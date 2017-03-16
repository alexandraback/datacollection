#include<cstdio>
#include<algorithm>
#include<cstring>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=2000;
char ch[N],s[N],ans[N],t1[N],t2[N];
bool cmp(char a[],char b[],int len)
{
	fo(i,1,len)
	if (a[i]<b[i]) return 1; else
	if (a[i]>b[i]) return 0;
	return 1;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T;
	scanf("%d",&T);
	fo(cas,1,T)
	{
		scanf("%s",ch+1);
		int n=strlen(ch+1);
		int len=0;
		fo(i,1,n)
		{
			memcpy(t1,ans,sizeof t1);
			t1[len+1]=ch[i];
			memcpy(t2,ans,sizeof t2);
			fd(i,len,1) t2[i+1]=ans[i];
			t2[1]=ch[i];
			len++;
			if (cmp(t1,t2,len)) memcpy(ans,t2,sizeof t2); else
			memcpy(ans,t1,sizeof t1);
		}
		printf("Case #%d: ",cas);
		fo(i,1,len) printf("%c",ans[i]);
		printf("\n");
	}
} 
