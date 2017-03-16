#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define reps(i,f,n) for(int i=f; i<int(n); ++i)
#define rep(i,n) reps(i,0,n)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const int INF = 1001001001;
const double EPS = 1e-10;
const int MAX = 2000000;

string solve()
{
	int x, y;
	scanf("%d%d", &x, &y);
	
	string ret;
	if(x<0){
		rep(i, -x)
			ret += "EW";
	}
	else if(x>0){
		rep(i, x)
			ret += "WE";
	}
	
	if(y<0){
		rep(i, -y)
			ret += "NS";
	}
	else if(y>0){
		rep(i, y)
			ret += "SN";
	}
	return ret;
}

int main()
{
	int t;
	scanf("%d", &t);
	rep(i, t){
		printf("Case #%d: %s\n", i+1, solve().c_str());
	}
	return 0;
}