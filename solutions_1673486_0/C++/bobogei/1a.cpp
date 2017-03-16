// --- BBG v2.1b ---
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<time.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<utility>
#include<map>
#include<set>
#include<string.h>
#include<string>
//
using namespace std;
//
//#define ONLINE_JUDGE BOBOGEI
#ifdef ONLINE_JUDGE
#define PP ;
#else
#define PP system("pause");
#endif
#define REP(n,i) for(int (i)=0;(i)<(n);(i)++)
#define CDREP(n,i) for(int (i)=((n)-1);(i)>=0;(i)--)
#define FOR(s,e,i) for(int (i)=(s);(i)<(e);(i)++)
#define _SZ(n) memset((n),0,sizeof(n))
#define _SMO(n) memset((n),-1,sizeof(n))
#define _MC(n,m) memcpy((n),(m),sizeof(n))
#define _F first
#define _S second
#define _MP(a,b) make_pair((a),(b))
#define _PB(a) push_back((a))
//
typedef unsigned int uint;
typedef long long i64;
typedef unsigned long long ui64;
typedef vector<int> vint;
typedef pair<int,int> pii;
const int INF = 1029384756;
const double PI = acos(-1);
const double EPS = 0.0000000304;
//
const int MAX = 123123;
//
int T;
int A,B;
double ip[MAX];
//
int main()
{
	freopen("cj/A.in","r",stdin);
	freopen("cj/A.out","w",stdout);
	scanf("%d",&T);
	REP(T,chiisanatenohira)
	{
		scanf("%d%d",&A,&B);
		double ans = (2.0+B),p=1.0;
		REP(A,i)
		{
			scanf("%lf",ip+i);
			p*=ip[i];
			ans=min(ans,p*(A+B-(i+1)*2+1)+(1-p)*(A+B-(i+1)*2+B+2));
		//	printf(",%lf",p*(A+B-(i+1)*2+1)+(1-p)*(A+B-(i+1)*2+B+2));
		}
		printf("Case #%d: %lf\n",chiisanatenohira+1,ans);
	}
}
