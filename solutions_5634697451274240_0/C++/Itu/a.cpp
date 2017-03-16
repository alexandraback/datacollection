#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(x) push_back(x)
#define REP(i,x,y) for(int (i)=(x);(i)<(y);(i)++)
#define REPIT(it,A) for(typeof(A.begin()) it = (A.begin()); it!=A.end();it++)
#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0); 
//#define NDEBUG 1
#define fst first
#define snd second
#define itm1 fst.fst
#define itm2 fst.snd
#define itm3 snd
#define mt(a,b,c) mp(mp(a,b),c)
#define sz(v) ((int)v.size())
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ii, int> tri;
typedef unsigned int ui;

int nc;
string s;

int main(){
	fast_io();
	cin >> nc;
	REP(tc,0,nc){
		cout << "Case #" << tc+1 << ": ";
		cin >> s;
		char p = 0;
		int cnt = 0;
		REP(i,0,sz(s)){
			if (s[i] != p) cnt++;
			p = s[i];
		}
		if (s[sz(s)-1] == '+') cnt--;
		cout << cnt << endl;
	}
	return 0;
}

