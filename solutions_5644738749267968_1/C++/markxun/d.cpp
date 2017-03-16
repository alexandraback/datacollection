#include<stdio.h>
int tot,T;
int f[1024];
double a[2][1024];
void sort(int num,int n){
	int i,j;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(a[num][i] < a[num][j]){
				double temp = a[num][j];
				a[num][j] = a[num][i];
				a[num][i] = temp;
			}
}
int calc(int n,int T1,int T2){
	int tt=0;
	int i,j;
	for(i=0;i<n;i++)f[i]=1;
	for(i=0;i<n;i++){
		int nu=-1;
		for(j=0;j<n;j++)
			if(f[j]==1 && a[T2][j]<a[T1][i]){
				nu = j;
				break;
			}
		if(nu!=-1){
			tt++;
			f[nu] = 0;
		}else{
			for(j=n-1;j>=0;j--)
				if(f[j]==1){
					f[j] = 0;
					break;
				}
		}
	}
	return tt;
}
int main(){
	int i,ans1,ans2;
	int n;
	freopen("sample.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for(tot=1;tot<=T;tot++){
		scanf("%d",&n);
		for(i = 0;i<n;i++)scanf("%lf",&a[0][i]);
		for(i=0;i<n;i++)scanf("%lf",&a[1][i]);
		sort(0,n);
		sort(1,n);
		ans1 = calc(n,0,1);
		ans2 = n - calc(n,1,0);
		printf("Case #%d: %d %d\n",tot,ans1,ans2);
	}
}
