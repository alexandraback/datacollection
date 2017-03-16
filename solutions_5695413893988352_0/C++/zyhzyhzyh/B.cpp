#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
using namespace std;
int T,cnt1,cnt2,a[2000],b[2000],inf=1e9;
char s1[10],s2[10];
template<class T>
void read(T&x)
{
	char ch=getchar();int mk=1;x=0;for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if (ch=='-') mk=-1,ch=getchar();for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-48;x*=mk;
}
void dfs(int step,int dep,int now,int*a,int &cnt,char*s)
{
	if (step==dep)
	{
		a[++cnt]=now;return;
	}
	if (s[step]=='?')
	{
		for(int i=0;i<10;i++) dfs(step+1,dep,now*10+i,a,cnt,s);
	}
	else dfs(step+1,dep,now*10+s[step]-'0',a,cnt,s);
}
int abs(int x){if (x<0) return -x;return x;}
void Print(int len,int now)
{
	int a[10],l=len;memset(a,0,sizeof(a));
	while (now) {a[len--]=now%10;now/=10;}
	for(int i=1;i<=l;i++) printf("%d",a[i]);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for(int _=1;_<=T;_++)
	{
		printf("Case #%d: ",_);
		scanf("%s%s",s1,s2);
		int l1=strlen(s1),l2=strlen(s2);
		cnt1=cnt2=0;
		dfs(0,l1,0,a,cnt1,s1);
		dfs(0,l2,0,b,cnt2,s2);
		int Min=inf;
		PII ans;
		for(int i=1;i<=cnt1;i++)
			for(int j=1;j<=cnt2;j++)
				if (abs(a[i]-b[j])<Min) Min=abs(a[i]-b[j]),ans=MP(a[i],b[j]);
				else if (abs(a[i]-b[j])==Min) ans=min(ans,MP(a[i],b[j]));
		Print(l1,ans.fi);printf(" ");
		Print(l2,ans.se);printf("\n");
	}
}

