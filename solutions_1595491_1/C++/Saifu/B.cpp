#include <iostream>
using namespace std;

int main() {
	int T, N, S, P, ans, num, tmp;
	cin >> T;
	
	for(int i=1; i<=T; i++) {
		ans = 0;
		cin >> N >> S >> P;
		while(N--) {
			cin >> num;
			if(num == 0) {
				if(P == 0)
					ans++;
				continue;
			}
			tmp = num / 3;
			if(num%3 == 0) {
				if(tmp >= P)
					ans++;
				else if(S > 0 && tmp+1 >= P) {
					ans++;
					S--;
				}
			} else if(num%3 == 1) {
				tmp++;
				if(tmp >= P)
					ans++;
			} else {
				tmp++;
				if(tmp >= P)
					ans++;
				else if(S > 0 && tmp+1 >= P) {
					ans++;
					S--;
				}
			}
		}
		cout << "Case #" << i << ": " << ans << endl;
	}
	
	return 0;
}
