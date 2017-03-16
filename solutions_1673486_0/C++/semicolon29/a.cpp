
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	int t,cs,i;
	cin>>t;
	for(cs=1;cs<=t;cs++){
		int a,b;
		double p[100000],x;
		p[0]=1.0;
		cin>>a>>b;
		for(i=0;i<a;i++){
			scanf("%lf",&x);
			p[i+1]=p[i]*x;
//			cout<<p[i+1]<<endl;
		}
		double ans,min=1e9;
		int c=b-a+1;
		for(i=a;i>=1;i--){
//			cout<<c<<endl;
			ans=c*p[i]+(c+b+1)*(1-p[i]);
			if(ans<min)
				min=ans;
			c+=2;
		}
		if(b+2<min)
			min=b+2;
		printf("Case #%d: %lf\n",cs,min);
	}
	return 0;
}
