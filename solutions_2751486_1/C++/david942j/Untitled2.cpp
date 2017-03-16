#include <cstdio>
#include <algorithm>
#include <cstring>
const int N=1001000;
char s[N];
int sum[N],cons[N];
bool ok[N];
int is(char c)
{return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';}
struct unit{
	int L,R;
};
inline int max (int a,int b){return a>b?a:b;}
int main()
{
	int T,w=1;
	scanf("%d",&T);
	while(T--)
	{
		int k;
		scanf("%s%d",s+1,&k);
		int n=strlen(s+1);
		for(int i=1;i<=n;i++)
			ok[i]=cons[i]=0;
		for(int i=1;i<=n;i++)
			if(!is(s[i]))
			{
				int l=i,r;
				while(i<=n&&!is(s[i]))
					i++;
				i--;
				r=i;
				for(int j=l;j<=r;j++)
					cons[j]=r-j+1;
			}
		long long ans=0;
		int last=1;
		for(int i=1;i<=n;i++){
			bool got=false;
			for(int j=max(last,i);j+k-1<=n;j++)
				if(cons[j]>=k)
				{
					ans+=n-(j+k-1)+1;
					last=j;
					got=true;
					break;
				}
				else j+=cons[j];
			if(!got)break;
		}
		printf("Case #%d: %lld\n",w++,ans);
		fprintf(stderr,"%d\n",w);
	}
}
