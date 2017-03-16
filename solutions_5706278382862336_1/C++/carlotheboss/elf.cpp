#include <cmath>
#include <iostream>
#include <cstdio>
using namespace std;


struct F {
	unsigned long long num, den;
};

int T;
F temp;

unsigned long long gcd(unsigned long long a, unsigned long long b) { return b==0 ? a : gcd(b, a%b); }

bool Potenza(unsigned long long x) {
	unsigned long long p=0;
	while(pow(2, p) < x && p<= 40) p++;
	if(pow(2, p) > x || p > 40) return false;
	else return true;
}
int Prova(F x) {
	if(x.num == x.den) return 0;
	x.num *= 2;
	unsigned long long g = gcd(x.num, x.den);
	x.num /= g;
	x.den /= g;
	if(x.num > x.den) {
		F appo=x;
		appo.num=appo.den;
		return 1 + Prova(appo);
	}
	else return 1 +Prova(x);
}
		
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> T;
	for(int i=0; i < T; i++) {
		char op;
		cin >> temp.num >> op >> temp.den;
		unsigned long long g = gcd(temp.num, temp.den);
		temp.num /= g;
		temp.den /= g;
		if(!Potenza(temp.den)) cout<<"Case #"<<i+1<<": impossible\n";
		else {
		 unsigned long long ris = Prova(temp);
		 cout<<"Case #"<<i+1<<": "<<ris<<endl;
		}
	}
	return 0;
}
