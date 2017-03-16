#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }

const int INF = 1 << 29;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while (n && ++res) n -= n&(-n); return res; }

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
/////////////////////////////////////////////////////////////////////
#define MAX 1010

int nextp[MAX];
int prec[MAX][MAX];
int np[MAX];
bool visited[MAX];
bool marked[MAX];
int sizep[MAX];
int find_greatest_cycle(int n) {
	for (int i = 1; i <= n; i++) {
		visited[i] = false;
		marked[i] = false;
		sizep[i] = -1;
	}
	int ans=0;
	int cur_size;
	int w, u;
	for (int v = 1; v <= n; v++) {
		//if (!visited[v]) {
			//
			//cout << "we start at v = " << v << endl;
			w = v;
			while (sizep[w]==-1 && !visited[w]) {
				visited[w] = true;
				w = nextp[w];
			}
			//cout << "we got w = " << w << endl;
			if (sizep[w] != -1);
			else {
				u = nextp[w];
				cur_size = 1;
				while (u != w) {
					cur_size++;
					u = nextp[u];
				}
				if (cur_size > ans)
					ans = cur_size;
			}
			//cout << " got here " << endl;
			u = v;
			int count = 0;
			while (count < 2) {
				visited[u] = false;
				if(count>=1) sizep[u] = cur_size; // if we are already in the cycle
				u = nextp[u];
				if (u == w) count++;
			}
		//}
	}
	return ans;
}


void find_two_cycles(vector < pair<int, int> >&ans, int n) {
	for (int i = 1; i <= n; i++) {
		if (nextp[i]>i && nextp[nextp[i]] == i)
			ans.push_back(pair<int, int>(i, nextp[i]));
	}
}
int dep[MAX];
int extend(pair<int, int>tc) {
	//we do kinda a DFS
	int depth1 = 0;
	stack<int>mystack;
	mystack.push(tc.first);
	dep[tc.first] = 0;
	//cout << "1 - we search for the component of " << tc.first << endl;
	while (!mystack.empty()) {
		int cur = mystack.top();
		//cout << "we consider the element cur = " << cur << "whose depth is " << dep[cur] << ". depth1 is " << depth1 << endl;
		mystack.pop();
		for (int i = 0; i < np[cur]; i++) {
			if (prec[cur][i] != tc.second) {
				mystack.push(prec[cur][i]);
				dep[prec[cur][i]] = dep[cur] + 1;
				depth1 = max(depth1, dep[cur] + 1);
			}
		}
	}
	//cout << "2 - we search for the component of " << tc.second << endl;
	int depth2 = 0;
	mystack.push(tc.second);
	dep[tc.second] = 0;
	while (!mystack.empty()) {
		int cur = mystack.top();
		//cout << "we consider the element cur = " << cur << "whose depth is " << dep[cur] << ". depth2 is " << depth2 << endl;
		mystack.pop();
		for (int i = 0; i < np[cur]; i++) {
			if (prec[cur][i] != tc.first) {
				mystack.push(prec[cur][i]);
				dep[prec[cur][i]] = dep[cur] + 1;
				depth2 = max(depth2, dep[cur] + 1);
			}
		}
	}
	//cout << "we finally return " << depth1 + depth2 + 2 << endl;
	return depth1 + depth2 + 2;
}
int find_greatest_with_no_cycle(int n) {
	vector<pair<int, int> >v;
	find_two_cycles(v, n);
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		//cout << "we've got the pair (" << v[i].first << ", " << v[i].second << ")" << endl;
		sum += extend(v[i]);
	}
	return  sum;
}

int main()
{
	int T;
	cin >> T;
	int n;
	for (int ind = 0; ind < T; ind++) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			np[i] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> nextp[i];
			prec[nextp[i]][np[nextp[i]]] = i;
			np[nextp[i]]++;
		}
		
		cout << "Case #" << ind + 1 << ": ";
		cout << max(find_greatest_cycle(n), find_greatest_with_no_cycle(n)) << endl;
	}
	return 0;
}


