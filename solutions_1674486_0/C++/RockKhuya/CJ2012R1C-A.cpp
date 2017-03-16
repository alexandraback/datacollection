#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define LL long long
#define zero(a) fabs(a)<1e-9
#define resz(a,n) a.clear(),a.resize(n)
#define same(a,n) memset(a,n,sizeof(a))
#define make(a,b) make_pair(a,b)
#define rep(i,a) for(int i=0;i<int(a);i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)

vector<vector<int> > G;
vector<int> node;

bool loang(int x) {
	int vt, k;
	int dd[1010];
	same(dd,0);
	vector<int> q;
	q.clear();

	vt = 0;
	q.push_back(x);
	dd[x] = 1;
	while(vt < q.size()) {
		k = q[vt];
		vt++;
		rep(i,G[k].size()) {
			if (G[k][i]>=0 && dd[G[k][i]]==0) {
				q.push_back(G[k][i]);
				dd[G[k][i]] = 1;
			}
			else {
				if (G[k][i]>=0 && dd[G[k][i]] == 1 )
					return true;
			}
		}
	}
	return false;
}


int main() {
	int test_num, test_id;
	string ans, str;
	int N, temp, M, d[1001], sum;

	ifstream ifs("A-small-attempt1.in");
	ofstream ofs("A-small-attempt1.out");

	ifs >> test_num;

	for(test_id = 1; test_id <= test_num; ++test_id) {
		ifs >> N;
		G.clear();
		same(d,0);
		sum = 0;
		// input
		rep(i,N) {
			ifs >> M;
			node.clear();
			sum += M;
			rep(j, M) {
				ifs >> temp;
				node.push_back(temp-1);
			}
			G.push_back(node);
		}
		bool ok = false;
		rep(i,N){
			if (loang(i)) {
					ofs << "Case #" << test_id << ": " << "YES" << endl;
					ok = true;
					break;
			}
		}
		if (!ok)
		ofs << "Case #" << test_id << ": " << "NO" << endl;
	}
	return 0;
}
