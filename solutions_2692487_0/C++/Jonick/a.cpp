#include <vector>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void solveTest()
{
	int A, N;
	cin >> A >> N;
	vector<int> a(N);
	for( int i = 0; i < N; i++ ) {
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	int best = a.size();
	int cur = A;
	int ind = 0;
	int cP = 0;
	if( cur == 1 ) {
		cout << a.size() << endl;
		return;
	}
	while( ind < a.size() ) {
		if( cur > a[ind] ) {
			cur += a[ind];
			ind++;
		} else {
			cP++;
			cur += cur - 1;
		}
		int tmp = cP + a.size() - ind;
		best = min(best, tmp);
	}
	cout << best << endl;
}

void run()
{
	int tn;
	cin >> tn;
	for( int i = 0; i < tn; i++ ) {
		cout << "Case #" << (i+1) << ": ";
		solveTest();
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	run();
	return 0;
}