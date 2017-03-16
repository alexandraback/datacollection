#include <bits/stdtr1c++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    for (int ca = 1; ca <= t; ca++) {
		ll n; cin >> n;
        cout << "Case #" << ca << ": ";
		if (n == 0) {
			cout << "INSOMNIA" << endl;
		} else {
			ll m = n;
			set<int> s;
			while (s.size() < 10) {
				ll num = m;
				while (num > 0) {
					s.insert(num%10);
					num /= 10;
				}
				
				if (s.size() == 10) break;
				m += n;
			}
			
			cout << m << endl;
		}
    }
	return 0;
}