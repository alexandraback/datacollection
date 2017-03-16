#pragma comment(linker, "/STACK:512000000")
#include <iostream>
#include <vector>
#include <iomanip>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <ctime>
#include <string>
#include <sstream>
#include <math.h>
#include <stack>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const int N = 1e6 + 5;
int memo[N];
int nextt[N];


long long rev(long long x) {
	long long t = 0;
	while (x) {
		t = t * 10 + x % 10;
		x /= 10;
	}
	return t;
}

long long brute(long long at, long long n) {
	if (memo[at] != -1) {
		return memo[at];
	}

	if (at == n) return 0;

	long long a1 = brute(at + 1, n) + 1;
	long long a2 = (rev(at) > at && rev(at) < N? brute(rev(at), n) : 1000000000) + 1;
	if (a1 < a2) {
		nextt[at] = at + 1;
	} else {
		nextt[at] = rev(at);
	}
	return memo[at] = min(a1, a2);
}

long long solve(long long n) {
	
	long long have = 1;
	long long at = 1;

	if (n <= 19) {
		return n;
	}

	at = 10;
	have = 10;

	int up = 1;
	while (at * 10 <= n) {
		long long power = 1;
		long long temp = at;
		long long best = 1e18;
		long long revat; 
		for (int nines = 1; nines <= up ; ++nines) {
			temp += power * 9;
			power *= 10;

			long long pay = temp - at + (at * 10 - rev(temp)) + 1;
			//if (pay > best) break;
			if (pay < best)  {
				best = pay;
				revat = temp;
			}
		}
		++up;
		at *= 10;
		have += best;
		//cerr << revat << " ";
	}
	
	if (at == n) return have;

	long long revat = -1;
	long long nrt = rev(n);
	long long nr;
	long long power = 1;
	long long temp = at;
	long long best = n - at;
	for (int digits = 1; digits <= up ; ++digits) {
		
		for (int delat = 0; delat <= digits; ++delat) {
			temp = at;
			power = 1;
			nr = nrt;
			
			bool was_del = 0;
			for (int i = 0; i < digits; ++i) {
				if (i == delat) {
					if (nr % 10) {
						temp += power * ((nr - 1  ) % 10);
						was_del = 1;
					} else {
						temp += power * ((nr  ) % 10);
					}
				} else {
					if (i > delat && was_del) {
						temp += power * ((9) % 10);
					} else {
						temp += power * ((nr  ) % 10);
					}
					
				}
				power *= 10;
				nr /= 10;
						
				long long pay = temp - at + (n - rev(temp)) + 1;
				if (rev(temp) <= n && pay < best) {
					revat = temp;
					best = pay;
				}

			}
		}
	}
	//cerr << revat << endl;
	have += best;
	return have;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	    freopen("output1.txt","w",stdout);
	#else
	#define taskname "cutting"
		//freopen(taskname".in","r",stdin);
		//freopen(taskname".out","w",stdout);
	#endif
	/*
	int tst = 0;
	while (true) {
		long long at = (rand() * rand()) % 1000000 + 1;
		memset(memo, -1, sizeof(memo));
		long long br = brute(0, at);
		long long solv = solve(at);
		if (br != solv) {
			cerr << solv << " " << br << endl;
			cerr << at << endl;
			return 0;
		}

		if (tst++ % 100 == 0) {
			cerr << tst << endl;
		}
	}
	*/
	int tests_; cin >> tests_;
	for (int test_ = 1; test_ <= tests_; ++test_) {
		///memset(memo, -1, sizeof(memo));
		long long x; cin >> x;
		long long ans = solve(x);
		/*
		long long brsolve = solve(x);
		
		
		
		if (ans != brsolve) {
			
			int at = 0;
			cout << x << endl;
			while (at != x) {
				if (nextt[at] != at + 1){
				cerr << at << " ";
				}
				at = nextt[at];
		
			}
			cerr << endl;
			
			cerr << ans << endl;
			cerr << solve(x) << endl;
			cerr << x << endl;
			return 0;

		}
		*/
		cout << "Case #"<< test_ << ": ";
		cout << ans << endl;
	
		
		cerr << "Case #"<< test_ << ": ";
		cerr << ans << endl;
		//int at = 0;
		
		/*
		cout << x << endl;
		while (at != x) {
			if (nextt[at] != at + 1){
			cout << at << " ";
			}
			at = nextt[at];
		
		}
		cout << endl;
		*/
	}
	
	return 0;
}