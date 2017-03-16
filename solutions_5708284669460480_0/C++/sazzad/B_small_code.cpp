
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <limits>
#include <utility>
#include <numeric>
#include <iterator>
#include <algorithm>
using namespace std;

const int INF=(1<<30)-1;
const long long LINF=(1ll<<62)-1;
const int DIRX[]={-1,0,0,1,-1,-1,1,1}, DIRY[]={0,-1,1,0,-1,1,-1,1};
const double ERR=1e-11, PI=(2*acos(0.0));

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
template<class T> inline T MIN(T a,T b) {return ((a<b)?(a):(b));}
template<class T> inline T MAX(T a,T b) {return ((b<a)?(a):(b));}
template<class T> inline T ABS(T a) {return ((a<0)?(-a):(a));}
template<class T> inline void checkMIN(T& a,T b) {if(b<a) a=b;}
template<class T> inline void checkMAX(T& a,T b) {if(a<b) a=b;}
template<class T> inline T SQR(T x) {return (x*x);}
template<class T> inline T GCD(T a,T b) {T c; while((c=a%b)!=0)a=b,b=c; return b;}
template<class T> inline T fastPow(T Base,T Power) {T Result=1; while(Power>0){if(Power&1)Result*=Base; Power>>=1; Base*=Base;} return Result;}
template<class T> inline T fastModPow(T Base,T Power,T Mod) {T Result=1;while(Power>0){if(Power&1)Result=(Result*Base)%Mod; Power>>=1; Base=(Base*Base)%Mod;} return (Result%Mod);}
inline int compDouble(double x,double y) {double d=x-y; if(d-ERR>0.0) return 1; else if(d+ERR<0.0) return -1; else return 0;}

#define ALL(X)       (X).begin(),(X).end()
#define SIZE(X)      ((int)(X).size())
#define MEM(X,with)  memset((X),(with),sizeof(X))
#define EACH(X,itr)  for( __typeof((X).begin()) itr=(X).begin(); itr!=(X).end(); itr++)
#define Contains(X,item)    ((X).find(item)!=(X).end())
#define Contains_n(X,item)	(find((X).begin(),(X).end(),(item))!=(X).end())

typedef unsigned long long ULL;
typedef long long      LL;
typedef stringstream   SS;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<LL>     VL;
typedef vector<int>    VI;
typedef pair<int,int>  Pii;

#define sz 109
int k, l, s;
char ks[sz], ls[sz], ss[sz];

LL summ, maxx, inst;

void bt(int si) {
    if(si==s) {
        inst++;
        int cnt=0;
        for(int i=0;i+l<=s;i++) {
            bool flag = true;
            for(int j=0;j<l;j++) {
                if(ss[i+j]!=ls[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                cnt++;
            }
        }
        maxx = max(maxx, cnt);
        summ += cnt;
        return;
    }
    for(int i=0;i<k;i++) {
        ss[si]=ks[i];
        bt(si+1);
    }
}

int main()
{
//	freopen("in.txt","r",stdin);
	freopen("B-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);

	int cases, caseno;
	scanf("%d",&cases);
	for(caseno=1;caseno<=cases;caseno++) {

        scanf(" %d %d %d", &k, &l, &s);
        scanf(" %s %s", ks, ls);
        summ=maxx=inst=0;
        if(l<=s) {
            bt(0);
        }
        double ans=0.0;
        if(maxx>0) {
            ans = (double)(inst*maxx - summ) / inst;
        }
        printf("Case #%d: %.8lf\n", caseno, ans);
	}

	return 0;
}
