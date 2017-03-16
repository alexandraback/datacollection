#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 20;

int t;
char s1[MAXN], s2[MAXN];

map<pair<int, ll>, pii> mem;

ll s10[MAXN];

int add(pair<ll, int> key, pii val) {
 	if (!mem.count(key)) {
 	 	mem[key] = val;
 	} else {
 	 	mem[key] = min(mem[key], val);
 	}
 	return 0;
}

int main() {
	s10[0] = 1;
	for (int i = 1; i < MAXN; ++i) {
	 	s10[i] = s10[i - 1] * 10;
	}
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d", &t);

	for (int tn = 0; tn < t; ++tn) {
		mem.clear();
	 	scanf("%s%s", s1, s2);
	 	int l = strlen(s1);

	 	set<ll> d;
	 	d.insert(0);
	 	ll now = 1;
	 	for (int i = l - 1; i >= 0; --i) {
	 		set<ll> nd;
	 	 	if (s1[i] != '?' && s2[i] != '?') {
	 	 		ll tmp = ((int) (s1[i] - '0') - (int) (s2[i] - '0')) * now;
	 	 	 	for (ll num: d) {
	 	 	 	 	nd.insert(num + tmp);
	 	 	 	 	add({i, num + tmp}, {(s1[i] - '0'), (s2[i] - '0')});
	 	 	 	}
	 	 	} else if (s2[i] != '?') {
	 	 	 	for (int j = 0; j < 10; ++j) {
	 	 	 	 	ll tmp = (j - (int) (s2[i] - '0')) * now;
	 	 	 	 	for (ll num: d) {
	 	 	 	 	 	nd.insert(tmp + num);
	 	 	 	 	 	add({i, num + tmp}, {j, (s2[i] - '0')});
	 	 	 	 	}
	 	 	 	} 
	 	 	} else if (s1[i] != '?') {
	 	 	 	for (int j = 0; j < 10; ++j) {
	 	 	 	 	ll tmp = ((int) (s1[i] - '0') - j) * now;
	 	 	 	 	for (ll num: d) {
	 	 	 	 	 	nd.insert(tmp + num);
	 	 	 	 	 	add({i, num + tmp}, {(s1[i] - '0'), j});
	 	 	 	 	}
	 	 	 	}
	 	 	} else {
	 	 	 	for (int j = 0; j < 10; ++j) {
	 	 	 	 	for (int k = 0; k < 10; ++k) {
	 	 	 	 		ll tmp = (j - k) * now;
	 	 	 	 	 	for (ll num: d) {
	 	 	 	 	 	 	nd.insert(num + tmp);
	 	 	 	 	 	 	add({i, num + tmp}, {j, k});
	 	 	 	 	 	}
	 	 	 	 	}
	 	 	 	}
	 	 	}

	 	 	d.clear();

	 	 	if (*nd.begin() <= 0) {
	 	 	 	d.insert(*nd.begin());
	 	 	}

	 	 	auto tmp = nd.end();
	 	 	--tmp;

	 	 	if (*tmp >= 0) {
	 	 	 	d.insert(*tmp);
	 	 	}

	 	 	tmp = nd.lower_bound(0);

	 	 	if (tmp != nd.end()) {
	 	 	 	d.insert(*tmp);
	 	 	}

	 	 	if (tmp != nd.begin()) {
	 	 	 	--tmp;
	 	 	 	d.insert(*tmp);
	 	 	}

	 	 	now *= 10;
	 	}

	 	ll ans = 9e18;
	 	string n1, n2;

	 	for (ll num: d) {
	 		ll nowv = num;
	 		string nn1;
	 		string nn2;
    	 	for (int i = 0; i < l; ++i) {
    	 	 	pii tmp = mem[{i, nowv}];
    	 	 	nn1 += (char) (tmp.ff + '0');
    	 	 	nn2 += (char) (tmp.ss + '0');
    	 	 	nowv -= (tmp.ff - tmp.ss) * s10[l - i - 1];
    	 	}
    	 	if (abs(ans) > abs(num) || (abs(ans) == abs(num) && n1 > nn1) || (abs(ans) == abs(num) && n1 == nn1 && n2 > nn2)) {
    	 	 	ans = num;
    	 	 	n1 = nn1;
    	 	 	n2 = nn2;
    	 	}
	 	}

	 	cout << "Case #" << tn + 1 << ": " << n1 << " " << n2 << "\n";
	}  

	return 0;
}