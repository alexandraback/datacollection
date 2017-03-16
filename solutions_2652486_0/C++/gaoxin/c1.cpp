#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<cmath>
#include<map>
using namespace std;


#define debug(x) cout << #x << "=" << x << endl
#define sqr(x) ((x)*(x))

typedef long long ll;

int tests,r,n,m,k;
int a[4],u[66];
map<int,int> mp[555];

int main()
{
	freopen("c1.in","r",stdin);
	freopen("c1.out","w",stdout);
	scanf("%d",&tests);
	printf("Case #1:\n");
	
	
		for (a[1]=2;a[1]<6;a[1]++)
		for (a[2]=2;a[2]<6;a[2]++)
		for (a[3]=2;a[3]<6;a[3]++)
		{
			int k = (a[1]-2)*16+(a[2]-2)*4+a[3]-2;
			for (int opt=0;opt<8;opt++)
			{
				int t = 1;
				for (int i=0;i<3;i++) if ((opt|(1<<i))==opt)
					t *= a[i+1];
				mp[k][t] = 1;
				//if (k==22) printf("# %d -> %d\n",k,t);
			}
		}


	scanf("%d%d%d%d",&r,&n,&m,&k);
	while (r--)
	{
		for (int i=0;i<64;i++) u[i] = 1;
		for (int j=1;j<=k;j++)
		{
			int x;
			scanf("%d",&x);
			//debug((mp[22].find(x) == mp[22].end()));
			for (int i=0;i<64;i++)
				if (mp[i].find(x)==mp[i].end())
					u[i] = 0;
			//for (int i=0;i<64;i++) printf("%d ",u[i]); printf("\n");
		}
		//for (int i=0;i<16;i++) printf("%d ",u[i]); printf("\n");
		for (int i=0;i<64;i++)
			if (u[i])
			{
				printf("%d%d%d\n",i/16+2,i/4%4+2,i%4+2);
				break;
			}
	}
	
	return 0;
}
