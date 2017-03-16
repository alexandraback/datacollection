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

string C_, J_;
ll diff;
void solve ( string C, string J, int state, int depth )
{
	// cout << depth << " " << state << " : " << C << ", " << J << endl;
	if( depth == C.size() ){
		ll tmp = abs(stoll(C) - stoll(J));
		if( diff >= tmp ){
			if( diff == tmp ){
				if( C == C_ ){
					if( stoll(J) < stoll(J_) ) J_ = J;
				}
				else if( stoll(C) < stoll(C_) ){
					C_ = C;
					J_ = J;
				}
			}
			else{
				diff = abs(stoll(C) - stoll(J));
				C_ = C;
				J_ = J;
			}
		}
		return;
	}

	if( C[depth] == '?' && J[depth] == '?' ){
		if( state == 1 ) {
			C[depth] = '0'; J[depth] = '9';
			solve( C, J, state, depth+1 );
		}
		else if( state == -1 ){
			C[depth] = '9'; J[depth] = '0';
			solve( C, J, state, depth+1 );
		}
		else{
			C[depth] = '0'; J[depth] = '0';
			solve( C, J, 0, depth+1 );
			C[depth] = '0'; J[depth] = '1';
			solve( C, J, -1, depth+1 );
			C[depth] = '1'; J[depth] = '0';
			solve( C, J, 1, depth+1 );
		}
	}
	else if( C[depth] == '?' ){
		if( state == 0 ){
			if( J[depth] != '9' ){
				C[depth] = J[depth] + 1;
				solve( C, J, state == 0 ? 1 : state, depth+1 );
			}
			if( J[depth] != '0' ){
				C[depth] = J[depth] - 1;
				solve( C, J, state == 0 ? -1 : state, depth+1 );
			}
		}
		else if( state == 1 ){
			C[depth] = '0';
			solve( C, J, state, depth+1 );
		}
		else if( state == -1 ){
			C[depth] = '9';
			solve( C, J, state, depth+1 );
		}
		C[depth] = J[depth];
		solve( C, J, state, depth+1 );
	}
	else if( J[depth] == '?' ){
		if( state == 0 ){
			if( C[depth] != '9' ){
				J[depth] = C[depth] + 1;
				solve( C, J, state == 0 ? -1 : state, depth+1 );
			}
			if( C[depth] != '0' ){
				J[depth] = C[depth] - 1;
				solve( C, J, state == 0 ? 1 : state, depth+1 );
			}
		}
		else if( state == 1 ){
			J[depth] = '9';
			solve( C, J, state, depth+1 );
		}
		else if( state == -1 ){
			J[depth] = '0';
			solve( C, J, state, depth+1 );
		}
		J[depth] = C[depth];
		solve( C, J, state, depth+1 );
	}
	else{
		// cout << C << " " << J << " " << state << endl;
		solve( C, J, state == 0 ? C[depth] > J[depth] ? 1 : (C[depth] < J[depth] ? -1 : 0) : state, depth+1 );
	}
}

int main()
{
	int t;
	cin >> t;

	rep(n, t){
		string C, J;
		cin >> C >> J;

		diff = 1ll << 62;
		solve(C, J, 0, 0);

		cout << "Case #" << n+1 << ": " << C_ << " " << J_ << endl;
	}
}
