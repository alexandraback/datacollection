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

const int MAXN = 50;

int N,K;
int key[MAXN];
int T[MAXN];
int dn[num(21)];
vector<int> res;
vector<int> ar[MAXN];

int f(int t){
	
	int &rev=dn[t];
	
	if(rev!=-1)	return rev;
	
	rev=0;
	
	if(t==(num(N)-1))
		return 1;
	
	int tmp;
	
	forn(i,0,N-1)
		if( (t&num(i))==0 && key[T[i]] )
		{
			key[T[i]]--;
			foreach(it,ar[i])
				key[*it]++;
			tmp=f( t|num(i) );
			if(tmp)
			{
				res.pb(i);
				return tmp;
			}
			foreach(it,ar[i])
				key[*it]--;
			key[T[i]]++;
		}
	
	return 0;
	
}

int main(){
	
	int test,a;
	
	scanf(" %d",&test);
	
	forn(Case,1,test){
		
		printf("Case #%d: ",Case);
		
		SET(key,0);
		SET(T,0);
		SET(dn,-1);
		
		scanf(" %d %d",&K,&N);
		
		forn(i,0,N-1)
			ar[i].clear();
		
		forn(i,1,K)
		{
			scanf(" %d",&a);
			key[a]++;
		}
		
		int sz;
		
		forn(i,0,N-1)
		{
			scanf(" %d %d",T+i,&sz);
			
			forn(j,1,sz)
			{
				scanf(" %d",&a);
				ar[i].pb(a);
			}
				
		}
		
		res.clear();
		
		f(0);
		
		if( SIZE(res)==0 )
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		foreachr(it,res)
			printf("%d ",*it+1);
		puts("");
		
	}
	
	return 0;
	
}
