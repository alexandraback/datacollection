#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#define MIN(x,y) (x)<(y)?(x):(y)
using namespace std;

const int N=1000010;
char s[N];
int n;
bool isvow[26]={1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0};

long long cal(long long st,long long en,long long si,long long ei)
{
	return (en-ei+1)*(si-st+1);
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	for(int cnt=1;cnt<=t;cnt++)
	{
		scanf("%s%d",s,&n);
		long long ans=0;
		int lasti=0;
		int ls = strlen(s);
		for(int i=0;i<=ls-n;i++)
		{
			bool flag=1;
			for(int j=0;j<n;j++)
			{
				if(isvow[s[i+j]-'a']==1)
				{
					flag=0;
					break;
				}
			}
			if(flag==0) continue;
			int begin = MIN(lasti,i);
			ans += cal(begin,ls-1,i,i+n-1);
			lasti = i+1;
		}
		printf("Case #%d: %lld\n",cnt,ans);
	} 
} 
