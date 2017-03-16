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
#define getline(x)  scanf("\n%[^\n]",x);

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
int qq;

typedef struct{
	int d,n,w,e,s,d_d,d_p,d_s;

}Wave;

bool wavesort(Wave const& a, Wave const& b){
	return a.d<b.d;
}

int main() {
  freopen("input.in", "rt", stdin); 
  freopen("output.out", "wt", stdout); 
  getnum(qq);
  fora(T,qq){
    int answer=0,N;
    int wall[100000];
    int newwall[100000];
    memset(newwall,0,sizeof(newwall));
    getnum(N);
    Wave *wave = new Wave[N];
    fora(i,N){
    	scanf("%d %d %d %d %d %d %d %d",&wave[i].d,&wave[i].n,&wave[i].w,&wave[i].e,&wave[i].s,&wave[i].d_d,&wave[i].d_p,&wave[i].d_s);
    }
    int lastdate;
    sort(wave,wave+N,wavesort);
    while(wave[0].d<99999999){
    	for(int i=0;i<100000;i++)
    		wall[i]=newwall[i];
    	lastdate=wave[0].d;
    	while(wave[0].d==lastdate){
    		int i=0;
    		if(wave[i].n==0)
    			break;
    		// printf("%d %d %d %d %d %d %d %d\n",wave[i].d,wave[i].n,wave[i].w,wave[i].e,wave[i].s,wave[i].d_d,wave[i].d_p,wave[i].d_s);
    		bool flag=false;
    		for(int j=wave[i].w*2;j<=wave[i].e*2;j++){
    			if (wall[j+10000]<wave[i].s){
    				flag=true;
    				break;
    			}
    		}
    		if(flag){
    			// cout << wave[i].d<< wave[i].w<< wave[i].e << wave[i].s<<endl;
    			answer++;
    			for(int j=wave[i].w*2;j<=wave[i].e*2;j++){
	    			if(newwall[j+10000]<wave[i].s){
	    				newwall[j+10000]=wave[i].s;
	    			}
	    		}
    		}
    		wave[i].d+=wave[i].d_d;
    		wave[i].e+=wave[i].d_p;
    		wave[i].w+=wave[i].d_p;
    		wave[i].s+=wave[i].d_s;
    		wave[i].n--;
    		if(wave[i].n==0){
    			wave[i].d=99999999;
    		}
    		sort(wave,wave+N,wavesort);
    	}
    }

    GCJ(T,answer);
  }
  return 0;
}