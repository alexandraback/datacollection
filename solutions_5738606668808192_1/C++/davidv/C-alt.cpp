/* Let k be a number with N/2 bits, where the first and last bits are 1.
 then k*(2^(N/2)+1) is okay with as divisors 100...001_b (N/2-1 0s) in base b*/

#include <bits/stdc++.h>

using namespace std;

void doCase(int t) {
	int N, J;
	
	cin >> N >> J;
	
	vector<long long> cur;
	
	for (int b=2; b<10; b++) {
		long long divis = 1;
		for (int j=0; j<N/2; j++) divis *= b;
		divis += 1;
		cur.push_back(divis);
	}
	cout << "Case #" << t << ":" << endl;
	for (int i=(1<<(N/2-1))+1; J>0; i+=2,J--) {
		for (int j=(N/2)-1; j>=0; j--) {
			if (i & (1<<j)) cout << "1";
			else cout << "0";
		}
		for (int j=(N/2)-1; j>=0; j--) {
			if (i & (1<<j)) cout << "1";
			else cout << "0";
		}
		for (auto d : cur) cout << " " << d;
		cout << endl;
	}
}

int main()
{
	int t;
	cin >> t;
	for (int i=0; i<t; i++) doCase(i+1);
	return 0;
}
