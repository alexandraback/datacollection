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

vector < int > seq;
int n,k,need[256];
bool cando[1<<20][20];
int has[1024],ori[1024];
int contains[1024][1024],memo[1<<20];
int maxi=0,orifre[256];

void precompute(void)
{
	int fre[256],mask;
	for(int i=0;i<(1<<n);i++)
	{
		mask=i;
		for(int j=1;j<=maxi;j++)
			fre[j]=orifre[j];
		for(int j=0;j<n;j++)
		{
			if(mask&(1<<j))
			{
				fre[need[j]]--;
				for(int k=0;k<has[j];k++)
					fre[contains[j][k]]++;
			}
			if((mask>>j)==0)
				break;
		}
		for(int j=0;j<n;j++)
		{
			if(fre[need[j]])
				cando[i][j]=true;
			else
				cando[i][j]=false;
		}
	}
}

int rec(int mask)
{
	int &ret=memo[mask];
	if(ret==-1)
	{
		if(mask==((1<<n)-1))
			ret=1;
		else
		{
			int i;
			for(i=0;i<n;i++)
			{
				if(cando[mask][i]&&(!(mask&(1<<i))))
				{
					if(rec(mask|(1<<i)))
					{
						seq.PB(i);
						break;
					}
				}
			}
			if(i==n)
				ret=0;
			else
				ret=1;
		}
	}
	return ret;
}


int main()
{
	int t,kase,i,j;
	while(scanf("%d",&t)!=EOF)
	{
		seq.clear();
		kase=1;
		while(t--)
		{
			maxi=0;
			scanf("%d%d",&k,&n);
			memset(orifre,0,sizeof(orifre));
			for(i=0;i<k;i++)
			{
				scanf("%d",&ori[i]);
				maxi=max(ori[i],maxi);
				orifre[ori[i]]++;
			}
			
			for(i=0;i<n;i++)
			{
				scanf("%d%d",&need[i],&has[i]);
				for(j=0;j<has[i];j++)
				{
					scanf("%d",&contains[i][j]);
					maxi=max(contains[i][j],maxi);
				}
			}

			precompute();
			memset(memo,-1,sizeof(memo));
			if(rec(0))
			{
				printf("Case #%d:",kase);
				reverse(seq.begin(),seq.end());
				for(i=0;i<n;i++)
					printf(" %d",seq[i]+1);
				printf("\n");
			}
			else
			{
				printf("Case #%d: IMPOSSIBLE\n",kase);
			}
			kase++;
		}
	}
	return 0;
}
