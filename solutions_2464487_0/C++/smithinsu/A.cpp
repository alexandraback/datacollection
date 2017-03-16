#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
#include<climits>
#include<cstring>
using namespace std;

#define CLR(a,x) memset(a,x,sizeof(a))
#define PB push_back
#define INF 1000000000
#define MOD 1000000007
#define MP make_pair
#define tr(container , it) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define LL long long
#define VI vector < int >
#define PII pair < int , int >


void precompute(void)
{
}
LL total,r,low,high,mid,ans;
LL f(LL n)
{
	LL ret;
	ret=2*( n*r + n*n - 1 ) - (n-1) +1;
//	printf("%lld %lld\n",n,ret);
	return ret;
}


int main()
{
	int t,test;
	precompute();
	while(scanf("%d",&t)!=EOF)
	{
		test=0;
		while(t--)
		{
			test++;
			printf("Case #%d: ",test);
			fprintf(stderr,"Case #%d: ",test);
		
			scanf("%lld%lld",&r,&total);
			low=1;
			high=min(1000000000LL,total/r + 1);
			ans=1;
			while(low<=high)
			{
				mid=(low+high)/2;
				if(f(mid)>total)
					high=mid-1;
				else
					low=mid+1,ans=mid;
			}
	//		fprintf(stderr,"%lld\n",ans);
			while(f(ans+1)<=total)
				ans++;
			printf("%lld\n",ans);
			fprintf(stderr,"%lld\n",ans);
		}
	}
	return 0;
}
