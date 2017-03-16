#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


long long E,R,V[10001];
int N;

long long naive(int idx, long long maxe) {
	if(idx == N)
		return 0;
	if(maxe > E)
		maxe = E;
	long long best = 0;
	for(long long i = maxe; i >= 0; i--)
		best = max(best, i*V[idx]+naive(idx+1,maxe-i+R));
	return best;
}

int main() {
	int testcases;
	cin >> testcases;
	for(int curtestcase = 1; curtestcase <= testcases; curtestcase++) {
		cout << "Case #" << curtestcase << ":";
		cin >> E >> R >> N;
		for(int i = 0; i < N; i++)
			cin >> V[i];
		cout << " " << naive(0,E);
	
	
		cout << endl;
	}
}