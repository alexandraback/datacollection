#include <iostream>
#include <string>

using namespace std;

string line;
int n;

bool isvowel(char kar) {
	return (kar == 'a' || kar == 'e' || kar == 'i' || kar == 'o' || kar == 'u');
}

void doit(int casenum) {
	cin >> line >> n;
	
	long long ans = 0;
	int seen = 0;
	int laststart = -1;
	int N = line.size();
	for (int i = 0; i < N; ++i) {
		if (isvowel(line[i])) {
			seen = 0;
		} else {
			seen++;
			if (seen >= n) {
				ans += ((i - n + 1) - laststart) * ((N - 1) - i + 1);
				//cerr << "d: " << i << ' ' << (i - n + 1 - laststart) << ' ' << ((N - 1) - i + 1) << endl;
				laststart = i - n + 1;
			}
		}
	}
	cout << "Case #" << casenum << ": " << ans << endl;
}

int main() {
	int t;
	cin >> t;
	cin.get();
	for (int i = 1; i <= t; ++i) doit(i);
	return 0;
}