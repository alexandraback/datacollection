#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int J, P, S;
int K;

int N;

int adjMat[2+1000+100+100+100][2+1000+100+100+100];
vector<vector<int>> adjList;
vector<vector<int>> incList;

pii name[0+1000+100+100+100 + 1];

int pred[2+1000+100+100+100];
bool visited[2+1000+100+100+100];

#define INF (1<<28)

int main(){
	int cases;
	scanf("%d", &cases);

	for(int e = 0; e<cases; e++){
		scanf("%d %d %d %d", &J, &P, &S, &K);

		int numJPS = J*P*S;
		N = 0;

		int numJP = J*P;
		int numJS = J*S;
		int numPS = P*S;

		N = 2 + numJPS + numJP + numJS + numPS;

		adjList.assign(N, vector<int>());
		incList.assign(N, vector<int>());
		for(int i = 0; i<N; i++){
			for(int j = 0; j<N; j++){
				adjMat[i][j] = 0;
			}
		}

		int tr = 1;
		for(int j = 1; j<=J; j++){
			for(int p = 1; p<=P; p++){
				for(int s = 1; s<=S; s++){
					name[tr] = pii(j,pi(p,s));
					adjList[0].push_back(tr);
					incList[tr].push_back(0);
					adjMat[0][tr] = 1;

					int jp_node = numJPS + j*p;
					int js_node = numJPS + numJP + j*s;
					int ps_node = numJPS + numJP + numJS + p*s;

					adjList[tr].push_back(jp_node);
					incList[jp_node].push_back(tr);
					adjMat[tr][jp_node] = 1;

					adjList[tr].push_back(js_node);
					incList[js_node].push_back(tr);
					adjMat[tr][js_node] = 1;

					adjList[tr].push_back(ps_node);
					incList[ps_node].push_back(tr);
					adjMat[tr][ps_node] = 1;

					tr++;
				}
			}
		}

		for(int j = 1; j<=J; j++){
			for(int p = 1; p<=P; p++){
				int jp_node = numJPS + j*p;
				adjList[jp_node].push_back(N-1);
				incList[N-1].push_back(jp_node);
				adjMat[jp_node][N-1] = K;
			}
		}
		for(int j = 1; j<=J; j++){
			for(int s = 1; s<=S; s++){
				int js_node = numJPS + numJP + j*s;
				adjList[js_node].push_back(N-1);
				incList[N-1].push_back(js_node);
				adjMat[js_node][N-1] = K;
			}
		}
		for(int p = 1; p<=P; p++){
			for(int s = 1; s<=S; s++){
				int ps_node = numJPS + numJP + numJS + p*s;
				adjList[ps_node].push_back(N-1);
				incList[N-1].push_back(ps_node);
				adjMat[ps_node][N-1] = K;
			}	
		}

		while(1){
			bool found_path = false;

			for(int i = 0; i<N; i++){
				pred[i] = -1;
				visited[i] = false;
			}

			queue<pii> que;
			que.push(pii(INF, pi(0, -1)));

			int chosen_flow = -1;

			while(!que.empty()){
				pii p = que.front();
				que.pop();

				int flow = p.first;
				int node = p.second.first;
				int pre = p.second.second;

				if(visited[node]){
					continue;
				}
				visited[node] = true;
				pred[node] = pre;

				if(node == N-1){
					found_path = true;
					chosen_flow = flow;
					break;
				}

				for(auto adj : adjList[node]){
					if(node && node <= numJPS){

						int j = name[node].first;
						int p = name[node].second.first;
						int s = name[node].second.second;

						int jp_node = numJPS + j*p;
						int js_node = numJPS + numJP + j*s;
						int ps_node = numJPS + numJP + numJS + p*s;

						if(visited[adj]){
							continue;
						}
						if(!adjMat[node][adj]){
							continue;
						}

						if(adjMat[node][jp_node] && adjMat[node][js_node] && adjMat[node][ps_node] && adjMat[jp_node][N-1] && adjMat[js_node][N-1] && adjMat[ps_node][N-1]){
							que.push(pii(1, pi(adj, node)));
						} else {
							continue;
						}
					} else {

						if(visited[adj]){
							continue;
						}
						if(!adjMat[node][adj]){
							continue;
						}

						int next_flow = adjMat[node][adj];
						next_flow = min(next_flow, flow);

						que.push(pii(next_flow, pi(adj, node)));
					}


				}

			}

			if(found_path){

				int node = N-1;

				while(1){
					int pre = pred[node];

					if(pre && pre<=numJPS){

						pii jps = name[pre];
						int j = jps.first;
						int p = jps.second.first;
						int s = jps.second.second;

						int jp_node = numJPS + j*p;
						int js_node = numJPS + numJP  + j*s;
						int ps_node = numJPS + numJP + numJS + p*s;

						adjMat[pre][jp_node] -= 1;
						adjMat[jp_node][pre] += 1;
						adjMat[jp_node][N-1] -= 1;
						adjMat[N-1][jp_node] += 1;

						adjMat[pre][js_node] -= 1;
						adjMat[js_node][pre] += 1;
						adjMat[js_node][N-1] -= 1;
						adjMat[N-1][js_node] += 1;

						adjMat[pre][ps_node] -= 1;
						adjMat[ps_node][pre] += 1;
						adjMat[ps_node][N-1] -= 1;
						adjMat[N-1][ps_node] += 1;

						adjMat[0][pre] -=1;
						adjMat[pre][0] += 1;

						break;
					}

					node = pre;
				}

			} else {
				break;
			}

		}

		vector<pii> v;
		for(int i = 1; i<=numJPS; i++){
			if(!adjMat[0][i]){
				v.push_back(name[i]);
			}
		}

		printf("Case #%d: %d\n", e+1, v.size());
		for(auto p : v){
			printf("%d %d %d\n", p.first, p.second.first, p.second.second);
		}


	}

	return 0;
}