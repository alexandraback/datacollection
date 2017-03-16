#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <functional>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std; 

typedef vector<int> VI; 
#define i64 long long 
#define pii pair<int,int>
#define mp make_pair
#define ALL(x) (x).begin(), (x).end() 
#define REP(i,n) for(int i = 0;i<(int)n;++i)
#define x first
#define y second

const int NMAX = 102, hmax = 100;
int T;
int N, M;
int A[NMAX][NMAX];
const string states[] = {"NO","YES"};
set< pii > s[NMAX];
bool used[2][NMAX];

void readData() {
	cin>>N>>M;
	REP(i,N) {
		REP(j,M) {
			cin>>A[i][j];
		}
	}
}

void solve(int t) {
	bool isPossible = true;
	memset(used,0,sizeof(used));
	if(N > 1 && M > 1) {
		REP(i,N) {
			REP(j,M) {
				s[A[i][j]].insert(mp(i,j));
			}
		}
		for(int i = hmax;i >= 1;i--) {
			if(!s[i].empty() && isPossible) {
				for(set< pii >::iterator it = s[i].begin();it != s[i].end();++it) {
					if(used[0][it->x] && used[1][it->y]) {
						isPossible = false;
					}
				}
				for(set< pii >::iterator it = s[i].begin();it != s[i].end();++it) {
					used[0][it->x] = used[1][it->y] = true;
				}
			}
			s[i].clear();
		}
	}
	cout<<"Case #"<<t<<": "<<states[isPossible]<<"\n";
}

int main()
{
	//freopen("test.in","r",stdin); freopen("test.out","w",stdout);cin.sync_with_stdio(false), cout.sync_with_stdio(false);
	cin>>T;
	REP(t,T) {
		readData();
		solve(t + 1);
	}
	return 0;
}
