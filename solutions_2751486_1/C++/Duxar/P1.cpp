#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define SIZE(A) ((int)(A).size())
#define ALL(A) (A).begin(),(A).end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define NMAX OOOOOO
#define MMAX OOOOOO

using namespace std ;

#define INFILE "date.in"
#define	OUTFILE "date.out"
#define cin F
#define cout G

ifstream F (INFILE) ;
ofstream G (OUTFILE) ;


string S ;
deque<char> Q ;

void Solve() ;

int main() {
	int i ;
	int N ;
	cin >> N ;
	for (i = 1; i <= N; ++i) {
		cout << "Case #" << i << ": " ;
		Solve() ;
		cout << '\n' ;
	}
	F.close() ;
	G.close() ;
	//system("PAUSE") ;
	return 0;
}

void Solve() {
	int n, lg, i, sz, nrc = 0, left, right, lastpos = 0 ;
	long long RES = 0 ;
	char c, lastc = 'a' ; 
	Q.clear() ;
	cin >> S ;
	cin >> n ;
	lg = S.length() ;
	for (i = 1; i <= lg; ++i) {
		c = S[i - 1] ;
		Q.push_back(c) ;
		if (strchr("aeiou",c) == NULL) {
			++nrc ;
		}
		sz = Q.size() ;
		if (sz == n && nrc == n) {
			left = 0 ;
			right = lg - i ;
			left = i - n - lastpos ;
			if (strchr("aeiou",lastc) == NULL) {
				left = 0 ;
			}
			RES += (long long) (left + 1) * (long long) (right + 1) ;
			lastpos = i - n + 1 ;
		}
		
		if (sz == n ) {
			lastc = Q.front() ;
			if (strchr("aeiou",lastc) == NULL) {
				--nrc ;
			}
			Q.pop_front() ;
		}
	}
	cout << RES ;
}
