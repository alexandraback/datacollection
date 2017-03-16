// Author: Nishant R. Krishan
#include <iostream>
#include <sstream>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <deque>
#include <bitset>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <vector>
#include <queue>

using namespace std;

#define VI vector < int >
#define VVI(A,N,M) vector< VI > A( N, VI (M) )
#define LD long double
#define LL long long
#define LLU unsigned long long
#define SI ({int x;scanf("%d",&x);x;})
#define SC ({char x;scanf("%c",&x);x;})
#define SLL ({LL x;scanf("%lld",&x);x;})
#define SLLU ({LLU x;scanf("%llu",&x);x;})
#define PI acos(-1)
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define getSize(x) ((int) (x).size()) 
#define SORT(c) sort(all(c))
#define FIT(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define FITD(it,v) for (typeof(v.rbegin()) it = v.rbegin(); it != v.rend(); it++)
#define IATOV(a) ({vector<int> v(a,a+sizeof(a)/sizeof(int));v;})
#define CATOV(a) ({vector<char> v(a,a+sizeof(a)/sizeof(char));v;})
#define sieve(a) ({int b=ceil(sqrt(a));VI d(a,0);VI e;int f=2;e.pb(2);e.pb(3);for(int x=1;x<b+1;x++){for(int y=1;y<b+1;y++){int n=(4*x*x)+(y*y);if(n<=a&&(n%12==1||n%12==5)){d[n]^=1;}n=(3*x*x)+(y*y);if(n<=a&&n%12==7){d[n]^=1;}n=(3*x*x)-(y*y);if(x>y&&n<=a&&n%12==11){d[n]^=1;}}}for(int r=5;r<b+1;r++){if(d[r]){for(int i=r*r;i<a;i+=(r*r)){d[i]=0;}}}for(int c=5;c<a;c++){if(d[c]){e.pb(c);}}e;})
#define INF 1000000007
#define EPS 1e-9

/********************************************************************************************************************************/

int main(int argc, char** argv) {
	int T=SI;
	for(int t=1;t<=T;++t){
		cout<<"Case #"<<t<<":"<<endl;
		/************************/
		int R=SI, N=SI, M=SI, K=SI;
		int i,j,c,k,X;
		string Ans;
		for( i=0;i<R;++i ){
			vector<int> Primes(10, 0);
			for( j=0;j<K;++j ){
				X=SI;
				for( k=2;k<=X;++k ){
					c=0;
					while( X%k==0 ){
						X/=k;
						c++;
					}
					Primes[k] = max(Primes[k], c);
				}
			}
			Ans = "";
			for( j=2;j<=M;++j ){
				if( Primes[j]==0 )
					continue;
				c=1;
				while( Primes[j]>0 && (c*j)<=M ){
					c = c*j;
					Primes[j]--;
				}
				Ans += c+'0';
				if( Primes[j]>0 )
					j--;
			}
			if( getSize(Ans)<N ){
				for( j=getSize(Ans);j<N;++j )
					Ans += '2';
			}
			cout<<Ans<<endl;
		}
		/************************/
	}
	return 0;
}

