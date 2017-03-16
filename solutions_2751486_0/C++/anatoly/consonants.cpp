#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <utility>
using namespace std;

void bruteforce(int tc) {
	string s;
	int n;
	cin >> s; 
	cin >> n;

	int value = 0;

	for (int b = 0; b < s.length(); ++b) {
		for (int e = b; e < s.length(); ++e) {
			int c = 0;
			for (int i = b; i <= e; ++i) {
				if (!(s[i] == 'a' || s[i] == 'e'  || s[i] == 'i'  || s[i] == 'o'  || s[i] == 'u')) {
					++c;
				} else if (c) {
					c = 0;
				}

				if (c == n) {
					value += 1;
					break;
				}
			}
		}
	}

		
	cout << "Case #" << tc + 1 << ": ";
	cout << value << endl;
}

int main() {
	int T; cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		bruteforce(tc);
		/*string s; int n;
		cin >> s; 
		cin >> n;

		int c = 0;
		int value = 0;
		int ccend = -1;

		for (int i = 0; i < s.length(); ++i) {
			if (!(s[i] == 'a' || s[i] == 'e'  || s[i] == 'i'  || s[i] == 'o'  || s[i] == 'u')) {
				++c;
			} else if (c) {
				--c;
			}

			if (c == n) {
				value += i - n + 2;

				ccend = i;
				i = i - n + 1;
				c = 0;
			} else if (ccend >= 0 && i > ccend) {
				value += (ccend - n + 2);
			}

		}

		
		cout << s << " " << n << endl;
		cout << "Case #" << tc + 1 << ": ";
		cout << value << endl;
		cout << endl;*/
	}
}