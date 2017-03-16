#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(int)(b);i++)
#define REP(i,a) for(int i=0;i<(int)(a);i++)
#define ALL(i) i.begin(),i.end()
#define rALL(i) i.rbegin(),i.rend()
#define PB push_back

typedef vector<int> vi;
typedef vector<vector<int> > vvi;

template<class T> string i2a(T x) {ostringstream oss; oss<<x; return oss.str();}

void printvec(vector<int> a)
{
 cout<<"Vecteur:  ";
 REP(i,a.size()) cout<<a[i]<<"  ";
 cout<<endl;
}


/*
void solve(int step, int x, int y, string path) {
	if(step > 100 || found) return;
	if(x == cx && y == cy) {
		found = true;
		result = path;
		return;
	}
	//NSEW
	solve(step + 1, x, y + step, path + "N");
	solve(step + 1, x, y - step, path + "S");
	solve(step + 1, x + step, y, path + "E");
	solve(step + 1, x - step, y, path + "W");
}
*/
int main()
{

   freopen("B-small-attempt1.in", "r", stdin);
   freopen("B-small-attempt1.out", "w", stdout);

	int cases;
	scanf("%d",&cases);
	REP(k, cases) {
		printf("Case #%d: ", k + 1);
		int x, y, cx, cy;
		scanf("%d %d", &x, &y);
		cx = x; cy = y;
		string result = "";
		//solve(1, 0, 0, "");
		int xx = 0, yy = 0;
		int step = 1;
		if(cx > 0) {
			while(true) {
				xx += step;
				if(xx > cx) {
					xx -= step;
					break;
				}
				step++;
				result += "E";
			}
			int diff = abs(cx - xx);
			for(int i = 0; i < diff; i++) {
				result += "WE";
				step+=2;
			}
		}
		if(cx < 0) {
			while(true) {
				xx -= step;
				if(xx < cx) {
					xx += step;
					break;
				}
				step++;
				result += "W";
			}
			int diff = abs(cx - xx);
			for(int i = 0; i < diff; i++) {
				result += "EW";
				step+=2;
			}
		}


		if(cy > 0) {
			while(true) {
				yy += step;
				if(yy > cy) {
					yy -= step;
					break;
				}
				step++;
				result += "N";
			}
			int diff = abs(cy - yy);
			for(int i = 0; i < diff; i++) {
				result += "SN";
				step+=2;
			}
		}
		if(cy < 0) {
			while(true) {
				yy -= step;
				if(yy < cy) {
					yy += step;
					break;
				}
				step++;
				result += "S";
			}
			int diff = abs(cy - yy);
			for(int i = 0; i < diff; i++) {
				result += "NS";
				step+=2;
			}
		}

		cout<<result<<endl;
	}
    return 0;
}
