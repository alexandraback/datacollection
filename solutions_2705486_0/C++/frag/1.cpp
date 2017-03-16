#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define maxn 52
using namespace std;
vector<string > in[maxn];
char l[maxn];
int f[maxn];
int n,m,ans;
inline int Df(string l1,string l2,int re)
{
	int cnt=0;
	for(int i=0;i<l1.length()&&cnt<re;i++)
		if(l1[i]!=l2[i])
			cnt++;
	return cnt;
}
void Doit()
{
	int n=strlen(l)-1;
	memset(f,0x7f,sizeof(f));
	f[0]=0;
	for(int i=0;i<=n;i++)
	{
		string lt="";
		for(int j=i;j>=0;j--)
		{
			lt=l[j]+lt;
			if(f[j]>=11000000)
				continue;
			int re=6;
			for(int k=0;k<in[i-j+1].size();k++)
			{
				re=min(re,Df(lt,in[i-j+1][k],re));
				if(re<6)
					f[i+1]=min(f[i+1],f[j]+re);
			}
		}
	}
	printf("%d\n",f[n+1]);
}
int main()
{
	freopen("2.in","r",stdin);
	freopen("1.out","w",stdout);
	string lt;
	int t;
	for(int i=1;i<=521196;i++)
	{
		cin>>lt;
		in[lt.length()].push_back(lt);
	}
	freopen("1.in","r",stdin);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		cerr<<i<<endl;
		scanf("%s",l);
		printf("Case #%d: ",i);
		Doit();
	}
	return 0;
}
