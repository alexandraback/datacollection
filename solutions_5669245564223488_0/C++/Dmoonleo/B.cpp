#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int in[26];
int to[26];
int out[26];
int self[26];
bool middle[26];
bool middle2[26];
bool reached[26];

long long fact(int a) {
	long long ans = 1;
	for (int i = 2; i <= a; i++) {
		ans *= i;
	}
	return ans;
}

long long dfs(int i) {
	long long sum = 1;
	reached[i] = true;
	if (self[i]) sum *= fact(self[i]);
	if (in[i]) return sum * dfs(to[i]);
	return sum;
}

int main() {
	int T;
	cin >> T;
	for(int c=1;c<=T;c++) {
		int N;
		cin >> N;
		string car;
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		memset(self, 0, sizeof(self));
		memset(middle, 0, sizeof(middle));
		bool flag = true;
		while (N--) {
			cin >> car;
			if (car[0] == car[car.size() - 1]) {
				for (int i = 0; i < car.size(); i++) {
					if (car[i] != car[0]) {
						flag = false;
					}
				}
				self[car[0] - 'a'] ++;
			}
			else {
				in[car[0] - 'a']++;
				out[car[car.size() - 1] - 'a']++;
				int left = 1;
				int right = car.size() - 2;
				while (left < car.size() && car[left] == car[left - 1]) left++;
				while (right >= 0 && car[right] == car[right + 1])right--;
				for (int i = left; i <= right; i++) {
					if (car[i] != car[i - 1]) {
						if (middle[car[i] - 'a'] == true) {
							flag = false;
						}
						else {
							middle[car[i] - 'a'] = true;
						}
					}
				}
				to[car[0] - 'a'] = car[car.size() - 1] - 'a';
			}
		}
		for (int i = 0; i < 26; i++) {
			if (middle[i] && (in[i] || out[i] || self[i])) {
				flag = false;
			}
			if (in[i] > 1 || out[i] > 1) {
				flag = false;
			}
		}
		cout << "Case #" << c << ": ";
		//for (int i = 0; i < 26; i++) {
		//	cout << char(i+'a') << ": ";
		//	cout << "in " << in[i] << " out " << out[i] << " middle " << middle[i] << " to " << to[i] << endl;
		//}
		if (flag == false) {
			cout << 0 << endl;
		}
		else {
			memset(reached, 0, sizeof(reached));
			long long part = 0;
			long long sum = 1;
			for (int i = 0; i < 26; i++) {
				if (in[i] == 1 && out[i] == 0) {
					part++;
					sum *= dfs(i);
				}
				else if (in[i] == 0 && out[i] == 0 && self[i] > 0) {
					part++;
					sum *= fact(self[i]);
					reached[i] = true;
				}
			}
			for (int i = 0; i < 26; i++) {
				if (in[i] || out[i] || self[i]) {
					if (!reached[i]) {
						flag = false;
					}
				}
			}
			//cout << "part: " << part << endl;
			sum *= fact(part);
			cout << (flag ? sum : 0) << endl;
		}
	}
	return 0;
}