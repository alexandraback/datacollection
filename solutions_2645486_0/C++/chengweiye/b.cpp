#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define For(i,n) for (i=0; i<int(n); i++)
#define ForR(i,n) for (i=int(n)-1; i>=0; i--)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x < 0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }

const int INF = (int)1e9;
const LD EPS = 1e-9;
const LD PI = acos(-1.0);

#define DEBUG 0

const int LIMN=10000;
LL input[LIMN];
int big[LIMN];
int main()
{
	//files
	freopen("in.in","r",stdin);
		if (!DEBUG)
			freopen("out.txt","w",stdout);
	//vars
	int tt,TT;
	//testcase loop
	LL E,R;
	
	int N;
	scanf("%d",&TT);
		For(tt,TT)
		{
			//init
			printf("Case #%d: ",tt+1);
			//input
			scanf("%lld%lld%d",&E,&R,&N);
			int i;
			For(i,N)
			{
				scanf("%lld",&input[i]);
			}
			For(i,N)
			{
				big[i]=-1;
				for(int j=i+1;j<N;j++)
				{
					if(input[j]>input[i])
					{
						big[i]=j;
						break;
					}
				}
			}
			LL ans=0;
			LL cur=E;
			For(i,N)
			{
				if(big[i]==-1)
				{
					ans+=cur*input[i];
					cur=R;
					if(cur>E) cur=E;
				}else
				{
					LL diff=big[i]-i;
					LL left=E-diff*R;
					if(left<0) left=0;
					if(left<cur)
					{
						ans+=(cur-left)*input[i];
						cur=left+R;
						if(cur>E) cur=E;
					}else{
						cur=cur+R;
						if(cur>E) cur=E;
					}
				}
			}
			printf("%lld\n",ans);
			
		}
	return(0);
}