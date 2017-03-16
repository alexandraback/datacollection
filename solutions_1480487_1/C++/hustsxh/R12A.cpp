#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

#define N 1000010

using namespace std;

struct Node {
	double p;
	double need;
	int id;
	Node() {
		need = 0;
	}
	static bool byP(const Node& a, const Node& b) {
		return a.p < b.p;
	}
	static bool byId(const Node& a, const Node& b) {
		return a.id < b.id;
	}
};

int main(int argc, char *argv[]) 
{
	freopen("A-large.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int T;
	cin >> T;
	for(int testcase = 1; testcase <= T; ++testcase) {
		cout << "Case #" << testcase << ":";
		int n;
		double sum = 0, s[200];
		Node node[200];
		cin >> n;
		for(int i = 0; i < n; ++i) {
			cin >> s[i];
			sum += s[i];
		}
		for(int i = 0; i < n; ++i) {
			node[i].id = i, node[i].p = s[i] / sum;
		}
		sort(node, node + n, Node::byP);
		int k = n;
		double s_need;
		do {
			--k;
			s_need = 0;
			for(int i = 0; i < k; ++i) {
				s_need += node[k].p - node[i].p;
			}
		} while(s_need > 1.0);
		double to = (1 - s_need) / (k + 1) + node[k].p;
		for(int i = 0; i <= k; ++i) {
			node[i].need = (to - node[i].p) * 100;
		}
		sort(node, node + n, Node::byId);
		for(int i = 0; i < n; ++i) {
			cout << " " << node[i].need;
		}
		cout << endl;
	}
	return 0;
}
