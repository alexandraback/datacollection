#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int cases = 0;
	cin >> cases;
	for(int ca=1;ca<=cases;ca++){
		long double c=0.0,f=0.0,x=0.0;
		cin >> c >> f >> x;
		long double fr = 2.0;
		long double sum = 0.0;
		while(x/(fr+f) + c/fr < x/fr){
			sum += c/fr;
			fr += f;
		}
		sum += x/fr;
		//cout << sum << endl;
		printf("Case #%d: %.7Lf\n", ca, (double)sum);
	}
}