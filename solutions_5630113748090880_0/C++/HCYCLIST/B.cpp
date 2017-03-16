#include<cstdio>
#include<cstring>
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

const int maxh=2505;

int n;
bool bz[maxh];

int T;
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	
	scanf("%d",&T);
	fo(Ti,1,T)
	{
		printf("Case #%d: ",Ti);
		memset(bz,0,sizeof(bz));
		
		scanf("%d",&n);
		fo(i,1,2*n-1)
			fo(j,1,n)
			{
				int x;
				scanf("%d",&x);
				bz[x]^=1;
			}
		
		fo(i,1,maxh) if (bz[i]) printf("%d ",i);
		printf("\n");
	}
}