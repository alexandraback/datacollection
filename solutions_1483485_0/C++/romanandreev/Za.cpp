#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <climits>
#include <cstring>
#include <complex>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;


#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define x first
#define y second
#define y1 y1_gdssdfjsdgf
#define y0 y0_fsdjfsdogfs
#define ws ws_fdfsdfsdgfs
#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}

#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
#define problem_name "a"
string s;
vector<string> a, b;
char m[256];
int main(){
	#ifdef home
	assert(freopen(problem_name".out","wt",stdout));
	assert(freopen(problem_name".in","rt",stdin));
	#endif
	while(1) {
		cin>>s;
		if (s == "#") {
			break;
		}
		a.pb(s);
	}
	while(1) {
		cin>>s;
		if (s == "#") {
			break;
		}
		b.pb(s);
	}
	for (int i = 0; i < sz(a); i++) {
		for (int  j = 0; j < sz(a[i]); j++) {
			m[a[i][j]] = b[i][j];
		}
	}
	for (int i = 0; i < 26; i++) {
		cout<<(char)(i + 'a');
	}
	cout<<endl;
	for (int i = 0; i < 26; i++) {
		cout<<m[i + 'a'];
	}
		                       
	return 0;
}
