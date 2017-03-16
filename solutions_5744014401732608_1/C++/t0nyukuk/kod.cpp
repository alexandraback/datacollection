#pragma comment(linker,"/STACK:10000000")

//TC

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
#include <set>
#include <map>

#define forn(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
#define forr(a,b,c) for(int (a)=(b);(a)>=(c);(a)--)
#define foreach(a,b) for( typeof( (b).begin() ) a=(b).begin(); (a)!=(b).end() ; (a)++ )
#define foreachr(a,b) for( typeof( (b).rbegin() ) a=(b).rbegin(); (a)!=(b).rend() ; (a)++ )
#define dg(x)  cerr <<#x<<':'<<x<<" "
#define dbg(x)  cerr <<#x<<':'<<x<<endl
#define SET(A,b) memset(A,b,sizeof (A) )
#define SIZE(A) ((int)(A).size())
#define ALL(A) (A).begin(),(A).end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define num(a) (1LL<<(a))
using namespace std;

typedef double dbl;
typedef long long Lint;
typedef pair<int,int> ii;
typedef pair<Lint,Lint> Lii;

const Lint mod = 1e9;

const int MAXN = 110;

int res[MAXN][MAXN];

int main(){

	Lint N,B,M;

	scanf(" %lld",&N);

	forn(task,1,N){
		printf("Case #%d: ",task);
		scanf("%lld %lld",&B,&M);
		
		stack< Lii > st;
		SET(res,0);

		st.push( Lii(1,1) );

		forn(i,2,B-1){
			//printf("%lld %lld\n",i,(1LL<<(i-2)));
			st.push( Lii( i,1LL<<(i-2) ) );
			forn( j,1,i-1 )
				res[j][i]=1;
		}

		while( !st.empty() ){
			Lii tmp = st.top();
			st.pop();
			//printf("at %Ld -> %Ld %Ld\n",M,tmp.fi,tmp.se);
			if( M >= tmp.se ){
				M-=tmp.se;
				res[ tmp.fi ][ B ]=1;
			}
			//printf("end %Ld -> %Ld %Ld\n",M,tmp.fi,tmp.se);
			//puts("");

		}

		if( M ){
			cout << "IMPOSSIBLE" << endl;
		}
		else{
			cout << "POSSIBLE" << endl;
			forn(i,1,B)
			{
				forn(j,1,B){
					printf("%d",res[i][j]);
				}
				cout << endl;
			}
		}

	}

	return 0;

}

