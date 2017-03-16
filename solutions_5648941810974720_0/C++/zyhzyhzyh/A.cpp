#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
using namespace std;
char s[2010];
int T,c[300],ues[20],vis[30];
string S[10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
double a[30][20];
template<class T>
void read(T&x)
{
	char ch=getchar();int mk=1;x=0;for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if (ch=='-') mk=-1,ch=getchar();for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-48;x*=mk;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&T);

	for(int _=1;_<=T;_++)
	{
		printf("Case #%d: ",_);
		scanf("%s",s);
		int l=strlen(s);
		memset(c,0,sizeof(c));
		for(int i=0;i<l;i++) c[s[i]-'A']++;
		memset(a,0,sizeof(a));
		for(int i=0;i<26;i++)
		{
			for(int j=0;j<10;j++)
				for(int k=0;k<(int)S[j].size();k++)
					a[i][j]+=(S[j][k]=='A'+i);
			a[i][10]=c[i];
		}
		memset(ues,-1,sizeof(ues));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<10;i++)
		{
			int l=-1;
			for(int j=0;j<26;j++)
				if (a[j][i]&&!vis[j])
				{
					l=j;ues[i]=j;vis[j]=1;break;
				}
			double k=a[l][i];
			for(int j=0;j<=10;j++) a[l][j]/=k;
			for(int k=0;k<26;k++)
				if (k!=l)
				{
					double X=a[k][i];
					for(int j=0;j<=10;j++) a[k][j]-=X*a[l][j];
				}
		}
		for(int i=0;i<10;i++) 
			if (ues[i]!=-1) 
				for(int j=1;j<=a[ues[i]][10]+0.1;j++) printf("%d",i);
		printf("\n");
	}
}
