#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>

 
using namespace std; 
 
typedef long long ll; 
typedef unsigned int uint; 
typedef unsigned long long ull; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-7;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;

const ll mod = 1000 * 1000 * 1000 + 7;

int n, m;
vector<pair<string, int> > zip;
vector<vector<int> > g;
string res;
vector<int> used;
vector<int> dused;
vector<int> uused;
vector<int> pr;
vector<set<int> > ss;
int num;
vector<int> nei;
vector<string> zipzip;

int dfs(int pos) {
	int res = 1;
	dused[pos] = 1;
	for (int i = 0; i < g[pos].size(); ++i) {
		int to = g[pos][i];
		if ((dused[to]) || (used[to]))
			continue;
		res += dfs(to);
	}
	return res;
}

int isPos(int pos, int to) {
	if (pos == -1)
		return -1;
	while(ss[pos].find(to) == ss[pos].end()) {
		--num;
		used[pos] = 1;
		int ok = isPos(pr[pos], to);
		if (ok >= 0)
			return ok;
		else {
			used[pos] = 0;
			++num;
			return -1;
		}
	}
	
	dused.assign(n, false);
	int num2 = dfs(pos);
	if (num == num2)
		return pos;
	else
		return -1;
}

void rec(int pos) {
	res += zipzip[pos];
	uused[pos] = 1;
	if (num == 0)
		return;
	for (int i = 0; i < g[pos].size(); ++i)
		nei[g[pos][i]] = 1;
	for (int i = 0; i < n; ++i) {
		int index = zip[i].second;
		if (uused[index])
			continue;
		if (nei[index] == 0)
			continue;
		int ok = isPos(pos, index);
		if (ok >= 0) {
			pr[index] = ok;
			rec(index);
			return;
		}
	}
}

string solve() {
	res = "";
	cin >> n >> m;
	zip.resize(n);
	pr.assign(n, -1);
	zipzip.resize(n);
	ss.clear();
	ss.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> zip[i].first;
		zip[i].second = i;
		zipzip[i] = zip[i].first;
	}
	sort(zip.begin(), zip.end());
	g.clear();
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
		ss[a].insert(b);
		ss[b].insert(a);
	}
	used.assign(n, false);
	uused.assign(n, false);
	num = n;
	nei.assign(n, 0);
	nei[zip[0].second] = 1;
	rec(zip[0].second);
	return res;
}


int main() {
	freopen("C-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tt;
	//scanf("%d\n", &tt);
	cin >> tt;
	for (int i = 0; i < tt; ++i) {
		if (i == 28) {
			cerr << "EWEW";
		}
		cout << "Case #" << i + 1 << ": " << solve() << endl;
		std::cerr << i << endl;
	}
	return 0;
}

