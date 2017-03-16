#define _USE_MATH_DEFINES
#define INF 100000000
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits>
#include <map>
#include <string>
#include <cstring>
#include <set>
#include <deque>
#include <bitset>
#include <list>

using namespace std;

typedef long long ll;
typedef pair <int,int> P;

static const double EPS = 1e-8;

int tx[] = {1,0};
int ty[] = {0,1};

int path[1000][1000];
int visited[1000];

void dfs(int s,int src,int N){

	for(int dst=0;dst<N;dst++){
		if(s != dst && path[src][dst] == 1 && visited[dst] <= 1){
			visited[dst]++;
			dfs(s,dst,N);
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++){
		memset(path,0,sizeof(path));
		int N;
		scanf("%d",&N);
		for(int from=0;from<N;from++){
			int M;
			scanf("%d",&M);
			for(int i=0;i<M;i++){
				int to;
				scanf("%d",&to);
				path[to-1][from] = 1;
			}
		}


		bool isok = false;
		for(int s=0;s<N;s++){
			memset(visited,0,sizeof(visited));
			visited[s] = 1;
			dfs(s,s,N);

			for(int i=0;i<N;i++){
				if(visited[i] >= 2){
					isok = true;
				}
			}
		}

		if(isok) printf("Case #%d: Yes\n",t+1);
		else printf("Case #%d: No\n",t+1);

	}
}