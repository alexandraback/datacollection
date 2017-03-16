#include<iostream>

using namespace std;

string s;
int n;

bool isC(char x) {
	return !(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');
}

int main() {
	int Ncase;
	
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> Ncase;
	for (int T = 1; T <= Ncase; T ++) {
		long long ans = 0;
		cin >> s >> n;
		int l = s.size();
		int p, t, q;
		p = 0;
		t = q = l;
		
		for (int i = 0; i < l ; i ++) {
			if (isC(s[i])) {
				t = q = i;
				break;
			}
		}
		
		while (p < l) {
			while (t < l && q - t < n) {
				if (!isC(s[q])) {
					t = q + 1;
					
					while (t < l && !isC(s[t])) {
						t ++;
					}
					q = t;
					continue;
				} else if (q == l) {
					t = l;
				}
				
				while (q < l && q - t < n && isC(s[q])) {
					q ++;
				}
			}
			
			if (t != l) {
				ans += l - q + 1;
			}

			p ++;
			if (p > t) {
				t = p;
			}
		}
		
		cout << "Case #" << T << ": " << ans << endl;
	}
	return 0;
}
