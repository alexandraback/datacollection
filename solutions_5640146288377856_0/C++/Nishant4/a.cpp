#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector< vector<int> >
#define pi pair<int,int>
#define pb push_back
#define out(a) cout<<(a)<<'\n'
#define sz(c) (int)(c).size()
#define isBit(n,i) ( ((n) >> (i)) & 1 )
#define fill(arr, v) memset(arr, v, sizeof(arr))
template<typename t1, typename t2> ostream& operator <<(ostream& os, const pair<t1, t2>& a) {os << a.first << ' ' << a.second;return os;}
template<typename typ> void vout(vector<typ>& v){for(int vint=0;vint<sz(v);vint++){cout<<(v)[vint];if(vint==sz(v)-1) cout<<'\n';else cout<<' ';}}
template<typename typ> void arrout(typ* arr,int l){for(int i=0;i<l;i++){cout<<arr[i];if(i<l-1) cout <<' ';else cout<<'\n';}}

#ifdef DEBUG
	#define debug(args...)            {dbg,args; cerr<<'\n';}
#else
	#define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger{template<typename T> debugger& operator , (const T& v) {cerr<<v<<" ";return *this;}}dbg;

int main() {
	std::ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int t = 1 ; t <= T ; t++) {
		int r, c, w;
		cin >> r >> c >> w;
		int ans = (c / w) * r;

		if ( c % w == 0 ) {
			ans += w - 1;
		} else {
			ans += w;
		}
		printf("Case #%d: %d\n", t, ans);
	}
}