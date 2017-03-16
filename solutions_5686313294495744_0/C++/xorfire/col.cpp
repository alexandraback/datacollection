#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define int long long

#undef int
int main()
{
#define int long long
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cerr << "Executing Case #" << tt << "\n";
		int n; cin >> n;
		string aa[n], bb[n];
		for (int i = 0; i < n; i++)
			cin >> aa[i] >> bb[i];

		set <string> s;
		for (int i = 0; i < n; i++) s.insert(aa[i]);
		for (int i = 0; i < n; i++) s.insert(bb[i]);
		map <string, int> M;
		int ct = 1;
		for (string p : s) M[p] = ct++;

		int a[n], b[n];
		for (int i = 0; i < n; i++)
			a[i] = M[aa[i]], b[i] = M[bb[i]];

		int ret = 0;
		for (int msk = 0; msk < 1 << n; msk++)
		{
			set <int> fst, snd;
			for (int i = 0; i < n; i++)
				if (msk >> i & 1)
					fst.insert(a[i]), snd.insert(b[i]);

			bool can = true;
			for (int i = 0; i < n and can; i++)
				if (!(msk >> i & 1))
					if (!fst.count(a[i]) or !snd.count(b[i]))
						can = false;
			if (can) ret = max(ret, n - __builtin_popcountll(msk));
		}
		cout << "Case #" << tt << ": " << ret << "\n";
	}
	return 0;
}