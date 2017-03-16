
// Author: Tiago Togores

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(), (a).end()
#define CLR(a, x) memset(a, x, sizeof a)
#define REP(i, n) for (auto i = 0; i < (n); i++)
#define FORT(it, l) for (auto it = (l).begin(); it != (l).end(); it++)
#define READLINE(line) cin.getline((line), sizeof (line))
#define VALID(i, j, n, m) (0 <= (i) && (i) < (n) && 0 <= (j) && (j) < (m))
#define PI M_PI
#define EPSILON 1e-6
#define INF 1000000000
#define MOD 1000000007
#define endl '\n'
//NOTE: append ll to name if using long long
#define BITCOUNT __builtin_popcount
#define BITLEAD0 __builtin_clz
#define BITTRAIL0 __builtin_ctz
#define BITPARITY __builtin_parity

typedef unsigned int uint;
typedef long long int int64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

///////////////////////////////

int coins[5];
int c, d, v;
bitset<35> represented, represented_original, already, temp;
vi mycoins;

void init()
{
	
}

// bit 0 is the least significant bit
// the order is descending lexicographically
// to generate in ascending order, take 0 as present
inline uint next_permutation(uint v)
{/*
	unsigned int t = (v | (v - 1)) + 1;  
	return t | ((((t & -t) / (v & -v)) >> 1) - 1); */

	uint t = v | (v - 1); // t gets v's least significant 0 bits set to 1
	// Next set to 1 the most significant bit to change, 
	// set to 0 the least significant ones, and add the necessary 1 bits.
	return (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));  
}

int bruteforce()
{
	for (int i = 1; i <= min(7, v - d); i++) {
		int start = (1 << i) - 1;
		for (int j = start; j <= (start << (v - i)); j = next_permutation(j)) {
			represented.reset();
			mycoins.clear();
			int invalid = 0;
			REP (l, v)
				if ((j >> l) & 1) {
					mycoins.PB(l + 1);
					if (already[l + 1])
						invalid = 1;
				}
			if (invalid) continue;
			for (int k = 1; k < (1 << i); k++) {
				int value = 0;
				REP (l, i)
					if ((k >> l) & 1)
						value += mycoins[l];
				if (value <= v)
					represented[value] = 1;
			}
			temp.reset();
			REP (a, v)
				REP (b, v)
					if (a + b + 2 <= v && represented_original[a + 1] && represented[b + 1])
						temp[a + b + 2] = 1;
			int is_good = 1;
			for (int i = 1; i <= v && is_good; i++)
				if (!temp[i] && !represented_original[i] && !represented[i])
					is_good = 0;
			if (is_good)
				return i;
		}
	}
	return 7;
}

void solve()
{
	cin >> c >> d >> v;
	already.reset();
	REP (i, d) {
		cin >> coins[i];
		already[coins[i]] = 1;
	}
	represented_original.reset();
	for (int i = 1; i < (1 << d); i++) {
		int value = 0;
		REP (j, d)
			if ((i >> j) & 1)
				value += coins[j];
		if (value <= v)
			represented_original[value] = 1;
	}
	int is_good = 1;
	for (int i = 1; i <= v && is_good; i++)
		if (!represented_original[i])
			is_good = 0;
	int ans = 0;
	if (!is_good) {
		ans = bruteforce();
	}
	cout << ans;
}

int main()
{ _
	init();
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ": ";
		solve();
		cout << endl;
	}
	return 0;
}
