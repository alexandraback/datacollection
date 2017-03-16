#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i = (a); i != b; i++)
#define Rep(i,n) For(i,0,n)
#define debug(x) cout<<#x<<": "<<x<<endl
#define Pb push_back
#define Mp make_pair

template<class T>void show(T a,int n) {Rep(i,n)cout<<a[i]<<' ';cout<<endl;}
template<class T>void show(T a,int n,int m) {Rep(i,n){Rep(j,m)cout<<a[i][j]<<' ';cout<<endl;}}


int main() {
	int T;
	scanf("%d\n", &T);

	int n, tmp;
	vector<vector<int> > adj;
	vector<int> in, out;

	Rep(iT, T) {
		scanf("%d", &n);
		adj.resize(n);
		in.resize(n);
		fill(in.begin(), in.end(), 0);
		out.resize(n);
		Rep(i,n) {
			scanf("%d", &out[i]);
			adj[i].resize(out[i]);
			Rep(j, out[i]) {
				scanf("%d", &adj[i][j]);
				adj[i][j]--;
				in[adj[i][j]] ++;
			}
		}
		
		vector<int> st(n,0);

		bool found = false;
		Rep(i, n) {
			if (in[i] == 0) {
				fill(st.begin(), st.end(), 0);
				// bfs
				queue<int> qu;
				qu.push(i);
				st[i] = 1;
				while (!qu.empty()) {
					int top = qu.front();
					qu.pop();
					Rep(j, out[top]){
						if (st[adj[top][j]] > 0) {
							found = true;
							break;
						} else {
							st[adj[top][j]] = 1;
							qu.push(adj[top][j]);
						}
					}
					if (found) {
						break;
					}
				}
			}
			if (found) break;
		}

		printf("Case #%d: %s\n", iT+1, (found?"Yes":"No"));
	}
	return 0;
}
