#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>
#include <cmath>
using namespace std;
unsigned long long n, j;
unsigned long long divisor (unsigned long long num) {
	for(unsigned long long i=2; i<=sqrt(num)+1; ++i) {
		if(num%i == 0) return i;
	}
	return -1;
}


string to_binstring (unsigned long long num) {
	string binary = "";
	for(unsigned long long i=0; i<n; ++i) {
		if(num%2) binary+='1';
		else binary+='0';
		num = num>>1;
	}
	reverse(binary.begin(), binary.end());
	return binary;	
}

int main () {
	cin>>n;
	cin>>n;
	cin>>j;
	unsigned long long top = 1;
	top = top<<n;
	unsigned long long start = top>>1;
	++start;
	string curr;
	unsigned long long num;
	unsigned long long div;
	bool prime;
	size_t unused=0;
	string currline;
	unsigned long long written = 0;
	cout<<"Case #1:"<<endl;
	for(unsigned long long i=start; i<top; i+=2) {
		curr = to_binstring(i);
		currline += curr;
		bool prime = false;
		for(int base = 2; base<=10; ++base) {
			num = stoull(curr,&unused,base);
			div = divisor(num);
			if(div == -1) prime = true;
			currline+=' ';
			currline+=to_string(div); 
		}
		if(!prime) {
			cout<<currline<<endl;
			++written;
			if(written==j) return 0;
		}
		currline = "";
	}
	return 0;
}
