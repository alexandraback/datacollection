#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <fstream>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <string.h>
#define rep(x,n) for(int x=0;x<n;++x)
#define rep1(i,s) for(int i = 0; i < (int)s.size(); ++i)
#define mem(a, b) memset(a, b, sizeof(a))

#define mp(x,y) make_pair(x,y)
#define getBit(code, i) (code & (1 << i))
#define setBit(code, i) (code | (1 << i))
#define xetBit(code, i) (code & ~(1 << i))
#define PI acos(-1.0)
#define oo (int)10e7
#define rdfile(x) freopen(x, "r", stdin)
#define wtfile(x) freopen(x, "w", stdout)
#define ll long long

using namespace std;

int T;

int X,Y;
int fStp;
map< pair<int,int>, char > V[505];

char dir[] = {'E','W','N','S'};
int dx[] = {+1,-1,0,0};
int dy[] = {0,0,+1,-1};
#define MX 25
void BFS() {
	queue< pair<int , pair<int, int> > > Q;
	Q.push(mp(0, mp(0,0)));
	V[0][mp(0,0)] = 'Z';
	int stp,x,y;
	while(!Q.empty()) {
		stp = Q.front().first + 1;
		x = Q.front().second.first;
		y = Q.front().second.second;
		if(stp > MX) {
			break;
		}
		Q.pop();
		int nx,ny;
		rep(i, 4) {
			nx = x + stp*dx[i];
			ny = y + stp*dy[i];
			if(V[stp].count(mp(nx,ny)))
				continue;
			V[stp][mp(nx,ny)] = dir[i];
			Q.push(mp(stp, mp(nx,ny)));
		}
	}
}


int main() {
	
	freopen("Text.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> T;
	BFS();
	rep(caseNum, T) {
		cin >> X >> Y;
		printf("Case #%d: ",caseNum+1);
		string res;
		char nw;
		bool fnd = false;
		for(int x=1;x<=MX;x++)if(V[x].count(mp(X,Y))) {
			fStp = x;
			fnd = true;
			break;
		}
		if(!fnd) {
			cout << "ERRRRRRRRROR";
			return 0;
		}
		while(true) {
			nw = V[fStp][mp(X,Y)];
			if(nw == 'Z')
				break;
			res += nw;
			rep(j, 4) {
				if(dir[j] == nw) {
					X -= fStp*dx[j];
					Y -= fStp*dy[j];
					break;
				}
			}
			fStp--;
		}
		reverse(res.begin(), res.end());
		cout << res << endl;

	}
}