#pragma comment(linker,  "/STACK:16777216")
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <locale>
#include <climits>

using namespace std;

typedef long long ll;
typedef unsigned long long Ull;

#define VI vector <int>
#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define RFOR(i, a, b) for(int (i) = (a)-1; (i) >= (b); --(i))
#define CLEAR(a) memset((a), 0, sizeof(a))
#define INF 1000000000
#define PB push_back
#define ALL(c) (c).begin(),  (c).end()
#define pi 2*acos(0.0)
#define SQR(a) (a)*(a)
#define MP make_pair
#define MOD 1000000007
#define EPS 1e-7
#define INF 2000000000


int T,TT,n,k,l,m,r,p,res,S;
vector<vector<int> > G(1010);
int U[1010];
bool b;

void DFS(int v)
{
	U[v] = 1;

	FOR(i,0,G[v].size())
	{
		if (b) break;
		if (U[G[v][i]])
		{
			b = 1;
			break;
		}
		DFS(G[v][i]);
	}
}

int main()
{
	freopen("inputA.txt","r",stdin);
	freopen("outputA.txt","w",stdout);

	cin >> TT;
	FOR(T,0,TT)
	{
		
		printf("Case #%d: ",T+1);

		cin >> n;

		FOR(i,0,n)
		{
			G[i].clear();
			cin >> m;
			FOR(j,0,m)
			{
				cin >> k;
				--k;
				G[i].PB(k);
			}
		}

		FOR(i,0,n)
		{
			b = 0;
			memset(U,0,sizeof(U));
			DFS(i);
			if (b)
			{
				printf("Yes\n");
				break;
			}
		}

		if (!b)
			printf("No\n");
	}
	return 0;
}