#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define LL long long

LL calc(LL k,LL r){
	LL res=2*k*r;
	res+=k*(2*k-1);
	return res;
}

int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int T;
	LL R,t;
	cin>>T;
	for (int cas=1;cas<=T;cas++){
		cin>>R>>t;
		double a=2;
		double b=2*R-1;
		double c=-t;
		double x1=(-b-sqrt(b*b-4*a*c))/2/a;
		double x2=(-b+sqrt(b*b-4*a*c))/2/a;
//		cout<<x1<<' '<<x2<<endl;
		LL l=(LL)x2-100;
		if (l<1) l=1;
		LL r=(LL)x2+100;
		while (l!=r){
			LL mid=((l+r)>>1)+1;
			LL res=calc(mid,R);
//			cout<<mid<<' '<<res<<endl;
			if (res>t) r=mid-1;
			else l=mid;
		}
		cout<<"Case #"<<cas<<": "<<l<<endl;
	}
	return 0;
}
