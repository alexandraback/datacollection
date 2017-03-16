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

LL v[1<<15],E,R,n;
int mini[1<<15][15];
void precompute(void)
{
	int sz,i,j,log,N,ind1,ind2;
	log=0;
	while((1<<log)<n)
		log++;
	N=(1<<log);
	for(i=0;i<N;i++)
	{
		if(i>=n)
			v[i]=0;
		mini[i][0]=i;
	}
	for(i=1;i<=log;i++)
	{
		sz=(1<<(i-1));
		for(j=0;j<N;j++)
		{
			if(j+2*sz > N)
				continue;
			ind1=mini[j][i-1];
			ind2=mini[j+sz][i-1];
			if(v[ind1]<v[ind2])
				mini[j][i]=ind2;
			else
				mini[j][i]=ind1;
		}
	}
}
int logfloor(int x)
{
	int ret=0;
	while(x>(1<<ret))
		ret++;
	return ret-1;
}

LL get(int p,int q,LL have,LL need)
{
	if(p>q)
		return 0;
	if(p==q)
	{
		LL can=have-need;
		return v[p]*can;
	}
	else
	{
		int log,ind1,ind2,ind;
		log=logfloor(q-p+1);
		ind1=mini[p][log];
		ind2=mini[q-(1<<log)+1][log];
		if(v[ind1]<v[ind2])
			ind=ind2;
		else
			ind=ind1;
		LL can = min(E , have + R*(ind-p));
		LL lower = max( 0LL , need - (q-ind)*R);
		can = max(0LL , can - lower);
		LL willhave = lower+R;
		LL neednow = max( 0LL , min(E , have+R*(ind-p)) - R );
		return v[ind]*can + get(p,ind-1,have,neednow) + get(ind+1,q,willhave,need);
	}
}


int main()
{
	int t,test,i;
	while(scanf("%d",&t)!=EOF)
	{
		test=0;
		while(t--)
		{
			test++;
			printf("Case #%d: ",test);
			fprintf(stderr,"Case #%d: ",test);
			

			scanf("%lld%lld%lld",&E,&R,&n);
			for(i=0;i<n;i++)
				scanf("%lld",&v[i]);
			precompute();
			LL ans=get(0,n-1,E,0);
			printf("%lld\n",ans);
			fprintf(stderr,"%lld\n",ans);
		}
	}
	return 0;
}
