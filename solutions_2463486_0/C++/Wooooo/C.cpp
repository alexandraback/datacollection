#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX (int)1e7

bool isPal(long long n) {
	string temp = to_string(n);
	int size = temp.size();
	for(int i = 0 ; i < size/2 ; i++) {
		if( temp[i] != temp[size-1-i] ) return false;
	}
	return true;
}
int main() {
	int t;
	scanf("%d", &t);
	freopen("output.txt", "w", stdout);
	vector<long long> pal;
	for(long long i = 1 ; i <= MAX ; i++) {
		if( isPal(i) && isPal(i*i) ) pal.push_back(i*i);
	}
	int z = 1;
	while(t--) {
		long long a, b;
		scanf("%lld %lld", &a, &b);
		int st = upper_bound(pal.begin(), pal.end(), a-1) - pal.begin();
		int end = upper_bound(pal.begin(), pal.end(), b) - pal.begin();

		printf("Case #%d: %d\n", z++,end-st);
	}
	fclose(stdout);
}