#include <cmath>
#include <iostream>
#include <cstdio>
using namespace std;

#define MAX 1<<41

struct F {
	int num, den;
};

int T;
F temp;

int gcd(int a, int b) { return b==0 ? a : gcd(b, a%b); }

bool Potenza(int x) {
	int p=0;
	while(pow(2, p) < x) p++;
	if(pow(2, p) > x) return false;
	else return true;
}
int Prova(F x) {
	if(x.num == x.den) return 0;
	x.num *= 2;
	int g = gcd(x.num, x.den);
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
		int g = gcd(temp.num, temp.den);
		temp.num /= g;
		temp.den /= g;
		if(!Potenza(temp.den)) cout<<"Case #"<<i+1<<": impossible\n";
		else {
		 int ris = Prova(temp);
		 cout<<"Case #"<<i+1<<": "<<ris<<endl;
		}
	}
	return 0;
}
