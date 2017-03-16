#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=100010;
int a[10],b[25][25];
void pre()
{
	a[0]=1;
	a[2]=6;
	a[4]=15;
	a[6]=28;
	int i,j;
	memset(b,0,sizeof(b));
	for(i=1;i<25;i++)
	{
		b[i][0]=1;
	}
	b[0][0]=1;
	for(i=1;i<25;i++)
	{
		for(j=1;j<=i;j++)
		{
			b[i][j]=b[i-1][j]+b[i-1][j-1];
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,cas=0;
	scanf("%d",&t);
	pre();
	while(t--)
	{
		printf("Case #%d: ",++cas);
		int n,x,y;
		scanf("%d%d%d",&n,&x,&y);
		int h=abs(x)+y;
		int i;
		int s,p;
		for(i=6;i>=0;i-=2)
		{
			if(n>=a[i])
			{
				s=i;
				p=n-a[i];
				break;
			}
		}
		if(h>s+2||(h==s+2&&p==0)||(h==s+2&&p<y+1))
		{
			printf("0.0\n");
			continue;
		}
		if(h<=s)
		{
			printf("1.0\n");
			continue;
		}
		int pp=0;
		for(i=max(y+1,p-s-2);i<=min(s+2,p);i++)
		{
			pp+=b[p][i];
			//printf("%d**%d**%d\n",p,i,pp);
		}
		int kk=0;
		for(i=max(0,p-s-2);i<=min(s+2,p);i++)
		{
			kk+=b[p][i];
		}
		//printf("%d**\n",kk);
		double ppp=1.0*pp/kk;
		printf("%.8lf\n",ppp);
	}


	fclose(stdin);
	fclose(stdout);
	return 0;
}
