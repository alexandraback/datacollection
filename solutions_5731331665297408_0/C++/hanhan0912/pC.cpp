#include <bits/stdc++.h>

using namespace std;

int N,M;
int per[10];
int tarPos;
string S[10];
vector<int> E[10];
int suffix[10][10];

string get_answer(){
	string res="";
	for (int i=0; i<N; i++){
		res = res + S[per[i]];
	}
	return res;
}
void DFS(int u){
	for (int i=0; i<(int)E[u].size() && tarPos < N; i++){
		int v= E[u][i];
		if (v == per[tarPos]){
			tarPos++;
			DFS(v);
			i = -1;
		}
	}
}
void input(){
	cin >> N >> M;
	for (int i=0; i<N; i++){
		E[i].clear();
		cin >> S[i];
	}
	for (int i=0; i<M; i++){
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		E[u].push_back(v);
		E[v].push_back(u);
	}
}
void solve(int nT){
	for (int i=0; i<N; i++){
		per[i] = i;
	}
	string ans = "";
	do{
		//memset(suffix,0,sizeof(suffix));
		//pre_process();
		tarPos = 1;
		DFS(per[0]);
		if (tarPos >= N){
			string str = get_answer();
			if ((int)ans.size() == 0 || str < ans){
				ans = str;
			}
		}
	}while(next_permutation(per,per+N));
	cout << "Case #" << nT << ": " << ans << endl;
}

int main(){
	int nT;
	cin >> nT;
	for (int i=1; i<=nT; i++){
		input();
		solve(i);
	}
}