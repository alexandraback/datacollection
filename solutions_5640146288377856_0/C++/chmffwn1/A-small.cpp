#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <list>
#include <set>
#include <map>
#include <ctime>
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define ms0(x) memset((x),0,sizeof(x))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define rep(i,m,n) for(int i=(m),_end=(n);i < _end;++i)
#define repe(i,m,n) for(int i=(m), _end =(n);i <= _end;++i)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;
using namespace std;

int main(){
    freopen("/Volumes/Mac1/Dropbox/chmffwn1/gcj/Round1_2015/C/A-small-attempt7.in", "r", stdin);
    freopen("/Volumes/Mac1/Dropbox/chmffwn1/gcj/Round1_2015/C/A-small.out", "w", stdout);
	int T;
    int R;
    int C;
    int W;
    cin >> T;
    rep(i, 0, T) {
    	cin >> R >> C >> W;
    	int res;
    	res = C/W*(R-1);
    	if (C%W==0) res+=W+C/W-1;
    	//res += (C - (C/W-1)*W + (C/W-1));
    	else res += W+C/W;
    	cout << "Case #" << (i+1) << ": " << res << endl; 
    	//cout <<"shout "<< C/W<< endl;
    }
	return 0;
}
