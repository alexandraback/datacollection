#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;
const long long MAX = 10000000; 
vector<long long> fas;

bool ispal(long long x) {
	char s[256];
	sprintf(s, "%lld", x);
	
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		if (s[i] != s[len - 1 - i]) return false;
	}
	return true;
}

int main(int argc, char **argv) {
	for (long long i = 1; i <= MAX; i++) {
		if (ispal(i) && ispal(i*i)) fas.push_back(i*i);
	}
	int tc;
	cin >> tc;
	for (int c = 0; c < tc; c++) {
		cout << "Case #" << (c + 1) << ": ";
		long long a, o;
		cin >> a >> o;
		int aId = 0;
		while (aId < fas.size() && fas[aId] < a) aId++;
		int oId = fas.size() - 1;
		while (oId > 0 && fas[oId] > o) oId--;
		printf("%d\n", (oId - aId + 1));
	}
	return 0;
}
