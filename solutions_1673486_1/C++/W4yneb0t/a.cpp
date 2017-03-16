#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
int main(){
	int t;
	cin>>t;
	double pr;
	double p;
	int a,b;
	double bt;
	for(int z=1;z<=t;z++){
		cin>>a>>b;
		pr=1;
		double tp;
		bt=b+2;
		if(a==0)
			bt=b+1;
		for(int i=1;i<=a;i++){
			cin>>p;
			pr*=p;
			tp=((b-i)+(a-i)+1)+(1-pr)*(b+1);
			if(tp<bt)
				bt=tp;
		}
		printf("Case #%d: %.6f\n",z,bt);
	}
	return 0;
}
