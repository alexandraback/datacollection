#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

//Macro........
#define maxm 300
#define eps 1e-7
#define sq(a) ((a)*(a))
#define iseq(a,b) (fabs(a-b)<eps)

int a[maxm],n,sum1,sum2;
double b[maxm];
double mini(double a,double b){
	if(a<b) return a;
	return b;
}
double cal(int ind);
double ff1(double val1,double val2,double piv);
int f(int ind,double val);

int main(){

	int i,j,k,l,test,t=1;

	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);
		sum1=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum1+=a[i];
			b[i-1]=a[i];
		}
		int n1=n;
		sort(b,b+n1);
		sum2=sum1;
		sum1+=sum1;
		double avg=sum1/n; double ans,ans1,temp;
		printf("Case #%d:",t++);
		double rh,lh;
		for(i=1;i<=n;i++){
			ans=cal(i);
			temp=100.0;
			ans=temp*ans; ans+=1e-8;
			printf(" %.6lf",ans);
		}
		printf("\n");

	}

	return 0;
}

double cal(int ind){

	int i,j,k,l,c=35;
	double lo=0,hi=1,mid;

	while(c--){

		mid=lo+hi; mid/=2;

		if(f(ind,mid)){
			hi=mid;
		}
		else lo=mid;

	}

	return hi;
}

int f(int ind,double val){

	double ret,val1=1.0-val,ret1;
    double aa=a[ind];
	double sumt1=sum1,sumt2=sum2;
	ret=aa+sumt2*val;
	int i=0;
	for(i=1;i<=n;i++){
	    if(i==ind) continue;
	    ret1=a[i];
	    if(ret1>ret) continue;
	    aa=a[i];
	    double vv=ff1(ret,a[i],sumt2);
	    val1-=vv;
	    if(val1<0) return 1;
	}
	return 0;
}
double ff1(double val1,double val2,double piv){

    int i,j,k,l,c=35;
	double lo=0,hi=1,mid;
	if(val2+piv<val1||iseq(val2+piv,val1)) return 2.0;

	while(c--){

		mid=lo+hi; mid/=2;

		if(val2+(piv*mid)>val1) hi=mid;
		else lo=mid;

	}

	return hi;

}
