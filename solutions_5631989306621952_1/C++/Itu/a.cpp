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
#define sz(v) ((int)v.size())
typedef vector<int> vi;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int tc;
string s;
int n;
deque<char> d;

int main(){
	fast_io();
	cin >> tc;
	REP(q,1,tc+1){
		cout << "Case #" << q << ": ";
		cin >> s;
		n = sz(s);
		d.clear();

		d.pb(s[0]);
		REP(i,1,n){
			if (s[i] >= d.front()) d.push_front(s[i]);
			else d.pb(s[i]);
		}
		REPIT(it,d) cout << *it;
		cout << endl;
	}
	return 0;
}

