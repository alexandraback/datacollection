	
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (i = 0; i < (int)(n); ++i)
#define sz(v) ((v).size())
#define all(v) (v).begin(), (v).end()
#define sqr(x) ((x)*(x))
#define updMax(a, b) ((a) = max((a), (b)))
#define updMin(a, b) ((a) = min((a), (b)))

const int maxn = 20;

int s[maxn];
int n;

int s1, s2;
int mark[maxn];
int cnt[3];

bool rec(int pos)
{
	if (pos == 20) {
		if (s1 == s2 && cnt[1] != 0 && cnt[2] != 0) {
			int i;
			forn(i, n)
				if (mark[i] == 1)
					cout << s[i] << " ";
			cout << "\n";
			forn(i, n)
				if (mark[i] == 2)
					cout << s[i] << " ";
			cout << "\n";
			return true;
		} else
			return false;
	}
	int i;
	forn(i, 3) {
		mark[pos] = i;
		if (i == 1)
			s1 += s[pos];
		if (i == 2)
			s2 += s[pos];
		cnt[i]++;
		if (rec(pos + 1))
			return true;
		cnt[i]--;
		if (i == 1)
			s1 -= s[pos];
		if (i == 2)
			s2 -= s[pos];
	}
	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t, it, k, i;
	uint mask;
	scanf("%d", &t);
	forn(it, t) {
		cout << "Case #" << it + 1 << ":\n";
		scanf("%d", &n);
		forn(i, n)
			scanf("%d", &s[i]);
		memset(cnt, 0, sizeof(cnt));
		s1 = s2 = 0;
		if (!rec(0))
			cout << "Impossible" << "\n";
	}


	return 0;
}

