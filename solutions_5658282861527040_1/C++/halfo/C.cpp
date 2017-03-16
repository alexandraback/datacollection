/* in the name of ALLAH, most gracious, most merciful */
#include <bits/stdc++.h>

typedef long long int64;
using namespace std;

vector <int> a, b, k;

bool seen [50][2][2][2];
int64 dp [50][2][2][2];

int64 cherry (int pos, bool pa, bool pb, bool pk) {
//	cout << pos << " " << pa << " " << pb << " " << pk << endl;
	if (pos >= 34) return (pa && pb && pk);
	int64 &ret = dp [pos][pa][pb][pk];

	if (seen [pos][pa][pb][pk])
		return ret;

	ret = 0LL;
	seen [pos][pa][pb][pk] = true;

	int ma = pa ? 1 : a [pos];
	int mb = pb ? 1 : b [pos];

	for (int i = 0; i <= ma; ++i) {
		for (int j = 0; j <= mb; ++j) {
			int mk = i & j;
			if (!pk && (mk > k [pos]))
				continue;

//			cout << i << " " << j << " " << (i & j) << endl;
			ret += cherry (pos + 1,
						   pa ? 1 : (i < ma),
						   pb ? 1 : (j < mb),
						   pk ? 1 : ((i & j) < k [pos]));
		}
	}

	return ret;
}

vector <int> process (int64 x) {
	vector <int> v;
	for (int64 i = 0; i < 34; ++i) {
		if (x & (1LL <<i)) v.push_back (1);
		else v.push_back (0);
	}
		
	reverse (v.begin (), v.end ());
	return v;
}

int main () {
#ifdef Local
	freopen ("B-large.in", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;

	for (int cs = 1; cs <= t; ++cs) {
		int64 A, B, K;
		cin >> A >> B >> K;

		a = process (A);
		b = process (B);
		k = process (K);
		memset (seen, 0, sizeof seen);

		cout << "Case #" << cs << ": " << cherry (0, 0, 0, 0) << endl;
	}

	return 0;
}

