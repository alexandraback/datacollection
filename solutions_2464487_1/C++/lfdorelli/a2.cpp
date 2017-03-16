#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <list>
#include <set>
#include <queue>
#include <gmpxx.h>

using namespace std;

typedef long long int LL;
typedef pair<int,int> pii;
typedef long double T;

#define F first
#define S second
#define pb push_back
#define mp make_pair

#define pi acos(-1)

#define mpz_z mpz_class

mpz_z  need(mpz_z nn, mpz_z r)
{
	mpz_class n = nn;
	return n * (2 * n + 2* r - 1);
}

bool can(mpz_z n, mpz_z has, mpz_z r)
{
	return need(n, r) <= has;
}

int main (void)
{
	int C; cin >> C;

	for(int cas = 1; cas <= C; ++cas)
	{
		mpz_z r, t;

		cin >> r >> t;

		mpz_z hi = 10000000000000000, lo = 0;
		

		while(hi != lo)
		{
			mpz_z mid = (hi + lo + 1)/2;

			if( can(mid, t, r) ) lo = mid;
			else hi = mid - 1;
		} 

		cout << "Case #" << cas << ": " << hi << endl; 
	}
	


	return 0;
}
