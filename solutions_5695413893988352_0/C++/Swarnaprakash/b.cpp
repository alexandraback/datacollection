// Author: Swarnaprakash
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>

using namespace std;

const int M = 105;
const int INF = 0x3f3f3f3f;
const bool debug = false;

#define SET(x,v)	memset(x,v,sizeof(x))
#define ALL(x) 		(x).begin() , (x).end()
#define SZ(x)		((int)((x).size()))
#define DB(x) 		if(debug) cout << #x << " : " << x <<endl;

typedef long long LL;
typedef vector < int >VI;
typedef vector < string > VS;
typedef vector < VI > VVI;
typedef pair < int, int >PII;
typedef pair < int, PII > PIII;

string c, j;

int min_diff;
pair < string, string > res;

void doit(int index)
{
    if (index == SZ(c) + SZ(j)) {
	int x = atoi(c.c_str());
	int y = atoi(j.c_str());
        DB(c); DB(j);
        DB(x); DB(y);

	int diff = abs(x - y);

	if (diff < min_diff) {
	    min_diff = diff;
	    res = make_pair(c, j);
	} else if (diff == min_diff) {

	    int resx = atoi(res.first.c_str());
	    int resy = atoi(res.second.c_str());

	    if (x < resx) {
		res = make_pair(c, j);
	    } else if (x == resx && y < resy) {
		res = make_pair(c, j);
	    }
	}
	return;
    }

    int real_index;
    if (index < SZ(c)) {
	real_index = index;

        if (c[real_index] != '?') {
            doit(index + 1);
            return;
        }
        for (int i = 0; i <= 9; ++i) {
            c[real_index] = i + '0';
            doit(index + 1);
            c[real_index] = '?';
        }
    } else {
	real_index = index - SZ(c);
        if (j[real_index] != '?') {
            doit(index + 1);
            return;
        }
        for (int i = 0; i <= 9; ++i) {
            j[real_index] = i + '0';
            doit(index + 1);
            j[real_index] = '?';
        }
    }


}

int main()
{
    int tc;
    scanf("%d", &tc);

    for (int t = 1; t <= tc; ++t) {
	cin >> c >> j;
        DB(c);
        DB(j);
	min_diff = INF;
	doit(0);
	cout << "Case #" << t << ": " << res.first << " " << res.
	    second << endl;
    }

    return 0;
}
