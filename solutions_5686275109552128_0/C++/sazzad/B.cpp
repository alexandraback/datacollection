
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

const int MAXN = 1005;
int n, plates[MAXN];

bool bs(int limit) {
    priority_queue<Pii> pq;
    for(int i=0;i<n;i++) {
        pq.push(make_pair(plates[i], 1));
    }

    int split=0, value, count;
    while(!pq.empty()) {
        if(split>limit) return false;

        value = pq.top().first;
        if(split+value<=limit) return true;

        count = 0;
        while(!pq.empty() && pq.top().first==value) {
            count += pq.top().second;
            pq.pop();
        }

        if(value&1) {
            pq.push(make_pair(value/2, count));
            pq.push(make_pair((value+1)/2, count));
        }
        else {
            pq.push(make_pair(value/2, count*2));
        }
        split += count;
    }
    if(pq.empty()) exit(-1);
    //cerr<<split<<" "<<pq.top().first<<" "<<pq.top().second<<"\n";
    return split+pq.top().first<=limit;
}

int main()
{
//	freopen("in.txt","r",stdin);
	freopen("B-small-attempt4.in","r",stdin);
	freopen("out.txt","w",stdout);

	int cases, caseno, maxval, ans;
	int lo, hi, mid;

	scanf("%d", &cases);
	for(caseno=1;caseno<=cases;caseno++) {
        scanf(" %d", &n);
        maxval=0;
        for(int i=0;i<n;i++) {
            scanf(" %d", &plates[i]);
            maxval = max(maxval, plates[i]);
        }

//        if(maxval<4) ans=maxval;
//        else {
            lo = 1;
            ans = hi = maxval;
            while(lo<=hi) {
                mid = (lo+hi)/2;
                if(bs(mid)) {
                    hi=mid-1;
                    ans=mid;
                }
                else lo=mid+1;
            }
//        }
        printf("Case #%d: %d\n", caseno, ans);
	}

	return 0;
}
