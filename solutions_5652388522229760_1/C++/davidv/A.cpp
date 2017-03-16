#include <bits/stdc++.h>

using namespace std;

void doCase(int t) {
	cout << "Case #" << t << ": ";
	
	int N;
	cin >> N;
	
	if (N == 0) {
		cout << "INSOMNIA" << endl;
		return;
	}
	
	set<int> seen;
	
	for (int k=1; true; k++) {
		int cur = k*N;
		
		while (cur) {
			int d = cur % 10;
			cur /= 10;
			seen.insert(d);
			
			if (seen.size() == 10) {
				cout << k * N << endl;
				return;
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;
	for (int i=0; i<t; i++) doCase(i+1);
	return 0;
}
