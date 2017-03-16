#include<cstdio>
#include<algorithm>
#include<cstring>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=200;
char ch[N];
int s[N];
int n;
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int T,pp=0;
	scanf("%d",&T);
	while (T--)
	{
		pp++;
		scanf("%s",ch+1);
		n=strlen(ch+1);
		int top=0;
		s[0]=-1;
		fo(i,1,n)
		{
			int p=(ch[i]=='+');
			if (s[top]!=p) s[++top]=p;
		}
		int size=top;
		int ans;
		if (s[1]==0 && s[size]==0) ans=size; else
		if (s[1]==1 && s[size]==1) ans=size-1; else
		if (s[1]==0 && s[size]==1) ans=size-1; else
		if (s[1]==1 && s[size]==0) ans=size;
		printf("Case #%d: %d\n",pp,ans);
	}
}
