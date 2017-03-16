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

int dig1[64],dig2[64],dig3[64];
double chance[64][128];
void precompute(void)
{
	int i,d1,d2,d3,j,a[4],cur,k,temp;
	for(i=0;i<64;i++)
	{
		d1=(i&3)+2;
		d2=((i&12)>>2)+2;
		d3=((i&48)>>4)+2;
		dig1[i]=d1;dig2[i]=d2;dig3[i]=d3;
		a[0]=d1;
		a[1]=d2;
		a[2]=d3;
		for(j=0;j<=125;j++)
			chance[i][j]=0;
		for(j=0;j<8;j++)
		{
			temp=j;
			cur=1;
			for(k=0;k<3;k++)
			{
				if(temp&1)
					cur*=a[k];
				temp/=2;
			}
			chance[i][cur]+=0.125;
		}
	}
}

int main()
{
	int t,test,R,N,M,K,num[128];
	double curp,prob;
	int ans;
	precompute();
	while(scanf("%d",&t)!=EOF)
	{
		test=0;
		while(t--)
		{
			test++;
			printf("Case #%d:\n",test);
			fprintf(stderr,"Case #%d:\n",test);
		
			scanf("%d%d%d%d",&R,&N,&M,&K);
			
			for(int i=0;i<R;i++)
			{
				for(int j=0;j<K;j++)
					scanf("%d",&num[j]);
				ans=0;
				prob=0;
				for(int j=0;j<64;j++)
				{
					curp=1;
					if(j==22||j==23)
					{
						j++;
						j--;
					}
					for(int k=0;k<K;k++)
						curp*=chance[j][num[k]];
					if(curp>prob)
					{
						prob=curp;
						ans=j;
					}
				}
				printf("%d%d%d\n",dig1[ans],dig2[ans],dig3[ans]);
			}
		}
	}
	return 0;
}
