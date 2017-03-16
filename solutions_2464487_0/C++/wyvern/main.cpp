#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<math.h>

using namespace std;

ifstream fin("A-small-attempt0.in");
ofstream fout("out.txt");


long long calcRes( long long n, long long r){
	return 2 * n * n - n + 2 * r * n;
}
long long calc(unsigned long long n, unsigned long long r){
	unsigned long long upper;

	if( n < (1 << 30))
		upper = n / r;
	else
		upper = ((1 << 30) < n/r) ? (1 << 30) : n/r;

	unsigned long long guess = upper / 2;
	unsigned long long lower = 1;

	while(true){
		unsigned long long val = calcRes(guess, r);

		if( val <= n && calcRes(guess + 1, r)> n){
			return guess;
		}else if( val > n){
			upper = guess;
			guess = guess / 2;
		}else if( val < n){
			guess = (guess + upper) / 2;
			lower = guess;
		}
	}
}

void print(long long n){
	if( n ==0)
		return;

	print(n/10);
	
	fout<< n%10;
}

int main(){
	int ncases;

	long long t;
	long long r;
	fin>>ncases;

	for(int test = 1; test <= ncases; test++){
		fin>>r>>t;
		long long res = calc(t, r);
		fout<<"Case #"<<test<<": ";
		print(res);
		fout<<"\n";
	}
}