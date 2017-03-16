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
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdint.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define NDEBUG
#if defined(NDEBUG)
#define DBG_CODE(cb...)
#else
#define DBG_CODE(cb...) cb
#endif
#define WRITE(x) DBG_CODE(cout << x << endl)
#define WATCH(x) DBG_CODE(cout << #x << "=" << x << endl)
#define FORN(i, a, b) for(typeof(b) i = (a); i < (b); i++)
#define ALL(x) x.begin(), x.end()
#define FOREACH(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
const double EPS = 1.e-9;
int cmp(double a, double b)
{
	if(a + EPS < b) return -1;
	if(a - EPS > b) return 1;
	return 0;
}


bool can(const int sum, const vector<int>& s, const int i, const double v)
{
	double available = 1.0 - v;
	double iscore = double(s[i]) + double(sum) * v;
	int num_eqs = 0;
	WATCH(v);
	WATCH(i);
	FORN(k, 0, s.size()){
		if(k == i) continue;
		double raw_score = s[k];
		if(cmp(raw_score, iscore) > 0) continue;
		double delta = (iscore - raw_score) / double(sum);
		available -= delta;
		num_eqs++;
	}
	WATCH(num_eqs);
	WATCH(available);
	switch(cmp(available, 0)){
		case -1:
			return true;
		case 0:		
			return num_eqs > 0;
		case 1:
			return false;
	}
}


int check(const vector<int>& s, const int sum, const double v)
{
	double acc = 0;
	FORN(i, 0, s.size()){
		double y = (v - s[i]) / double(sum);
		acc += y;
	}
	return cmp(acc, 1.0);
}

int main(){
	int ntc;
	scanf("%d", &ntc);
	FORN(tc, 0, ntc){
		int n;
		scanf("%d", &n);
		vector<int> s(n);
		int sum = 0;
		int smax = 0;
		FORN(i, 0, n){
			scanf("%d", &(s[i]));
			sum += s[i];
			smax = max(smax, s[i]);
		}

		printf("Case #%d:", tc + 1);
		FORN(i, 0, n){	
			double lb = 0;
			double ub = 1;
			while(cmp(lb, ub) != 0){
				double m = (ub - lb) / 2 + lb;
				if(can(sum, s, i, m)){
					ub = m;
				}else{
					lb = m;
				}
			}
			printf(" %.6lf", lb * 100);
		}
		printf("\n");
	}
}
