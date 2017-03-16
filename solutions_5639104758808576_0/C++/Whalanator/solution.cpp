#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

string s1;
int smax,T,c,cas,s,M;

int main() {
	cin >> T;
	for (cas=1;cas<=T;cas++) {
		cin >> smax;
		cin >> s1;
		s=0;M=0;
		for (c=0;c<=smax;c++) {
			M=max(M,c-s);
			s+=(s1[c]-'0');
		}
		cout << "Case #" << cas << ": " << M << endl;
	}
	return 0;
}
