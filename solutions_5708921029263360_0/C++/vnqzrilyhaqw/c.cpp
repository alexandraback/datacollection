#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using piii = pair<int, pii>;

struct Node {
	int j, p, s;
};

void single_test() {
	unordered_set<int> visited;
	int cjs[4][4] = {0};	
	int cps[4][4] = {0};
	int j, p, s, k;
	cin >> j >> p >> s >> k;
	vector<piii> q;
	for(int i0=1; i0<=j; ++i0) {
		for(int i1=1; i1<=p; ++i1) {
			q.push_back(piii{0, pii{i0, i1}});
		}
	}
	vector<Node> nodes;
	int prev = -1;
	while( (int)nodes.size() != prev ) {
		prev = nodes.size();
		sort(q.begin(), q.end());
		bool done = false;
		for(piii& c : q) {
			if(c.first==k) {
				done = true;
				break;
			}
			vector<pii> q;
			int i0 = c.second.first;
			int i1 = c.second.second;
			for(int i2=1; i2<=s; ++i2) {
				if(cjs[i0][i2]<k && cps[i1][i2]<k) {
					int hash = i0 + (i1<<8) + (i2<<16);
					auto ins = visited.insert(hash);
					if(ins.second==true) {
						++c.first;
						++cjs[i0][i2];
						++cps[i1][i2];
						nodes.push_back(Node{i0, i1, i2});
						done = true;
						break;
					}
				}
			}
			if(done) {
				break;
			}			
		}
	}
	cout << nodes.size() << endl;
	for(Node& node: nodes) {
		cout << node.j << ' ' << node.p << ' ' << node.s << endl;
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	int t;
	cin >> t;
	for(int i=1; i<=t; ++i) {
		cout << "Case #" << i << ": ";
		single_test();
	}
	return 0;
}
