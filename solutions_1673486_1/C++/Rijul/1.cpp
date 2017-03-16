#include<stdio.h>
#include<algorithm>
using namespace std;

#define maxm 100050

double p[maxm];
int a,b;
double mini(double a,double b){
	if(a<b) return a;
	return b;
}
double cal(int ind,int fl);

int main(){

	int i,j,k,l,test,t=1;

	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&a,&b);
		double tot[maxm];
		tot[0]=1;
		for(i=1;i<=a;i++){
			scanf("%lf",&p[i]);
			tot[i]=tot[i-1]*p[i];
		}
		//cal(1,0);
		double ans; double kd=b-a+1;
		ans=tot[a]*kd; double pd=1-tot[a];
		kd+=(b+1);ans+=(pd*kd);
		double ans1,ld;
		ans1=b+2;
		ans=mini(ans,ans1);

		for(i=1,j=a-1;i<a;i++,j--){
			kd=(i+(b-(a-i))+1);
			ld=kd+b+1;
			pd=1-tot[j];
			ans1=tot[j]*kd+pd*ld;
			ans=mini(ans,ans1);
		}
		ans1=a+b+1;
		ans=mini(ans,ans1);
		ans+=1e-9;
		printf("Case #%d: %.6lf\n",t++,ans);

	}

	return 0;
}
