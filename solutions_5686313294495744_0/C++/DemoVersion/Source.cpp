#include<iostream>
#include<iomanip>
#include<queue>
#include<stack>
#include<sstream>
#include<algorithm>
#include<list>
#include<map>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<set>
#include<fstream>

#define Author "DemoVersion"
#define DBG(x) cout<<#x<<" = "<<x<<";\n"


using namespace std;
int dx[] = { 0,0,-1,1,1,-1,1,-1 };
int dy[] = { 1,-1,0,0,1,1,-1,-1 };
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

map<string, int> m1, m2;
int get1id(string &s) {
	if (m1.count(s)) {
		return m1[s];
	}
	else {
		int id = m1.size();
		m1[s] = id;
		return id;
	}
}
int get2id(string &s) {
	if (m2.count(s)) {
		return m2[s];
	}
	else {
		int id = m2.size();
		m2[s] = id;
		return id;
	}
}
vector<int> adj1[1010];
vector<int> adj2[1010];
int solve(vector<string> &vs1, vector<string> &vs2) {
	m1.clear();
	m2.clear();
	int j,i,id1,id2;
	for (i = 0;i < 1010;i++) {
		adj1[i].clear();
		adj2[i].clear();
	}
	for (i = 0;i < vs1.size();i++) {
		id1 = get1id(vs1[i]);
		id2 = get2id(vs2[i]);
		adj1[id1].push_back(id2);
		adj2[id2].push_back(id1);
	}
	int cnt=0,mm,mm2;
	for (i = 0;i < 1010;i++) {
		mm = adj1[i].size();
		mm2 = 0;
		for (j = 0;j < adj1[i].size();j++) {
			
			if (adj2[adj1[i][j]].size()>1) {
				mm2 = max(int( adj2[adj1[i][j]].size()), mm2);
			}
		}
		if (min(mm, mm2)>0) {
			cnt += min(mm, mm2) - 1;
		}
	}
	return cnt;
}
int main() {
	int n,i,T,test;
	vector<string> vs1, vs2;
	string S1,S2;
	cin >> T;
	for (test = 1;test <= T;test++) {
		cin >> n;
		vs1.clear();
		vs2.clear();
		for (i = 0;i < n;i++) {
			cin >> S1 >> S2;
			vs1.push_back(S1);
			vs2.push_back(S2);
		}
		cout << "Case #" << test << ": " << solve(vs1,vs2) << endl;
	}
	return 0;
}
