#include <iostream>
#include <array>
#include <vector>
#include <stdio.h>

using namespace std;

#define ull unsigned long long


#define dfor(i,n) for(ull i = 0; i < n; i++)
#define rfor(i,n) for(ull i = n-1;i >=0; i--)
#define all(k) k.begin(),k.end()
#define ifor(i,b,n) for(auto i=b, i!=n, i++)


int bitcount (ull a) {
	int count = 0;
	while(a) {
		a = a & (a-1);
		count++;
	}
	return count;
}

int msb(ull a) {
	for (int i = 63; i >= 0; i-- ) {
		if ((1ull << i) & a) {
			return i;
		}
	}
}

ull gcd(ull a, ull b) {
	return b ? gcd (b, a%b) : a;
}


void solv()
{
	ull a, b;
	char k;
	cin >> a >> k >> b;
	ull g = gcd(a, b);
	a /= g;
	b /= g;
	if (bitcount(b) != 1) {
		cout << "impossible";
		return ;
	}
	int kg = msb(b) - msb(a);
	cout << kg;
	

}

int main () {

	int T, cases = 0;
	cin >> T;
	while (T--) {
		cout << "case #" << ++cases << ": " ;
		solv();
		cout << endl;
	}
	
	return 0;
}

