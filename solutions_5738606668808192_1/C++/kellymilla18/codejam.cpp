#include <bits/stdc++.h>
#define ll long long
#define int ll
#define mod 1000000007
using namespace std;

int modpow(int a, int b, int c) {
	int ret = 1;
	while(b) {
		if(b%2 == 1)
			ret = (ret * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}
	return ret;
}

bool isPrime(int n, int base, int len) {
	int copy = n;
	for(int i = 2; i < 10; i++) {
		n = copy;
		int rem = modpow(base, len-1, i);
		int mult = 1;
		while(n) {
			if(n%2 == 1) {
				rem += mult;
				if(rem >= i)
					rem -= i;
			}
			mult = (mult * base) % i;
			n /= 2;
		}
		if(rem == 0) 
			return false;
	}	
	return true;
} 

void printBin(int n, int l) {
	if(l) {
		printBin(n/2, l-1);
		cout << n%2;
	}
}

void getDiv(int n, int base, int len) {
	int copy = n;
	for(int i = 2; i < 10; i++) {
		n = copy;
		int rem = modpow(base, len-1, i);
		int mult = 1;
		while(n) {
			if(n%2 == 1) {
				rem += mult;
				if(rem >= i)
					rem -= i;
			}
			mult = (mult * base) % i;
			n /= 2;
		}
		if(rem == 0) {
			cout << i;
			return;
		}
	}
} 

main(){
	ios::sync_with_stdio(0);
	freopen("C-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, c = 1, n, k;
	cin >> t;
	
	while(t--) {
		int ctr = 0;
		cin >> n >> k;
		cout << "Case #" << c++ << ":\n";
		for(int i = 0; ; i++) {
			bool hasPrime = false;
			for(int j = 2; j <= 10; j++) {
				if(isPrime((i<<1) + 1, j, n)) {
					hasPrime = true;
					break;
				}
			}
			if(!hasPrime) {
				cout << 1;
				printBin((i<<1) + 1, n-1);
				for(int j = 2; j <= 10; j++) {
					cout << " ";
					getDiv((i<<1) + 1, j, n);
				}
				ctr++;
				cout << endl;
				if(ctr == k)
					break;
			}
		}
	}
}

