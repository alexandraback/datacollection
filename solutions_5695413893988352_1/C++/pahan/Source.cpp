#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<iomanip>
#include<unordered_set>
#include<unordered_map>
#include<ctime>
#include<cstdlib>
#include<climits>
#include<string>
#include<cstring>
using namespace std;
using ll = long long;

int code(char c) {
	return c - '0';
}

pair<string,string> maxrise(string c, string j) {
	for (int i = 0; i < c.size(); i++) {
		if (c[i] == '?')
			c[i] = '0';
		if (j[i] == '?')
			j[i] = '9';
	}
	return {c, j};
}

int calcdiff(pair<string,string> t) {
	int r = 0;
	for (int i = 0; i < t.first.size(); i++)
		r = r * 10 + (t.first[i] - t.second[i]);
	return abs(r);
}

pair<string,string> solve(string c, string j) {
	int pr = 0;
	int n = c.size();
	while (pr < n && c[pr] != '?' && c[pr] != '?' && c[pr] == j[pr])
		pr++;
	if (pr == n)
		return {c, j};
	if (c[pr] != '?' && j[pr] != '?') {
		if (j[pr] < c[pr]) {
			pair<string,string> t = maxrise(c.substr(pr+1, n-pr-1), j.substr(pr+1, n-pr-1));
			return {c.substr(0, pr+1)+t.first, j.substr(0, pr+1)+t.second};
		} else {
			pair<string,string> t = maxrise(j.substr(pr+1, n-pr-1), c.substr(pr+1, n-pr-1));
			return {c.substr(0, pr+1)+t.second, j.substr(0, pr+1)+t.first};
		}
	}
	vector<pair<int,pair<string,string>>> solves;
	if (c[pr] != '?') {
		if (c[pr] == '9') {
			j[pr] = '9';
			pair<string,string> a = solve(c.substr(pr, n-pr), j.substr(pr, n-pr));
			j[pr] = '8';
			pair<string,string> b = maxrise(c.substr(pr, n-pr), j.substr(pr, n-pr));
			solves.push_back({calcdiff(a), a});
			solves.push_back({calcdiff(b), b});
		} else if (c[pr] == '0') {
			j[pr] = '0';
			pair<string,string> a = solve(c.substr(pr, n-pr), j.substr(pr, n-pr));
			j[pr] = '1';
			pair<string,string> b = maxrise(j.substr(pr, n-pr), c.substr(pr, n-pr));
			swap(b.first, b.second);
			solves.push_back({calcdiff(a), a});
			solves.push_back({calcdiff(b), b});
		} else {
			j[pr] = c[pr];
			pair<string,string> a = solve(c.substr(pr, n-pr), j.substr(pr, n-pr));
			j[pr] = c[pr]+1;
			pair<string,string> b = maxrise(j.substr(pr, n-pr), c.substr(pr, n-pr));
			swap(b.first, b.second);
			j[pr] = c[pr]-1;
			pair<string,string> k = maxrise(c.substr(pr, n-pr), j.substr(pr, n-pr));
			solves.push_back({calcdiff(a), a});
			solves.push_back({calcdiff(b), b});
			solves.push_back({calcdiff(k), k});
		}
	} else if (j[pr] != '?') {
		if (j[pr] == '9') {
			c[pr] = '9';
			pair<string,string> a = solve(c.substr(pr, n-pr), j.substr(pr, n-pr));
			c[pr] = '8';
			pair<string,string> b = maxrise(j.substr(pr, n-pr), c.substr(pr, n-pr));
			swap(b.first, b.second);
			solves.push_back({calcdiff(a), a});
			solves.push_back({calcdiff(b), b});
		} else if (j[pr] == '0') {
			c[pr] = '0';
			pair<string,string> a = solve(c.substr(pr, n-pr), j.substr(pr, n-pr));
			c[pr] = '1';
			pair<string,string> b = maxrise(c.substr(pr, n-pr), j.substr(pr, n-pr));
			solves.push_back({calcdiff(a), a});
			solves.push_back({calcdiff(b), b});
		} else {
			c[pr] = j[pr];
			pair<string,string> a = solve(c.substr(pr, n-pr), j.substr(pr, n-pr));
			c[pr] = j[pr]-1;
			pair<string,string> b = maxrise(j.substr(pr, n-pr), c.substr(pr, n-pr));
			swap(b.first, b.second);
			c[pr] = j[pr]+1;
			pair<string,string> k = maxrise(c.substr(pr, n-pr), j.substr(pr, n-pr));
			solves.push_back({calcdiff(a), a});
			solves.push_back({calcdiff(b), b});
			solves.push_back({calcdiff(k), k});
		}
	} else {
		c[pr] = '0';
		j[pr] = '0';
		pair<string,string> a = solve(c.substr(pr, n-pr), j.substr(pr, n-pr));
		c[pr] = '0';
		j[pr] = '1';
		pair<string,string> b = maxrise(j.substr(pr, n-pr), c.substr(pr, n-pr));
		swap(b.first, b.second);
		c[pr] = '1';
		j[pr] = '0';
		pair<string,string> k = maxrise(c.substr(pr, n-pr), j.substr(pr, n-pr));
		solves.push_back({calcdiff(a), a});
		solves.push_back({calcdiff(b), b});
		solves.push_back({calcdiff(k), k});
	}
	sort(solves.begin(), solves.end());
	return {c.substr(0, pr) + solves[0].second.first, j.substr(0, pr) + solves[0].second.second};
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	srand(time(NULL));

	int tnumber;
	cin >> tnumber;
	for (int tcase = 1; tcase <= tnumber; tcase++) {
		cout << "Case #" << tcase << ": ";
		string c, j;
		cin >> c >> j;
		pair<string,string> p = solve(c, j);
		cout << p.first << ' ' << p.second;
		cout << endl;
	}

	return 0;
}