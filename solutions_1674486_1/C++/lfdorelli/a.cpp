#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <list>

using namespace std;

typedef long long int LL;
typedef pair<int,int> pii;

#define F first
#define S second
#define pb push_back
#define mp make_pair
int chega[1001];
vector<int> grafo[1001];
int P[1001];

int dfs(int x) {
	int s = grafo[x].size();
	P[x] ++;
	for(int i = 0; i < s; i++) 
		dfs(grafo[x][i]);
}

int main (void)
{
	int t;
	cin >> t;

	for(int T = 0; T < t; T++) {
		
		int n;
		cin >> n;
		
		memset(chega,0,sizeof chega);
		printf("Case #%d: ", T+1);

		for(int i = 0; i < n; i++) grafo[i].clear(); 
	
		int has  = 0;
		for(int j = 0; j < n; j++)
		{
			int v, x;
			cin >> v;
			for(int i = 0; i < v; i++) {
				cin >> x;
				grafo[j].pb(x-1);
				chega[x-1]++;
			}
		}



		for(int i = 0; i < n; i++) {
			if(chega[i] == 0) {
				memset(P, 0, sizeof P);
				dfs(i);
				for(int i = 0; i < n; i++) if(P[i] > 1) has = 1;
			}
		}

		if(has) printf("Yes\n");
		else printf("No\n");
		
		
	}
	return 0;
}
