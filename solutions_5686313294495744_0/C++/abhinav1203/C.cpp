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
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
typedef long long ll;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
/////////////////////////////////////////////////////////////////////
char str1[1005][20], str2[1005][20];
bool visited[1005];
int main()
{
	int T, test, i, j, counter, N, k;
	int edge1Found, edge2Found;
	vector< pair<int, int> > numEdges;
	scanf("%d", &T);
	for (test=1; test<=T; test++) {
		scanf("%d", &N);
		for (i=0; i<N; i++) {
			scanf("%s %s", str1[i], str2[i]);
		}
		counter = 0;
		numEdges.clear();
		numEdges.resize(N);
		for (i=0; i<N; i++) {
			numEdges[i].second = i;
			numEdges[i].first = 0;
			for (j=0; j<N; j++) {
				if (i!=j && str1[i]==str1[j])numEdges[i].first++;
				if (i!=j && str2[i]==str2[j])numEdges[i].first++;
			}
		}
		sort(numEdges.begin(), numEdges.end(), greater< pair<int,int> >());
		memset(visited, false, sizeof(bool)*N);
		for (k=0; k<N; k++) {
			i = numEdges[k].second;
			edge1Found = edge2Found = -1;
			if (visited[i])continue;
			for (j=0; j<N; j++) {
				if (i!=j && strcmp(str1[i], str1[j])==0) {
					edge1Found = j;
				}
				if (i!=j && strcmp(str2[i], str2[j])==0) {
					edge2Found = j;
				}
				if (edge1Found!=-1 && edge2Found!=-1) {
					counter++;
					visited[edge1Found] = visited[edge2Found] = true;
					break;
				}
			}
		}
		printf("Case #%d: %d\n", test, counter);
	}
    return 0;
}