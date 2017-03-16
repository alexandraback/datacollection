/*-------------icalFikr's template v2.1--------------*/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <algorithm>
#include <iomanip>
#include <cstddef>
#include <cassert>
#include <cctype>
#include <utility>
#include <ctime>

#ifndef GEDEBUG
	#define DEBUG printf(__VA_ARGS__)
	#define DEBUGS puts("gukguk")
	#define TIME() printf("\nFinished in %.3lf s\n",clock()/(double)CLOCKS_PER_SEC)
#else
	#define DEBUG
	#define DEBUGS
	#define TIME()
#endif

#ifdef __WIN32__
	char getchar_unlocked() { return getchar(); }
#endif

/* Abbreviations */
#define puf push_front
#define pof pop_front()
#define pub push_back
#define pob pop_back()
#define fs first
#define sc second
#define mp make_pair
#define FOR(i,a,b) for(int i=int(a),_b=int(b);i<=_b;i++)
#define FORLL(i,a,b) for(LL i=LL(a),_b=LL(b);i<=_b;i++)
#define FORD(i,a,b) for(int i=int(a),_b=int(b);i>=_b;i--)
#define FOREACH(i,a) for (__typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define OPEN freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define CLOSE fclose(stdin); fclose(stdout);
#define ALL(v) (v).begin(),(v).end()
#define sz size()
#define reset(x,N) memset(x,N,sizeof(x))
#define nl puts("")
#define gc getchar_unlocked()

using namespace std;
typedef double db;
typedef long long LL;
typedef pair <int,int> ii;
typedef pair <LL,LL> pll;
typedef vector <ii> vii;
typedef vector <int> vint;

const db EPS	= 0.0000001;		
const db PI 	= acos(-1);			
const LL INFLL	= 0x7FFFFFFFFFFFFFFF;
const int INF	= 0x7FFFFFFF;

template<typename T>
inline void next(T &num) {
    char c; num=0;	
    do { c=gc; } 
    while (c!=EOF && c==' ' && c=='\n' && c=='\t');
    int sign=(c=='-' ? -1 : 1);
    if (c!='-') num+=(c-'0');
    while ( (c=gc)!=EOF && c!='\n' && c!='\t' && c!=' ') {
        num*=10; num+=(c-'0');
    }
    num*=sign;
}

inline string getstr() {
    string str; char k;
    while( (k=gc)==' ' || k=='\n' )
    {
        k=gc;
        if ( k==' ' || k=='\n' ) continue;
        else break;
    }
    while((k=gc)!=EOF &&k!='\n' && k!='\t'
        && k!='\v' && k!='\0' && k!=' ')
        str.pub(k);
    return str;
}

/*-------------end of template-------------*/
int tc,dua[45];
LL a,b,g,p;

LL gcd(LL a,LL b) { return (!a ? b : gcd(b%a,a)); }
LL power2(LL a) {
	if (a==0) return 1000;
	else if (a%2) return (a>1 ? 1000 : 0);
	else return min(1000LL,power2(a>>1)+1);
}

int main() {
	scanf("%d",&tc);
	FOR(cs,1,tc) {
		printf("Case #%d: ",cs);
		scanf("%lld/%lld",&a,&b);
		g=gcd(a,b);
		a/=g; b/=g;
		p=power2(b);
		if (p<1000) {
			reset(dua,0);
			int i=0;
			while (a) {
				dua[p-i]=a%2;
				a=a>>1;
				i++;
			}
			int res=-1;
			FOR(i,0,p) {
				if (dua[i] && res<0) res=i;
			}
			if (res<1) puts("Impossible");
			else printf("%d\n",res);
		} else {
			puts("Impossible");
		}
	}
	return 0;
}