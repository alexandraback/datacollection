#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<(n);i++)
#define MOD 1000000007
#define PB push_back
typedef long long ll;

int T, N;
string a, b, p, q;
tuple<ll, ll, ll> ans;
ll po[19];

ll conv (string x) {
	ll ret = 0;
	fo(i, (int) x.size()) {
		ret += po[N - i - 1] * (x[i] - '0');
	}
	return ret;
}

ll d (ll v, ll pr) {
	return (v / po[N - pr - 1]) % 10;
}

int main () {
	fo(i, 19) po[i] = i ? po[i-1] * 10 : 1;
	cin >> T;
	for (int _ = 1; _ <= T; _++) {
		ans = make_tuple(MOD, MOD, MOD);
		cin >> a >> b; N = (int) a.size();
		p = a, q = b;

		bool same = 1;
		fo(x, N) if (a[x] != '?' && b[x] != '?' && a[x] != b[x]) same = 0;
		if (same) {
			fo(x, N) {
				if (a[x] == '?' && b[x] == '?') a[x] = b[x] = '0';
				else if (a[x] == '?') a[x] = b[x];
				else if (b[x] == '?') b[x] = a[x];
			}
			ans = min(ans, make_tuple(0ll, conv(a), conv(b)));
			goto skip;
		}

		fo(i, N) {
			bool can = 1;
			//make this digit purposely smaller on a
			fo(j, i) {
				if (a[j] != '?' && b[j] != '?' && a[j] != b[j]) can = 0;
			}

			if (b[i] == '0') can = 0;
			if (a[i] == '9') can = 0;
			if (b[i] != '?' && a[i] != '?' && a[i] >= b[i]) can = 0;

			if (!can) continue;
			//make this digit one smaller on a
			fo(j, i) {
				if (a[j] == '?' && b[j] == '?') a[j] = b[j] = '0';
				else if (a[j] == '?') a[j] = b[j];
				else if (b[j] == '?') b[j] = a[j];
			}
			if (a[i] == '?' && b[i] == '?') a[i] = '0', b[i] = '1';
			else if (a[i] == '?') a[i] = (char) b[i] - 1;
			else if (b[i] == '?') b[i] = (char) a[i] + 1;
			//the rest, maximise a, minimise b
			for (int j = i+1; j < N; j++) {
				if (a[j] == '?') a[j] = '9';
				if (b[j] == '?') b[j] = '0';
			}
			//cout << a << " " << b << endl;
			ll A = conv(a), B = conv(b);
			ans = min(ans, make_tuple(abs(A-B), A, B));
			a = p, b = q;
		}

		a = q, b = p;
		fo(i, N) {
			bool can = 1;
			//make this digit purposely smaller on a
			fo(j, i) {
				if (a[j] != '?' && b[j] != '?' && a[j] != b[j]) can = 0;
			}

			if (b[i] == '0') can = 0;
			if (a[i] == '9') can = 0;
			if (b[i] != '?' && a[i] != '?' && a[i] >= b[i]) can = 0;

			if (!can) continue;
			//make this digit one smaller on a
			fo(j, i) {
				if (a[j] == '?' && b[j] == '?') a[j] = b[j] = '0';
				else if (a[j] == '?') a[j] = b[j];
				else if (b[j] == '?') b[j] = a[j];
			}
			if (a[i] == '?' && b[i] == '?') a[i] = '0', b[i] = '1';
			else if (a[i] == '?') a[i] = (char) b[i] - 1;
			else if (b[i] == '?') b[i] = (char) a[i] + 1;
			//the rest, maximise a, minimise b
			for (int j = i+1; j < N; j++) {
				if (a[j] == '?') a[j] = '9';
				if (b[j] == '?') b[j] = '0';
			}
			//cout << a << " " << b << endl;
			ll A = conv(a), B = conv(b);
			ans = min(ans, make_tuple(abs(A-B), B, A));
			a = q, b = p;
		}

skip:;
	 fo(x, N) a[x] = (char) '0' + (int) d(get<1>(ans), x);
	 fo(x, N) b[x] = (char) '0' + (int) d(get<2>(ans), x);
	 printf("Case #%d: ", _);
	 cout << a << " " << b << '\n';
	}
	return 0;
}
