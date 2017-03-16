#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <functional>
#include <numeric>
#include <climits>
#include <cassert>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);++i)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);++i)
#define forall(i,c) for(typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define dforn(i,n) for(int i=((int)(n)-1);i>=0;--i)
#define dforsn(i,s,n) for(int i=((int)(n)-1);i>=(int)(s);--i)
#define all(v) (v).begin(),(v).end()
#define dbg(x) cerr << #x << " = " << x << endl
#define raya cerr << "=============================================" << endl

typedef long long tint;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< pii > vii;

int dy[] = {-1,0,0,1};
int dx[] = {0,-1,1,0};
char letters[] = { 'S','W','E','N' };
int main()
{
	int tests; cin >> tests;
	forsn(test,1,tests+1){
		string res = "";
		int x,y; cin >> x >> y;

		map< pii, pii> d;
		queue< pair<int,pii> > q;
		q.push(make_pair(1,make_pair(0,0)));
		d[make_pair(0,0)] = make_pair(0,0);
		while(!q.empty()){
			pair<int,pii> pp = q.front(); q.pop();
			if(pp.first > 500) break;	
			int pj = pp.first;
			pii	pos = pp.second;
			if(pos == make_pair(x,y)) 
				break;
			for(int dir = 0; dir < 4; dir++){
				pii np = make_pair(pos.first+dx[dir]*pj,
							pos.second+dy[dir]*pj);
				if(d.find(np) == d.end()){
					d[np] = make_pair(3-dir,pj);
					q.push(make_pair(pj+1,np));
				}
			}
		}
		int px = x, py = y;
		while(true){
			if(px == 0 && py == 0) break;
			pii pp = d[make_pair(px,py)];
			int dir = pp.first;int pj = pp.second;
			res += letters[3-dir];
			px = px + dx[dir]*pj;
			py = py + dy[dir]*pj;
		}
		reverse(all(res));
		px = 0, py = 0;
		forn(i,res.size()){
			char dir = res[i];
			int l; for(l = 0; l < 4; l++) if(letters[l] == dir) break;
			px += (i+1)*dx[l], py += (i+1)*dy[l];
		}
		assert(px == x && py == y);
		cout << "Case #" << test << ": " << res << endl;
	}
	return 0;
}
