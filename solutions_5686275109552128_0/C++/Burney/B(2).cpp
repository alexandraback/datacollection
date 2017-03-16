#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=2147483647;
int T,N,G[1001];
bool cmp_G(int a,int b){return a>b;}
int max(int a,int b){return a>b?a:b;}
void getmin(int &a,int b){if(b<a)a=b;}
int STEP[1001][1001];//steps take to reduce i to j
int get_step(int l)
{
	int ans=0;
	for(int i=0;i<N;i++)ans+=STEP[G[i]][l];
	return ans;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	for(int i=0;i<=1000;i++)
	{
		for(int j=1;j<=1000;j++)
		{
			int &step=STEP[i][j];
			step=(i+(j-1))/j;
			if(step>0)step--;
		}
	}
	scanf("%d",&T);
	int kase=1;
	while(T--)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&G[i]);
		}
		sort(G,G+N,cmp_G);
		int ans=G[0];
		for(int i=G[0];i>=1;i--)
		{
			int j=get_step(i)+i;
//			printf("%d %d\n",i,get_step(i));
			getmin(ans,j);
		}
		printf("Case #%d: %d\n",kase++,ans);
	}
	return 0;
}
