// Standard I/O
#include <iostream>
#include <sstream>
#include <cstdio>
// Standard Library
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
// Template Class
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
// Container Control
#include <algorithm>

using namespace std;

#define rep( i, n ) for( int i = 0; i < n; ++i )
#define irep( i, n ) for( int i = n-1; i >= 0; --i )
#define reep( i, s, n ) for ( int i = s; i < n; ++i )
#define ireep( i, n, s ) for ( int i = n-1; i >= s; --i )
#define foreach(itr, x) for( typeof(x.begin()) itr = x.begin(); itr != x.end(); ++itr)

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all( v ) v.begin(), v.end()
#define fs first
#define sc second
#define vc vector

// for visualizer.html
double SCALE = 1.0;
double OFFSET_X = 0.0;
double OFFSET_Y = 0.0;
#define LINE(x,y,a,b) cerr << "line(" << SCALE*(x) + OFFSET_X << ","	\
	<< SCALE*(y) + OFFSET_Y << ","										\
	<< SCALE*(a) + OFFSET_X << ","										\
	<< SCALE*(b) + OFFSET_Y << ")" << endl;
#define CIRCLE(x,y,r) cerr << "circle(" << SCALE*(x) + OFFSET_X << ","	\
	<< SCALE*(y) + OFFSET_Y << ","										\
	<< SCALE*(r) << ")" << endl;

typedef long long ll;
typedef complex<double> Point;

typedef pair<int, int> pii;
typedef pair<int, pii> ipii;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector< vector<int> > vii;
typedef vector< vector<double> > vdd;

typedef vector<int>::iterator vi_itr;

const int IINF = 1 << 28;
const double INF = 1e30;
const double EPS = 1e-10;
const double PI = acos(-1.0);

// Direction : L U R D
const int dx[] = { -1, 0, 1, 0};
const int dy[] = { 0, -1, 0, 1 };

int main()
{
	int t;
	cin >> t;

	rep(n, t){
		string s;
		int cnt[26] = { 0 };

		cin >> s;
		rep(i, s.size()) cnt[s[i]-'A']++;

		int num[10] = { 0 };
		num[0] = cnt['Z'-'A'];
		num[2] = cnt['W'-'A'];
		num[4] = cnt['U'-'A'];
		num[6] = cnt['X'-'A'];
		num[8] = cnt['G'-'A'];

		num[5] = cnt['F'-'A'] - num[4];
		num[1] = cnt['O'-'A'] - (num[0] + num[2] + num[4]);
		num[3] = cnt['T'-'A'] - (num[2] + num[8]);
		num[9] = cnt['I'-'A'] - (num[5] + num[6] + num[8]);
		num[7] = cnt['S'-'A'] - num[6];

		string ans = "";
		rep(i, 10){
			rep(j, num[i]) ans += ('0'+i);
		}
		cout << "Case #" << n+1 << ": " << ans << endl;
	}
}
