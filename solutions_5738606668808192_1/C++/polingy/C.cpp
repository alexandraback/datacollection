#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>

#include <iostream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <functional>
#include <algorithm>

#include <boost/multiprecision/cpp_int.hpp>

using namespace std;

typedef long long ll;
typedef boost::multiprecision::int128_t lll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int max_P = 1e8 + 10;

vector <int> primes;
int notPrime[max_P];

void seive(int N);
string sb2(ll base2);
vector <lll> allB(ll base2);
pair < int, vector<int> > coinJam(ll base2);

int main()
{
	seive(10);

	int N, J, T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> J;
		cout << "Case #" << tc << ":\n";
		for (ll i = 0; J && i < (1ll << (N - 2)); ++i) {
			ll act = (1ll << (N - 1)) + (i << 1) + 1;
			auto temp = coinJam(act);
			if (temp.first) {
				--J;
				auto ans = sb2(act);
				reverse(ans.begin(), ans.end());
				cerr << J << endl;
				cout << ans << ' ';
				for (auto i : temp.second) {
					cout << i << ' ';
				}
				cout << endl;
			}
		}
	}
}

void seive(int N)
{
	notPrime[0] = notPrime[1] = 1;
	for (int i = 2; i <= N; ++i)
		if (!notPrime[i]) {
			primes.push_back(i);
			for (ll j = i; j * i <= N; ++j)
				notPrime[j * i] = 1;
		}
}

vector <lll> allB(ll base2)
{
	string b2 = sb2(base2);
	vector <lll> ans;
	for (int i = 2; i <= 10; ++i) {
		lll curr = 0, rad = 1;
		for (auto &j : b2) {
			curr += (rad * (j - '0'));
			rad *= i;
		}
		ans.push_back(curr);
	}

	assert(ans[0] == base2);
	return ans;
}


string sb2(ll base2)
{
	string b2 = "";
	while(base2) {
		b2 += ((base2 & 1) + '0');
		base2 >>= 1;
	}
	return b2;
}

pair < int, vector<int> > coinJam(ll base2)
{
	vector <lll> cand = allB(base2);
	vector <ll> root;
	for (auto &i : cand) 
		root.push_back((ll)sqrt(i) + 1);
	vector <int> ans(9, -1);

	int mxA = 8, numA = 9;
	for (auto &i : primes) {
		if (i > root[mxA] || !numA)
			break;
		for (int j = 0; j < 9; ++j)
			if (i <= root[j] && cand[j] % i == 0 && ans[j] == -1) {
				--numA;
				ans[j] = i;
			}
		while(mxA >= 0 && ans[mxA] != -1)
			--mxA;
	}

	assert((numA == 0) == (mxA < 0));

	return {numA == 0, ans};
}
