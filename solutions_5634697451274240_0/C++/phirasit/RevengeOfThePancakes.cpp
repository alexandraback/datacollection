#include <iostream>
#include <cassert>

using namespace std;

string pancake;
int ans = 0;

void flip(int a, int b) {
	if(a > b) return;
	ans++;
	for(int i = a, j = b;i < j;i++, j--) {
		swap(pancake[i], pancake[j]);
	}
	for(int i = a;i <= b;i++) {
		pancake[i] = (pancake[i] == '+' ? '-' : '+');
	}
}
int main() {

	ios::sync_with_stdio(false);
	int test_num;
	cin >> test_num;
	for(int Case = 1;Case <= test_num;Case++) {
		cin >> pancake;
		ans = 0;
		for(int i = pancake.length() - 1;i >= 0;i--) {
			if(pancake[i] == '+') {
				continue;
			}
			if(pancake[0] == '-') {
				flip(0, i);
			}else {
				int right = 0;
				for(int j = 0;j < i;j++) {
					if(pancake[j] == '+') {
						right = j;
					}
				}
				flip(0, right);
				flip(0, i);
			}
		}

		for(char p : pancake) {
			assert(p == '+');
		}

		cout << "Case #" << Case << ": " << ans << endl;
	}
}