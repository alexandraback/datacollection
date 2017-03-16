#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include <cassert>
#include <climits>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
//#include <unordered_set>
//#include <unordered_map>
#include <functional>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef long long llong;
typedef pair<llong, llong> pll;
typedef unsigned long long ullong;
#define mp make_pair
#define sqr(x) ((x)*(x))
const double PI = 3.14159265359;
#define y1 Y1
#define y0 alalal1231

int solve(){
	int n;
	cin >> n;
	vector<string> arr(n);
	vector<int> ord(n);
	vector<set<int>> gr(256);
	for( int i = 0; i < n; ++i ){
		ord[i] = i;
		cin >> arr[i];
		arr[i].resize( unique( arr[i].begin(), arr[i].end() ) - arr[i].begin() );
		//cout << arr[i] << endl;
		for( int j = 1; j < ((int)arr[i].size()); ++j ){
			gr[arr[i][j-1]].insert( arr[i][j] );
		}
	}
	for( int i = 0; i < (int)gr.size(); ++i )
		if( 2 <= gr[i].size() )
			return 0;

	int ans = 0;
	do{
		string s = "";
		for( int i = 0; i < n; ++i ) s += arr[ord[i]];
		int len = (int)s.size();

		vector<bool> used( 255 );
		bool OK = true;
		for( int l = 0, r; l < len;  ){
			if( used[s[l]] ){
				OK = false;
				break;
			}
			used[s[l]] = true;
			r = l;
			while( r+1 < len && s[l] == s[r+1] ) ++r;
			//
			l = r + 1;
		}
		if( OK ) ++ans;
	}while( next_permutation(ord.begin(),ord.end()) );
	//cout << endl;
	return ans;
}

int main(){
#ifdef MYLOCAL
    freopen("prob.in" , "rt", stdin);
	freopen("prob.out", "wt", stdout);
#endif
    
	int t;
	cin >> t;
	for( int i = 1; i <= t; ++i ) {
		cerr << "Test: " << i << endl;
		printf( "Case #%d: %d\n", i, solve() );
		
	}

    return 0;
}

