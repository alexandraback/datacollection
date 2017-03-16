#include <iostream>
using namespace std;

double mymin(double a,double b){
	if(a<b)return a;
	return b;
}

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int T,A,B;
	cin >> T;
	for(int Case = 1; Case <= T ;Case ++){
		cin >> A >> B;
		double ans = 9999999999.0,pi,E;
		double p = 1.0;
		for(int i = 1;i <= A; i++){
			cin >> pi;
			p = p * pi;
			E = p * (A - i + 1 + B - i) + (1 - p) * (A - i + 1 + B - i + B + 1);
			ans = mymin(E,ans);
		}
		ans = mymin(B+2,ans);
		printf("Case #%d: %.6f\n",Case,ans);
	}
	
	
	return 0;
}
