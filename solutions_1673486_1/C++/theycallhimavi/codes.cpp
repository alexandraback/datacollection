#include <iostream>
#include <cstdio>
using namespace std;
int main (){
	int n;
	int a;
	int b;
	int i , j;
	double p[100000];
	double exp;
	double pr;
	double min;
	cin>>n;
	for (i=1;i<=n;i++){
		cin>>a>>b;
		for (j=0;j<a;j++){
		cin>>p[j];
		}
		min=(b+2) * 1.000;
		pr=1;
		for (j=0 ; j<a ; j++){
		pr *= p[j];
		exp = pr * (a+b - 2*j - 1) + (1-pr) * (a + 2*b - 2*j);
		if (exp < min){
			min = exp;
		}
	}
	printf("Case #%d: %0.6lf\n", i, min);
}
return 0;
}
