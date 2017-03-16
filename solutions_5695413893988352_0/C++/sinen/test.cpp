#include <bits/stdc++.h>
using namespace std;

void solve (int tc) {
	string s, t;
	cin >> s >> t;
//	s += "000";
//	t += "000";
	string sans, tans;
	int n = s.length();
	sans = s, tans = t;
	long long cost = 11111111111111111;
	int cnt = 0;
	for (int i1 = '0'; i1 <= '9'; i1++)
		for (int i2 = '0'; i2 <= '9'; i2++)
			for (int i3 = '0'; i3 <= '9'; i3++)
				for (int j1 = '0'; j1 <= '9'; j1++)
					for (int j2 = '0'; j2 <= '9'; j2++)
						for (int j3 = '0'; j3 <= '9'; j3++) {
							string ss, tt;
							ss = s; tt = t;
							if (s[0] == '?') ss[0] = i1; 
							if (s[1] == '?') ss[1] = i2;
							if (s[2] == '?') ss[2] = i3;
							if (t[0] == '?') tt[0] = j1;
							if (t[1] == '?') tt[1] = j2;
							if (t[2] == '?') tt[2] = j3;
							long long nows = 0, nowt = 0, now;
							for (int i = 0; i < n; i++) nows = nows * 10 + ss[i], nowt = nowt * 10 + tt[i];
							now = abs(nows - nowt);
							if (abs(now) < cost || abs(now) == cost && (sans > ss || sans == ss && tans > tt))
								sans = ss, tans = tt, cost = abs(now);
						}
	cout << "Case #" << tc << ": " << sans << " " << tans << "\n";
}

int main () {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
//	clock_t start = clock();
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) solve (tc);
//	cout << (double) (clock() - start) / CLOCKS_PER_SEC << "\n";
}