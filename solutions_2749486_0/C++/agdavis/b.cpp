#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

//#define NDEBUG
#ifdef NDEBUG
#define DEBUG if (false)
#else
#define DEBUG if (true)
#endif

#pragma GCC diagnostic warning "-Wall"
#define WRITE(x) DEBUG { cout << x << endl; }
#define WATCH(x) DEBUG { cout << #x << " = " << x << endl; }
#define ALL(x) (x).begin(), (x).end()
#define FORN(i, a, b) for(typeof(b) i = (a); i < (b); i++)
#define FOREACH(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

int main(){
	//Descomente para acelerar cin
	//ios::sync_with_stdio(false);
	int ntc;
	scanf("%d", &ntc);
	FORN(tc, 1, ntc+1){
		int x, y;
		scanf("%d %d", &x, &y);
		printf("Case #%d: ", tc);
		if (y < 0){
			FORN(i, 0, abs(y))
				printf("NS");
		}else{
			FORN(i, 0, abs(y))
				printf("SN");
		}
		if (x < 0){
			FORN(i, 0, abs(x))
				printf("EW");
		}else{
			FORN(i, 0, abs(x))
				printf("WE");
		}
		printf("\n");
	}			
}
