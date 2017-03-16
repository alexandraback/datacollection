#include <iostream>
#include <vector>
#include <string>

using namespace std;

void run(int t) {
	int smax;
	string s;

	cin >> smax >> s;
	int M = s.size();

	long long sum = s[0] - 0x30;
	long long add = 0;
	for(int i = 1; i < M; ++i) {
		if(sum < i) {
			add += i - sum;
			sum += i - sum;
		}
		sum += s[i] - 0x30;
	}

	cout << "Case #" << t + 1 << ": " << add << endl;
}


int main() {
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	for(int i = 0; i < T; ++i)
		run(i);
	return 0;
}
