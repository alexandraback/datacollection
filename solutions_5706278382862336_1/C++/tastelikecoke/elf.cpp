#include <iostream>
using namespace std;
long long gcdf(long long a, long long b){
	long long t = 0;
	while(b!=0){
		t = b;
		b = a%b;
		a = t;
	}
	return a;
}
int main() {
	int cases = 0;
	cin >> cases;
	for(int c=0;c<cases;c++){
		long long a = 0;
		long long b = 0;
		cin >> a;
		cin.get();
		cin >> b;
		long long gcd = gcdf(a,b);
		a /= gcd;
		b /= gcd;
		long long denom=1, num=2, gen=0; 
		while(denom<b){
			denom *= 2;
			gen += 1;
		}
		while(num<a){
			num *= 2;
			gen -= 1;
		}
		if(denom != b){
			cout<<"Case #"<<c+1<<": impossible";
		}
		else{
			cout<<"Case #"<<c+1<<": "<<gen;
		}
		cout << endl;
	}
	return 0;
}