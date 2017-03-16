#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<queue>
#include<string>
#include<sstream>
#define eps 1e-9
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define MAXN 1005
#define MAXM 40005
#define INF 0x3fffffff
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define lc (k<<1)
#define rc ((k<<1)1)
using namespace std;
typedef long long LL;
LL i,j,k,n,m,x,y,T,big,cas,num,len,sz;
bool flag;
LL tmp,ans,tmp1,tmp2;
char s[20],a[20];
void scc()
{
	if (strcmp(s,"")==0)
	{
		tmp=0;
	}else
	sscanf(s,"%lld",&tmp);
}

bool ck()
{
	if (a[0]!='1') return false;
	for (i=1;i<len;i++)
	{
		if (a[i]!='0') return false;
	} 
	return true;
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%lld",&T);
	while (T--)
	{
		if (cas==61)
		{
			len=len;
		}
		scanf("%s",a);
		len=strlen(a);
		ans=1;
		for (i=1;i<len;i++)
		{
			if (i%2)
			{
				sz=(i+1)/2;
				for (j=0;j<sz;j++)
				{
					s[j]='9';
				}
				s[sz]=0;
				scc();
				ans+=tmp;
				s[sz-1]=0;
				scc();
				ans+=tmp;
				
				if (i!=1) ans++;
				
			}else
			{
				sz=(i+1)/2;
				for (j=0;j<sz;j++)
				{
					s[j]='9';
				}
				s[sz]=0;
				scc();
				ans+=tmp*2;
				if (i!=1) ans++;
			}
		}
		if (!ck())
		if (len%2==0)
		{
			sz=len/2;
			for (j=0;j<sz;j++)//前半部分 
			{
				s[j]=a[sz-j-1];
			}
			s[sz]=0;
			if (strcmp(s,"")==0)
			{
				tmp1=0;
			}else
			sscanf(s,"%lld",&tmp1);
			
			
			
			for (j=0;j<sz;j++)//后半部分 
			{
				s[j]=a[j+sz];
			}
			s[sz]=0;
			if (strcmp(s,"")==0)
			{
				tmp2=0;
			}else
			sscanf(s,"%lld",&tmp2);
			
			
			if (tmp2==0)
			{
				sscanf(a,"%lld",&tmp);
				tmp--;
				ans++;
				sprintf(a,"%lld",tmp);
				
				
			sz=len/2;
			for (j=0;j<sz;j++)//前半部分 
			{
				s[j]=a[sz-j-1];
			}
			s[sz]=0;
			if (strcmp(s,"")==0)
			{
				tmp1=0;
			}else
			sscanf(s,"%lld",&tmp1);
			
			
			
			for (j=0;j<sz;j++)//后半部分 
			{
				s[j]=a[j+sz];
			}
			s[sz]=0;
			if (strcmp(s,"")==0)
			{
				tmp2=0;
			}else
			sscanf(s,"%lld",&tmp2);
				
			}
			ans+=tmp1;
			ans+=tmp2;
			
			ans--;
			
			if (tmp1!=1 && len>1) ans++;
			
		}else
		{
			sz=len/2;
			for (j=0;j<sz;j++)
			{
				s[j]=a[sz-j-1];
			}
			s[sz]=0;
			if (strcmp(s,"")==0)
			{
				tmp1=0;
			}else
			sscanf(s,"%lld",&tmp1);
			for (j=0;j<=sz;j++)
			{
				s[j]=a[j+sz];
			}
			s[sz+1]=0;
			if (strcmp(s,"")==0)
			{
				tmp2=0;
			}else
			sscanf(s,"%lld",&tmp2);
			
			if (tmp2==0)
			{
				sscanf(a,"%lld",&tmp);
				tmp--;
				ans++;
				sprintf(a,"%lld",tmp);
				
				
			sz=len/2;
			for (j=0;j<sz;j++)
			{
				s[j]=a[sz-j-1];
			}
			s[sz]=0;
			if (strcmp(s,"")==0)
			{
				tmp1=0;
			}else
			sscanf(s,"%lld",&tmp1);
			for (j=0;j<=sz;j++)
			{
				s[j]=a[j+sz];
			}
			s[sz+1]=0;
			if (strcmp(s,"")==0)
			{
				tmp2=0;
			}else
			sscanf(s,"%lld",&tmp2);
			
				
			}
			ans+=tmp1;
			ans+=tmp2;
			ans--;
			if (tmp1!=1&&len>1) ans++;
		}
		
	
		printf("Case #%lld: %lld\n",++cas,ans);
	}
	return 0;
}
