#include <bits/stdc++.h>
#define ll long long
#define int ll
#define mod 1000000007
using namespace std;

int convertBase(int b, int e) {
	int ret = 0;
	int mult = 1;
	while(b) {
		if(b%2 == 1)
			ret += mult;
		mult *= e;
		b/=2;
	}
	return ret;
}

void printBin(int n) {
	if(n) {
		printBin(n/2);
		cout << n%2;	
	}
}

bool isPrime(int n) {
	int limit = sqrt(n);
	for(int i = 2; i <= limit; i++)
		if(n % i == 0)
			return false;
	return true;
}

void findDiv(int n) {
	int limit = sqrt(n);
	for(int i = 2; i <= limit; i++)
		if(n % i == 0) {
			cout << " " << i;
			return;
		}	
}

main(){
	ios::sync_with_stdio(0);
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, c = 1, n, k;
	cin >> t;
	
	while(t--) {
		int ctr = 0;
		cin >> n >> k;
		cout << "Case #" << c++ << ":\n";
		int limit = 1<<(n-2);
		int add = (1<<(n-1))+1;
		for(int i = 0; i < limit; i++) {
			int bin = (i<<1) + add;
			bool hasPrime = false;
			for(int j = 2; j <= 10; j++) {
				int conv = convertBase(bin, j);
				if(isPrime(conv)) {
					hasPrime = true;
					break;
				}
			}
			if(!hasPrime) {
				printBin(bin);
				for(int j = 2; j <= 10; j++) {
					int conv = convertBase(bin, j);
					findDiv(conv);	
				}
				ctr++;
				cout << endl;
				if(ctr == k)
					break;
			}
		}
	}
}

