/*

jsrkrmciB

*/

#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define clear(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define Fora(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define fora(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define output(x) cout << (x)
#define ST first
#define ND second
#define br printf("\n")
#define getnum(x) scanf("%d", &x);
#define GCJ(x,y)  printf("Case #%d: %d\n", x+1, y);
#define getline(x) 	scanf("\n%[^\n]",x);

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
template <class _T> inline istream& operator << (istream& is, const _T& a) { is.putback(a); return is; }

typedef long double ld;
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < ld > VD;
typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < string > VS;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

const ld PI  = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

#define DEBUG

#ifdef DEBUG
#define debug(x) cout << #x << ":" << x << "\n";
#define dprintf(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
#else
#define debug //
#define dprintf(fmt,...)
#endif

// Global Variable
i64 final,ans=0;
int N,M,qq;
i64 a[2][200];
i64 b[2][200];


i64 min(i64* x, i64* y){
	if(x>y){return *y;}else{return *x;}
}

i64 max(i64* x, i64* y){
	if(x>y){return *x;}else{return *y;}
}
void test(int ps, int pj,i64 last,i64 lastf,i64 lastn){

	if(ps>=N || pj>=M){final=max(final,ans);}
	else{

		i64 buf=ans;
			i64 lastbuf=last;
			i64 lastnbuf=lastn;
			i64 lastfbuf=lastf;
			i64 temp1=b[0][pj];
			i64 temp2=a[0][ps];
		if(a[1][ps]==b[1][pj]){

			if(a[1][ps]==last){
				if(lastf==1){
					b[0][pj]+=lastn;
				}
				if(lastf==0){
					a[0][ps]+=lastn;
				}
			}
			ans+=min(a[0][ps],b[0][pj]);
			last=a[1][ps];
			lastn=max(a[0][ps],b[0][pj])-min(a[0][ps],b[0][pj]);
			if(a[0][ps]>b[0][pj]){lastf=0;}else{lastf=1;}
		//	debug(a[1][ps]);
			i64 buf2=ans;
			i64 lastbuf2=last;
			i64 lastnbuf2=lastn;
			i64 lastfbuf2=lastf;

			test(ps+1,pj,last,lastf,lastn);
			ans=buf2;
			last=lastbuf2;
			lastn=lastnbuf2;
			lastf=lastfbuf2;
			test(ps+1,pj+1,last,lastf,lastn);

			b[0][pj]=temp1;
			a[0][ps]=temp2;
			ans=buf;
			last=lastbuf;
			lastn=lastnbuf;
			lastf=lastfbuf;

		}

		test(ps,pj+1,last,lastf,lastn);
		ans=buf;
		last=lastbuf;
		lastn=lastnbuf;
		lastf=lastfbuf;
		test(ps+1,pj,last,lastf,lastn);

	}

}




int main() {
	freopen("input.txt", "rt", stdin); 
	cout << setiosflags(ios::fixed) << setprecision(15);
	getnum(qq);
	fora (i,qq){
		clear(a);
		clear(b);
		i64 t1,t2;
		getnum(N);
		getnum(M);
		fora(j,N){
			scanf("%lli", &t1);
			scanf("%lli", &t2);
			a[0][j]=t1;
			a[1][j]=t2;
		}
		fora(j,M){
			scanf("%lli", &t1);
			scanf("%lli", &t2);
			b[0][j]=t1;
			b[1][j]=t2;
		}
		ans=0;
		final=0;
		test(0,0,-1,-1,-1);


		printf("Case #%d: ", i+1);
		cout << final << "\n" ;
	}



	return 0;
}