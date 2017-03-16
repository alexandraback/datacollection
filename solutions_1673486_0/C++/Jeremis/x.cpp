#include <iostream>
#include <vector>
using namespace std;

double calc(int a,int b,vector <double>&v) {
	//strat1
	double succ = 1;
	for (int i=0;i<a;i++) succ*=v[i];
	double ans = succ*(b-a+1) + (1-succ)*(b-a+1+b+1);
	//strat3
	ans = min(ans,b+2.0);
	//strat2
	for (int i=1;i<a;i++) {
		succ/=v[a-i];
		ans = min(ans,succ*(b-a+1+i*2) + (1-succ)*(b-a+1+b+1+i*2));
	}
	return ans;
}

int main() {
	int n;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int a,b;
		vector <double> v;
		scanf("%d %d",&a,&b);
		v.resize(a);
		for (int j=0;j<a;j++) scanf("%lf",&v[j]);
		printf("Case #%d: %.9lf\n",i+1,calc(a,b,v));
	}
}