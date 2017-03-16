/*
 ID: aandrew
 PROG: GCJ qual 2012, C
 URL: 
 LANG: C++
 
 
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <utility>
#include <cassert>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <bitset>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPE(i, n) for(int i = 0; i <= n; i++)
#define CL(x) memset(x, 0, sizeof(x))
typedef long long ll;

int seen[251000];
int c, T, A, B;

bool check(int a) {
	int x = 1, digit;
	while (a / ((ll)10*x)) x *= 10;

	//cout << "start" << endl;
	do {
		digit = a / x;
		//cout << a << " " << seen[a] << " " << digit << endl;
		
		if (digit && A <= a && a <= B) {
			seen[a/8] |= 1<<(a%8);
			c++;
		}
		
		a %= x;
		a = 10*a + digit;	
	} while (a < A || B < a || !(seen[a/8] & (1<<(a%8))) );
}

int main() {

	cin >> T;
	//T = 50;
	REP(i, T) {
		cin >> A >> B;
		//A = 1; B = 2000000;
		
		CL(seen);
		ll total = 0;
		//if (
		
		for (int j = A; j <= B; j++) {
			if ( !(seen[j/8] & (1<<(j%8))) ) {
				c = 0;
				check(j);
				total += ((ll)c - 1) * c / 2;
			}
		}
		cout << "Case #" << (i+1) << ": " << total << endl;
	}
}