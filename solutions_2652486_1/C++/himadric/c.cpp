#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;
typedef vector<string> VS;

// Basic macros

#define st          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define fr(i,s,n)  	for(int i=s;i<(n);++i)
#define rep(i,n)    fr(i,0,n)
#define tr(i,x)     for(typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define pu          push_back
#define mp          make_pair
#define sz(x)       (int)(x.size())

int main() 
{
	int T;
	cin >> T;
	vector<int> v(4);
	map<int, set<string> > memo;
	for(v[0]=2; v[0]<6; ++v[0]) 
	for(v[1]=2; v[1]<6; ++v[1]) 
	for(v[2]=2; v[2]<6; ++v[2]) {
		rep(i, (1<<3)) {
			ostringstream oss;
			int prod = 1;
			oss << v[0] << v[1] << v[2];
			if (i&4) {
				prod *= v[0];
			}
			if (i&2) {
				prod *= v[1];
			}
			if (i&1) {
				prod *= v[2];
			}
			string str = oss.str();
			sort(all(str));
			memo[prod].insert(str);
		}
	}
	printf("Case #%d:\n", 1);
	int R, N, M, K;
	cin >> R >> N >> M >> K;
	rep(r, R) {
		map<string, int> guesses;
		rep(i, K) {
			int tmp;
			cin >> tmp;
			tr(j, memo[tmp]) {
				guesses[*j]++;	
			}
		}
		tr(i, guesses) {
			if (i->second == K) {
				cout << i->first << endl;
				break;
			}
		}
	}


	return 0;
}