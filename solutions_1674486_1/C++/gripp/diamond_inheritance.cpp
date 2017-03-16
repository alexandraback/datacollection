#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>

#define pb(x) push_back(x)
#define sz() size()
#define f() first
#define s() second
#define b() begin()
#define e() end()

#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
#define fork(n) for(int k=0;k<n;k++)
#define forit(tipo,v) for(tipo::iterator it = (v).begin(); it != (v).end(); it++)

#define trace(x...) x
#define print(x...) trace(printf(x))
#define watch(x) trace(cout << #x" = " << x << "\n")

#define EPS 1e-10

using namespace std ;

int cmpD(double a, double b = 0)
{
	return (a <= b + EPS) ? (a + EPS < b) ? -1 : 0 : 1 ;
}


#define MAX_N 1010


int main(void)
{
	int t, N, cases = 1 ;

	scanf("%d", &t) ;
	while( t )
	{
		scanf("%d", &N) ;
		vector< vector<int> > grafo(N) ;
		fori(N)
		{
			int M, aux ;
			scanf("%d", &M) ;
			forj(M)
			{
				scanf("%d", &aux) ;
				grafo[i].pb(aux - 1) ;
			}
		}
		// busca
		fori(N)
		{
			vector< bool > block(N, false) ;
			queue< int > fila ;
			block[i] = true ;
			forit(vector<int>, grafo[i])
			{
				fila.push(*it) ;
			}
			while( !fila.empty() )
			{
				int atual = fila.front() ;
				fila.pop() ;
				if( block[atual] )
				{
					// sim
					printf("Case #%d: Yes\n", cases++) ;
					goto fim ;
				}
				block[atual] = true ;
				forit(vector<int>, grafo[atual])
				{
					fila.push(*it) ;
				}
			}
		}
		printf("Case #%d: No\n", cases++) ;
fim:
		t-- ;
	}


	return 0 ;
}



