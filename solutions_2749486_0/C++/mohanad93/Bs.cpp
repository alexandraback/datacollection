#include <iterator>
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <valarray>
#ifdef _MSC_VER
#include <hash_set>
#include <hash_map>
using namespace stdext;
#else
#include <ext/hash_set>
#include <ext/hash_map>
using namespace __gnu_cxx;
#endif
using namespace std;

#define SZ(v)                   (int)v.size()
#define FOR(i,a,b)				for(int i=(a);i<(b);++i)
#define rev(i,a,b)				for(int i=(b);i>=(a);--i)
#define sz(v)                   (int)v.size()
#define all(v)					v.begin(), v.end()
#define rall(v)					v.rbegin(), v.rend()
#define pb						push_back
#define mp						make_pair
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
const int OO = 1 << 28;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
#define Nd 0
#define Ed 1
#define Sd 2
#define Wd 3

int X,Y;

int vis[400][400][400];
struct state{
	int x,y,jum;
	string s;
};
string bfs(){
	memset(vis,0,sizeof vis);
	queue<state> q;
	state s = {200,200,1,""};
	vis[200][200][1]=1;
	q.push(s);
	while(!q.empty()){
		s = q.front();
		q.pop();
		FOR(d,0,4){
			state nw = {s.x+s.jum*dx[d],s.y+s.jum*dy[d],s.jum+1,s.s};
			if(d == Nd)
				nw.s+="N";
			else if (d == Ed)
				nw.s += "E";
			else if(d == Sd)
				nw.s += "S";
			else
				nw.s += "W";
			if(nw.x < 0 || nw.y<0 || nw.x >= 400 || nw.y >= 400 )
				continue;
			if(vis[nw.x][nw.y][nw.jum])
				continue;
			vis[nw.x][nw.y][nw.jum]=1;
			if(nw.x == X && nw.y == Y)
				return nw.s;
			q.push(nw);
		}
	}
	return "";
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "rt", stdin);
//		freopen("out.out", "wt", stdout);
#endif
	int t;
	cin >> t;
	t++;
	FOR(cs,1,t){
		cin >> X >> Y;
		X+=200;
		Y+=200;
		cout << "Case #" << cs << ": " << bfs() << "\n";
	}
	return 0;
}




