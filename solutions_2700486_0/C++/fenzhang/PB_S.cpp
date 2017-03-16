#include<stdio.h>
#include<algorithm>
using namespace std;
int n,x,y;
typedef double dou;
dou dp[3000][3000];
void sol(int uuu){
	scanf("%d %d %d",&n,&x,&y);
	if(x<0)x*=-1;
	int a=(x+y)/2;
	int b=0;
	for(int t=1;n>=t;t+=4){
		n-=t;
		b++;
		}
	//printf("%d %d\n",b,n);
	if(a<b){
		printf("Case #%d: %.10lf\n",uuu,1.0);
		return;
		}
	if(a>b){
		printf("Case #%d: %.10lf\n",uuu,0.0);
		return;
		}
	dou ans=0;
	dp[0][0]=1;
	for(int i=0;i<=n&&i<=b*2;i++){
		for(int j=0;i+j<=n&&j<=b*2;j++){
			if(i==0&&j==0)
				continue;
			dp[i][j]=0;
			if(i)
				dp[i][j]+=dp[i-1][j]*0.5*(1+(j==b*2));
			if(j)
				dp[i][j]+=dp[i][j-1]*0.5*(1+(i==b*2));
			if(i+j==n&&j>y)
				ans+=dp[i][j];
			}
		}
	printf("Case #%d: %.10lf\n",uuu,ans);
	}
int main(){
	freopen("B-small-attempt1.in","r",stdin);
	freopen("PBout.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int ti=1;ti<=t;ti++)
		sol(ti);
	return 0;
	}
