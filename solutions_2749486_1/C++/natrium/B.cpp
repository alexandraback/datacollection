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

string solve_small()
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

bool func(int x, int y, int rem, vector<char>& mark, int n)
{
	/*
	printf("x=%d, y=%d, rem=%d, mark=", x, y, rem);
	reps(i, 1, mark.size())
		putchar(mark[i]);
	puts("");
	*/
	
	if(rem){
		for(int i=min(rem, n); i>0; --i){
			if(mark[i] == 'N'){
				mark[i] = 'W';
				if(func(x+i, y, rem-i, mark, n))
					return true;
				mark[i] = 'S';
				if(func(x, y+i, rem-i, mark, n))
					return true;
				mark[i] = 'N';
			}
		}
	}
	else{
		if(x == 0)
			return true;
		
		for(int i=min(x, n); i>0; --i){
			if(mark[i] == 'N'){
				mark[i] = 'E';
				if(func(x-i, y, rem, mark, n))
					return true;
				mark[i] = 'N';
			}
		}
	}
	return false;
}

int ox, oy;
string solve_large()
{
	scanf("%d%d", &ox, &oy);
	
	int x = abs(ox), y = abs(oy);
	int n, sum = 0;
	for(n=0; sum < x+y || (sum-(x+y))%2 == 1; ++n, sum+=n);
		
		int rem = (sum-(x+y)) / 2;
	
	vector<char> mark(n+1, 'N');
	func(x, y, rem, mark, n);
	
	string ans = "";
	rep(i, n)
	ans += mark[i+1];
	
	rep(i, ans.size()){
		if(ox < 0){
			if(ans[i] == 'E')
				ans[i] = 'W';
			else if(ans[i] == 'W')
				ans[i] = 'E';
		}
		if(oy < 0){
			if(ans[i] == 'N')
				ans[i] = 'S';
			else if(ans[i] == 'S')
				ans[i] = 'N';
		}
	}
	return ans;
}

void verify(string str)
{
	int x=0, y=0;
	rep(i, str.size()){
		char c = str[i];
		if(str[i] == 'W')
			x -= i+1;
		if(str[i] == 'E')
			x += i+1;
		if(str[i] == 'S')
			y -= i+1;
		if(str[i] == 'N')
			y += i+1;
	}
	puts(x==ox && y==oy ? "yes" : "no");
}
int main()
{
	int t;
	scanf("%d", &t);
	rep(i, t){
		string ret = solve_large();
		printf("Case #%d: %s\n", i+1, ret.c_str());
	}
	return 0;
}