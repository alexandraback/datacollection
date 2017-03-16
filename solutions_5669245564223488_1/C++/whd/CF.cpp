//#include <algorithm>

//#include <cstdio>

//#include <cmath>
#include <cstdio>
#include <cstring>
//#include <iostream>
#include <string>

//#include <iostream>

//#include <map>
//#include <utility>

//#include <vector>

using namespace std;

typedef long long int big;

const big MOD=1000000007;
const int N=10200;
int cas;
int inmid[N],n,m,all[N];
string a[N];
int begin[26],end[26];
char str[N];
big f[N][26];
bool used[N];
int nxt[300];
big fac[333];
int appear[26];
big sol()
{
	int i,j,k;
	char st,ed;
	memset(all,0,sizeof(all));
	memset(begin,0,sizeof(begin));
	memset(end,0,sizeof(end));
	memset(used,false,sizeof(used));
	memset(nxt,-1,sizeof(nxt));
	memset(appear,0,sizeof(appear));
	for(i=1;i<=n;i++)
	{
		st=a[i][0];
		for(j=0;j<a[i].size();j++)
			if(a[i][j]!=st)break;
		if(j==a[i].size())
			all[st-'a']++;
		else
		{
			if(!begin[st-'a'])
				begin[st-'a']=i;
			else return 0;
		}

		for(;j<a[i].size();j++)
			if(a[i][j]==st)
				break;
		if(j<a[i].size())return 0;

		ed=a[i][a[i].size()-1];
		for(j=a[i].size()-1;j>=0;j--)
			if(a[i][j]!=ed)break;
		k=j;
		for(;j>=0;j--)
			if(a[i][j]==ed)break;
		if(j>=0)return 0;
		if(k>=0)
		{
			if(!end[ed-'a'])end[ed-'a']=i;
			else return 0;
		}
		if(i==begin[st-'a']&&i==end[ed-'a'])
		{
			if(-1==nxt[st-'a'])nxt[st-'a']=ed-'a';
			else return 0;
		}

		for(j='a';j<='z';j++)
		{
			for(k=0;k<a[i].size();k++)
				if(a[i][k]==j)break;
			if(k<a[i].size()&&j!=a[i][0]&&j!=a[i][a[i].size()-1])
				appear[j-'a']++;
		}
	}
//	puts("!");
	for(i=0;i<26;i++)
	{
//		printf("%c\n",i+'a');
		if(appear[i]>=2)
			return 0;
		if(appear[i]&&(begin[i]||end[i]||all[i]))
			return 0;
	}
	big ans=1;
	big tmp;
	int cnt=0;
	for(i=0;i<26;i++)
	if(begin[i])
	{
		for(j=0;j<26;j++)
			if(nxt[j]==i)break;
		if(j==26&&!used[i])
		{
			tmp=1;
			for(k=i;k!=-1;k=nxt[k])
			{
				if(used[k])return 0;
				used[k]=true;
				tmp=tmp*fac[all[k]]%MOD;
			}
			ans=ans*tmp%MOD*(cnt+1)%MOD;
			cnt++;
		}
	}
	for(i=0;i<26;i++)
		if(!used[i]&&begin[i])
			return 0;
	for(i=0;i<26;i++)
		if(!begin[i]&&!end[i]&&all[i])
		{
			ans=ans*fac[all[i]]*(cnt+1)%MOD;
			cnt++;
		}
	return ans;
}
big pw(big x,big y)
{
	big ans=1;
	for(;y;y>>=1,x=x*x%MOD)
		if(y&1)ans=ans*x%MOD;
	return ans;
}
big inv(big x)
{
	return pw(x,MOD-2);
}
int main() {
	freopen("a.in", "r", stdin);
	freopen("a.txt", "w", stdout);
	int cass,i,j,k;
	fac[0]=1;
	for(i=1;i<=100;i++)
		fac[i]=fac[i-1]*i%MOD;
	scanf("%d",&cas);
	for(cass=1; cass<=cas;cass++) {
		printf("Case #%d: ",cass);
		scanf("%d",&n);
		m=0;
		for(i=1;i<=n;i++)
		{
			scanf("%s",str);
			a[i]=str;
			m+=a[i].size();
		}
		printf("%lld\n",sol());
	}
}
