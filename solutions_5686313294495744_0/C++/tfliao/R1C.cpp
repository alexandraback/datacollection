#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
struct Edge {
	int A, B;
	Edge(int a, int b) {
		A = a;
		B = b;
	}
};

vector<string> dictA, dictB;

int getIndex(string& key, vector<string>& dict)
{
	for (int i=0;i<dict.size();++i) {
		if (dict[i] == key) return i;
	}
	dict.push_back(key);
	return dict.size()-1;
}
vector<Edge> edges;

void input()
{
	dictA.clear();
	dictB.clear();
	edges.clear();
	
	string A, B;
	cin >> N;
	for (int i=0;i<N;++i) {
		cin >> A >> B;
		edges.push_back(Edge(getIndex(A, dictA), getIndex(B, dictB)));
	}
}

int solv()
{
	int ans = 0;
	for (int i=0;i<(1<<N);++i) {
		int cnt = 0;
		for (int j=0;j<N;++j) {
			if (i & (1<<j)) continue;
			
			bool a = false, b = false;
			for (int k=0;k<N;++k) {
				if (i & (1<<k)) {
					if (edges[k].A == edges[j].A) a = true;
					if (edges[k].B == edges[j].B) b = true;
				}
			}
			if (a && b) { cnt ++;
			}
		}
		if (ans < cnt) ans = cnt;
	}
	
	return ans;
}

int main()
{
	int T, nCase = 1;
	cin >> T;
	for (nCase = 1; nCase <= T; ++nCase) {
		input();
		
		printf("Case #%d: %d\n", nCase, solv());
	}
	
	return 0;
}