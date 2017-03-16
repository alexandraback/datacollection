#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool palindrom(unsigned long long val) {
	char k[100];
	sprintf(k,"%lld",val);
	int len = strlen(k);
	for (int i=0; i<len; i++) {
		if (k[i] != k[len-1-i]) return false;
	}
	return true;
}
vector<unsigned long long> data;

void execute(int tc) {
	unsigned long long l,r;
	cin >> l >> r;
	vector<unsigned long long>::iterator low, up;
	low = lower_bound (data.begin(), data.end(), l);
	up =  upper_bound (data.begin(), data.end(), r);
	printf("Case #%d: ", tc);
	int ans = (up-data.begin()) - (low - data.begin());
	cout << ans << endl;
	
}

int main() {
	
	for (unsigned long long i=0LL; i< 2001003LL; i++) {
		unsigned long long x = i*i;
		if (palindrom(i) && palindrom(x)) {
			data.push_back(x);
		}
	}
	int tc;
	cin >> tc;
	for (int t=1; t<=tc; t++) {
		execute(t);
	}
	
}
