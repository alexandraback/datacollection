#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

typedef long long ll;
#define INF (1<<29)

vector<int> G[1100];
int visit[1100];
bool flag;

void dfs(int x){
	int i;
	if(visit[x]==0){
		visit[x]=1;
		REP(i,G[x].size()){
			dfs(G[x][i]);
		}
	}
	else{
		flag=true;
		visit[x]=2;
	}
}

int main(){
	int t, tc, i, j, k;
	cin >> t;
	REP(tc,t){
		flag=false;
		int n, m, tmp;
		cin >> n;
		REP(j,n){
			visit[j]=0;
			G[j].clear();
		}
		REP(i,n){
			cin >> m;
			REP(j,m){
				cin >> tmp;
				G[i].push_back(tmp-1);
			}
		}
		REP(j,n){
			visit[j]=j+1;
			REP(k,G[j].size()){
				dfs(G[j][k]);
			}
			
			REP(k,n){
			//	cout << visit[k] << " ";
				visit[k]=0;
			}
			if(flag)break;
			//puts("");
		}
		printf("Case #%d: ",tc+1);
		if(flag)puts("Yes");
		else puts("No");
	}
	return 0;
}

