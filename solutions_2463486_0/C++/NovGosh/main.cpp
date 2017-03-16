#include <cstdio>
#include <fstream>
#include <iostream>

#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <vector>
#include <bitset>
#include <string>
#include <cstring>
#include <algorithm>

#include <ctime>
#include <cstdlib>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(A) (int) (A).size()

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eputs(A) fputs((A), stderr)

#define sqr(A) ((A) * (A))
#define x first
#define y second
  
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair <int, int> pii;

const int N = (int) 0;

int t;
LL A, B;

int trans (int left)
{
	int res = 0;
	while (left)
		res = res * 10 + left % 10, left /= 10;
	return res;
}

bool isPolindrom (LL val)
{                              	
	//cerr << val << ' ';
	string s = "";
	while (val)
		s = s + (char)(val % 10 + '0'), val /= 10;
	for (int i = 0, j = sz(s) - 1; i < j; i++, j--)
		if (s[i] != s[j]) {
			//cerr << "false" << endl;
			return false;
		}					 
	//cerr << "true" << endl;
    return true;
}

bool test (LL val)
{
	LL sqr = val * val;
	
	return (A <= sqr && sqr <= B && isPolindrom(sqr));
}

int solve ()
{
	int res = 0;
    for (int left = 1, pow10 = 1; (LL) left * left <= B; left++) {
		if (left == pow10 * 10)
			pow10 *= 10;
		
		LL h1 = (LL) left * pow10 * 10 + trans(left);
		LL h2 = (LL) left * pow10 + trans(left / 10);

		if (test(h1)) {
			cerr << h1 << ' ' << h1 * h1 << endl;
			res++;
		}					
		if (test(h2)) { 
			cerr << h2 << ' ' << h2 * h2 << endl;
			res++;
		}
		/*
		eprintf("left = %d, trans = %d, hole = %d\n", left, trans(left), left * pow10 * 10 + trans(left));
		if (left)
			eprintf("left = %d, trans = %d, hole = %d\n", left, trans(left / 10), left * pow10 + trans(left / 10));
	    */

	    //cerr << h1 << ' ' << h2 << endl;

		if (sqr(min(h1, h2)) > B) {
			//cerr << h1 << ' '<< h2 << endl;
			break;
		}
	}

	return res;
}

int main () 
{
    #ifdef DEBUG
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    freopen(".err", "w", stderr);
    #endif
    
    cin >> t;
    for (int test = 0; test < t; test++) {
    	cin >> A >> B;
    	printf("Case #%d: ", test + 1);
    	printf("%d\n", solve());
    
    	cerr << endl << endl;
    }


    return 0; 
}

