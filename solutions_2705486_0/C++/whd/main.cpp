
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long big;
int n,X,Y;
char str[5020];
string tmp;
vector<string>dic[200];
int f[5020];
int get(const string &a,const string &b)
{
	int i,s=0;
	for(i=0;i<a.size();i++)
		if(abs(a[i]-b[i]))
		{
			if(abs(a[i]-b[i])>=5)s++;
			else s=0x3f3f3f3f;
		}
	return s;
}
int main()
{
	int now,cas,cass,i,j,s,k=0,w;
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	FILE *in=fopen("dic.txt","r");
	while(~fscanf(in,"%s",str))
		tmp=str,dic[tmp.size()].pb(tmp);
	scanf("%d",&cas);
	for(cass=1;cass<=cas;cass++)
	{
		printf("Case #%d: ",cass);
		scanf("%s",str+1);
		memset(f,0x3f3f3f3f,sizeof(f));
		f[0]=0;
		n=strlen(str+1);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=i;j++)
			{
				tmp="";
				for(k=i-j+1;k<=i;k++)
					tmp+=str[k];
				w=0x3f3f3f3f;
				for(k=0;k<dic[tmp.size()].size();k++)
					w=min(w,get(tmp,dic[tmp.size()][k]));
				f[i]=min(f[i-j]+w,f[i]);
			}
		}
		printf("%d\n",f[n]);
	}
	fclose(in);
}
