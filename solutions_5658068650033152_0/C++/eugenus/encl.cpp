#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <vector>

#define forn(i,n) for(int i = 0; i < (n); i++)
#define forsn(i,s,n) for(int i = (s); i < (n); i++)
#define pb push_back
#define x first
#define y second
#define mp make_pair

typedef long long int tint;

using namespace std;

int solve(int n, int m, int k)
{
	if(min(n,m) == 1) return k;
	int res = k;
	if(k == 6) res = 5;
	if(k <= 9){ int d = (k >= 8) ? (k-8): 0; res = min(res, 6 + d); }
	if(min(n,m) == 2){
		if(k <= 12){ int d = (k >= 11) ? (k-11): 0; res = min(res, 8 + d); }
		if(k <= 15){ int d = (k >= 14) ? (k-14): 0; res = min(res, 10 + d); }
		if(k <= 18){ int d = (k >= 17) ? (k-17): 0; res = min(res, 12 + d); }
		else{
			res = min(res,14);
		}

		return (res);
	}	
	else{
		if(k <= 14){ int d = (k >= 12) ? (k-12): 0; res = min(res, 8 + d); }
		if(k <= 18){ int d = (k >= 16) ? (k-16): 0; res = min(res, 10 + d); }
		else{
			res = min(res,12);
		}
	}

	return (res);
}

int main()
{
	int t, n, m, k;
	cin >> t;
	forn(caso,t){
		cin >> n >> m >> k;
		int res = solve(n,m,k);
		cout << "Case #" << (caso+1) << ": " << res << endl;
	}
	return 0;
}
