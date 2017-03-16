#include <iostream>
using namespace std;
#define M 101
#define N 101
int a[M][N],ru[M],rl[M],cu[N],cl[N],m,n;
bool check(){
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++){
			if(ru[i] == a[i][j])continue;
			if(a[i][j] < cu[j])return false;
		}
	}
	return true;
}
int main(){
	//freopen("A-small-practice.in","r",stdin);
	//freopen("A-small-practice.out","w",stdout);
	int t,nt,i,j;
	scanf("%d",&t);
	for(nt = 1;nt <= t;nt ++)
	{
		scanf("%d%d",&m,&n);
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		for(i=0;i<m;i++)
			ru[i] = rl[i]= a[i][0];
		for(j=0;j<n;j++)
			cu[j] = cl[j] = a[0][j];
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
			{
				if(a[i][j]>ru[i])ru[i]=a[i][j];
				if(a[i][j]<rl[i])rl[i]=a[i][j];
				if(a[i][j]>cu[j])cu[j]=a[i][j];
				if(a[i][j]<cl[j])cl[j]=a[i][j];
			}
		printf("Case #%d: ",nt);
		if(check())printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}