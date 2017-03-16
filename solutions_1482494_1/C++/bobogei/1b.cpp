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
const int MAX = 1234;
//
int T;
int N;
int ls[MAX];
pii ip1[MAX],ip2[MAX];
priority_queue<pii> pq;
int tp[MAX];
//
void aozora()
{
	_SZ(tp);
	while(pq.size())
	{
		pq.pop();
	}
}
//
int meteor()
{
	int t=0,ns=0;
	int id1=0,id2=0;
	while(ip1[id1]._F<=ns&&id1<N)
	{
		pq.push(_MP(ls[ip1[id1]._S],ip1[id1]._S));
		//printf("%d,%d\n",ip2[ip1[id1]._S]._F,ip1[id1]._S);
		id1++;
	}
	REP(N,i)
	{
		
		while(pq.size())
		{
			if(ns>=ip2[id2]._F)
			{
				break;
			}
			pii tt=pq.top();
			pq.pop();
			if(tp[tt._S]<1)
			{
				//printf("%d<",tt._S);
				tp[tt._S]=1;
				ns++;
				t++;
				while(ip1[id1]._F<=ns&&id1<N)
				{
					pq.push(_MP(ls[ip1[id1]._S],ip1[id1]._S));
					//printf("%d,%d\n",ip2[ip1[id1]._S]._F,ip1[id1]._S);
					id1++;
				}
			}
		}
		if(ns<ip2[id2]._F)
		{
			return INF;
		}else
		{
			ns+=2-tp[ip2[id2]._S];
			t++;
			tp[ip2[id2]._S]=2;
			id2++;
			while(ip1[id1]._F<=ns&&id1<N)
			{
				pq.push(_MP(ls[ip1[id1]._S],ip1[id1]._S));
				//printf("%d,%d\n",ip2[ip1[id1]._S]._F,ip1[id1]._S);
				id1++;
			}
		}
		
	}
	return t;
}
//
int main()
{
	freopen("cj/B.in","r",stdin);
	freopen("cj/B.out","w",stdout);
	scanf("%d",&T);
	REP(T,chiisanatenohira)
	{
		aozora();
		scanf("%d",&N);
		REP(N,i)
		{
			int v1,v2;
			scanf("%d%d",&v1,&v2);
			ls[i]=v2;
			ip1[i]=_MP(v1,i);
			ip2[i]=_MP(v2,i);
		}
		sort(ip1,ip1+N);
		sort(ip2,ip2+N);
		int ans=meteor();
		
		if(ans<INF)
		{
			printf("Case #%d: %d\n",chiisanatenohira+1,ans);
		}else
		{
			printf("Case #%d: Too Bad\n",chiisanatenohira+1);
		}
		
	}
}
