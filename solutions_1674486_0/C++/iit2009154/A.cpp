#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cstdio>

using namespace std;

bool is_path(vector<vector<int> > g,int i,int j)
{
	vector<int> q;
	vector<bool> is_ok(g.size(),true);
	int c=0;
	q.push_back(i);
	while (q.size()) {
		int cur = q[0];
		q.erase(q.begin());
		for (int k=0; k<(g[cur]).size(); k++) {
			if (g[cur][k]==j) {
				c++;
			} else if (is_ok[g[cur][k]]) {
				q.push_back(g[cur][k]);
				is_ok[g[cur][k]] = false;
			}
		}
	}
	if (c > 1) {
		return true;
	}
	return false;
}

void smain()
{
	int n,num,node;
	cin >> n;
	vector<int> t;
	vector<vector<int> > g(n,t);
	for (int i=0; i<n; i++) {
		cin >> num;
		for (int j=0; j<num; j++) {
			cin >> node;
			(g[i]).push_back(node-1);
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i!=j) {
				if (is_path(g,i,j)) {
					cout << "Yes";
					return;
				}
			}
		}
	}
	cout << "No";
}

int main()
{
	int t;
	cin >> t;
	for (int i=1; i<=t; i++) {
		printf("Case #%d: ",i);
		smain();
		cout << endl;
	}
	return 0;
}
