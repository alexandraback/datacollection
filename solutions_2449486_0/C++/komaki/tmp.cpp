#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <algorithm>
//#include <sys/time.h>
using namespace std;
#define li        long long int
#define rep(i,to) for(li i=0;i<((li)(to));++i)
#define pb        push_back
#define sz(v)     ((li)(v).size())
#define bit(n)    (1ll<<(li)(n))
#define all(vec)  (vec).begin(),(vec).end()
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define MP        make_pair
#define F         first
#define S         second


int main()
{
	li T;
	cin >> T;
	rep(step, T){
		li n, m;
		cin >> n >> m;
		vector<vector<li> > mp(n, vector<li>(m));
		rep(x, n)rep(y, m) cin >> mp[x][y];
		
		bool ok = true;
		while(true){
			li mini = mp[0][0];
			rep(x, n)rep(y, m) mini = min(mini, mp[x][y]);
			
			vector<vector<li> > used(n, vector<li>(m, 0));
			rep(x, n){ li cnt = 0; rep(y, m)if(mp[x][y] == mini) cnt++; if(cnt == m) rep(y, m) used[x][y] = true; }
			rep(y, m){ li cnt = 0; rep(x, n)if(mp[x][y] == mini) cnt++; if(cnt == n) rep(x, n) used[x][y] = true; }
			rep(x, n)rep(y, m)if(mp[x][y] == mini && !used[x][y]) ok = false;
			if(!ok) break;
			
			
			li next = bit(25);
			rep(x, n)rep(y, m)if(mp[x][y] != mini) next = min(next, mp[x][y]);
			if(next == bit(25)) break;
			rep(x, n)rep(y, m)if(mp[x][y] == mini) mp[x][y] = next;
		}
		cout << "Case #" << step + 1 << ": " << (ok ? "YES" : "NO") << endl;
	}
}


