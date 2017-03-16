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

bool isVogal(char c){
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void countSubstr(int beg, int end, int strsize, set <pair <int, int> > &count){
	for(int vb = beg; vb >= 0; vb--){
		for(int ve = end; ve < strsize; ve++){
			count.insert(make_pair(vb, ve));
		}
	}
}

int main(){
	//Descomente para acelerar cin
	ios::sync_with_stdio(false);
	int ntc;
	cin >> ntc;
	FORN(tc, 1, ntc+1){
		int n;
		string s;
		cin >> s >> n;

		set <pair <int, int> > count;
		bool cstreak = false;
		int ncons = 0;
		int beg, end;
		FORN(i, 0, (int)s.size()){
			if (not isVogal(s[i]) && cstreak){
				ncons++;
			}
			if (not isVogal(s[i]) && not cstreak){
				cstreak = true;
				ncons = 1;
				beg = i;
			}
			if (isVogal(s[i])){
				cstreak = false;
				ncons = 0;
			}
			if (cstreak && ncons >= n){
				for (int nbeg = beg; (i-nbeg+1) >= n; nbeg++)
					countSubstr(nbeg, i, (int)s.size(), count);
			}
		}

		cout << "Case #"<< tc <<": "<<count.size()<< endl;
	}

/*
tsetse
ts
tse
tset
tsets
tsetse
   ts
  ets
 sets
tsets
   tse
  etse
 setse
tsetse
*/
			
}
