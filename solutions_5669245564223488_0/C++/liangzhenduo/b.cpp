#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define mod	1000000007
char c[120][120];
int b[120],next[120],bo[120],v[120];
int l[30],r[30],md[30],al[30];
long long f[130];
bool noans;
void check(char *c,int ii)
{
	int ll=strlen(c);
	//is al?
	bool flag=1;
	for(int i=0;i<ll;i++)
	{
		if(c[i]!=c[0])
		{
			flag=0;
			break;
		}
	}
	if(flag)
	{
		al[c[0]-'a']++;
		bo[ii]=1;
		return;
	}
	//l
	memset(b,0,sizeof(b));
	b[0]=1;
	for(int i=1;i<ll;i++)
	{
		if(c[i]==c[i-1])
		{
			b[i]=1;
		}
		else break;
	}
	//r
	b[ll-1]=2;
	for(int i=ll-2;i>=0;i--)
	{
		if(c[i]==c[i+1])
		{
			b[i]=2;
		}
		else break;
	}
	if(!l[c[0]-'a'])l[c[0]-'a']=ii;
	else noans=1;
	if(!r[c[ll-1]-'a'])r[c[ll-1]-'a']=ii;
	else noans=1;
	if(c[0]==c[ll-1])noans=1;
	for(int i=1;i<ll;i++)
	{
		if(c[i]!=c[i-1]&&!b[i])
		{
			md[c[i]-'a']++;
			if(l[c[i]-'a']||r[c[i]-'a']||al[c[i]-'a']||md[c[i]-'a']>1)noans=1;
		}
	}
}
bool dfs(int x)
{
	v[x]=1;
	if(!next[x])return 1;
	if(v[next[x]])return 0;
	return dfs(next[x]);
}
int main()
{
	f[0]=1;
	for(int i=1;i<=110;i++)
	{
		f[i]=f[i-1]*i;
		f[i]%=mod;
	}
	int T;
	scanf("%d",&T);
	for(int tcase=1;tcase<=T;tcase++)
	{
		int n;
		noans=0;
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		memset(md,0,sizeof(md));
		memset(al,0,sizeof(al));
		memset(bo,0,sizeof(bo));
		memset(next,0,sizeof(next));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",c[i]);
			check(c[i],i);
		}
		if(noans)
		{
			printf("Case #%d: 0\n",tcase);
			continue;
		}
		long long ans=1;
		int cnt=0;
		for(int i=0;i<26;i++)
		{
			ans*=f[al[i]];
			ans%=mod;
			if(l[i]&&r[i])
			{
				next[r[i]]=l[i];
				bo[l[i]]=1;
			}
			if(l[i]==0&&r[i]==0&&al[i]>0)cnt++;
		}
		for(int i=1;i<=n;i++)
		{
			memset(v,0,sizeof(v));
			if(!dfs(i))
			{
				noans=1;
				break;
			}
		}
		if(noans)
		{
			printf("Case #%d: 0\n",tcase);
			continue;
		}
		for(int i=1;i<=n;i++)
			if(!bo[i])cnt++;
		ans*=f[cnt];
		ans%=mod;
		ans+=mod;
		ans%=mod;
		printf("Case #%d: %I64d\n",tcase,ans);
	}
}
