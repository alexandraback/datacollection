#include <bits/stdc++.h>
using namespace std;


int get(char c) {
	if (c == '?')
		return 10;
	return c - '0';
}
string s1, s2;
vector<string> mem[20];
int vis[20];
int id;
void append(int x, string &s) {
	char c = '0' + x;
	s = c + s;
}

long long get(string s) {
	long long ret = 0;
	for (int i = 0; i < int(s.size()); i++)
		ret = ret * 10LL + (s[i] - '0');
	return ret;
}

vector<string> minimize(vector<string> v1, vector<string> v2) {
	if (v2.empty())
		return v1;
	long long x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	x1 = get(v1[0]);
	y1 = get(v1[1]);
	x2 = get(v2[0]);
	y2 = get(v2[1]);
	if (abs(x1 - y1) < abs(x2 - y2))
		return v1;
	else if (abs(x2 - y2) < abs(x1 - y1))
		return v2;
	if (x1 < x2)
		return v1;
	else if (x2 < x1)
		return v2;
	if (y1 < y2)
		return v1;
	else
		return v2;
}

vector<string> solveMax(int ind, int dir) {

	vector<string> ret(2, "");
	if (dir == 1) {
		for (int i = ind; i < int(s1.size()); i++)
			ret[0] += s1[i] == '?' ? '9' : s1[i];
		for (int i = ind; i < int(s2.size()); i++)
			ret[1] += s2[i] == '?' ? '0' : s2[i];
	}

	else {
		for (int i = ind; i < int(s1.size()); i++)
			ret[0] += s1[i] == '?' ? '0' : s1[i];
		for (int i = ind; i < int(s2.size()); i++)
			ret[1] += s2[i] == '?' ? '9' : s2[i];
	}
	return ret;
}


vector<string> solveMin(int ind) {
	if (ind >= int(s1.size()))
		return vector<string>(2, "");
	if (vis[ind] == id)
		return mem[ind];
	vis[ind] = id;
	vector<string> ret;
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			int cur1 = get(s1[ind]);
			int cur2 = get(s2[ind]);
			if (cur1 != 10 && cur1 != x)
				continue;
			if (cur2 != 10 && cur2 != y)
				continue;
			vector<string> tmp;
			if (x == y)
				tmp = solveMin(ind + 1);
			else if (x > y)
				tmp = solveMax(ind + 1, -1);
			else
				tmp = solveMax(ind + 1, 1);
			append(x, tmp[0]);
			append(y, tmp[1]);
			ret = minimize(tmp, ret);
		}
	}
	return mem[ind] = ret;
}




int main() {
	ios::sync_with_stdio(false);
	freopen("/home/ahmed/Desktop/GCJ_1B/B/B-small-attempt2.in", "r", stdin);
	freopen("/home/ahmed/Desktop/GCJ_1B/B/B-small-attempt2.out", "w", stdout);
	int t; cin >> t;
	while (t--) {
		cin >> s1 >> s2;
		id++;
		vector<string> res = solveMin(0);

		cout << "Case #" << (id) << ": " << res[0] << " " << res[1] << endl;
	}

	return 0;
}
