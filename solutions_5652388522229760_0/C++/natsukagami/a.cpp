#include <iostream>
#include <cstdio>
#include <sstream>
#include <set>
using namespace std;

string to_str(int s) {
	stringstream ss; ss << s; return ss.str();
}

int N;

int main() {
	int Tc; cin >> Tc;
	for (int T = 1; T <= Tc; ++T) {
		printf("Case #%d: ", T);
		cin >> N; 
		if (!N) { printf("INSOMNIA\n"); continue; } 
		set<char> S; int cnt = 1;
		for (int& i = cnt; S.size() < 10; ++i) {
			string p = to_str(i * N);
			for (int j = 0; j < (int)p.length(); ++j) S.insert(p[j]);
		}
		printf("%d\n", cnt * N - N);
	}
}