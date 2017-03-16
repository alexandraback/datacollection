#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>
#include <math.h>
using namespace std;


int r;
int c;
int w;

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		cin >> r >> c >> w;
		int ans,a,b,d;
		a=(r-1)*(c/w);
		if(c%w==0)
			b=c/w;
		else
			b=(c/w)+1;
		d=w-1;
		ans=a+b+d;
		cout << "Case #" << it << ": " << ans;
		cout << endl;
		
	}
	return 0;
}
