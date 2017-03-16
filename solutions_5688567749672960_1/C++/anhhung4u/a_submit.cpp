//Pham Huu Canh
//
//Algorithm:
//Complexity:
//AC:

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define max64 9223372036854775807LL
#define max32 2147483647
#define maxty 1001001001
#define max16 32767
#define EPS 1e-8
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define PQ priority_queue
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define timmax(x, y)    ((x) > (y) ? (x) : (y))
#define timmin(x, y)    ((x) < (y) ? (x) : (y))
#define fori(i, n)      for((i) = 0; (i) < (n); (i)++)
#define ford(i, n)      for((i) = (n-1); (i) >= 0; (i)--)
#define fore(i, v)		for(typeof(v.begin()) i = v.begin(); i != v.end(); i++)
#define repi(i, a, b)   for((i) = (a); (i) <= (b); (i)++)
#define repd(i, a, b)   for((i) = (a); (i) >= (b); (i)--)
#define all(tmpv)      tmpv.begin(), tmpv.end()

#define fii "a.inp"
#define foo "a.txt"
#define MOD 1000000007

using namespace std;

typedef pair<int, int> II;
typedef vector<int> VI;

ll sum[20];

void precal(){
	
	int i;
	sum[0] = 1;
	sum[1] = 9;
	sum[2] = 9 + 1 + 9;
	sum[3] = 99 + 1 + 9;
	sum[4] = 99 + 1 + 99;
	sum[5] = 999 + 1 + 99;
	sum[6] = 999 + 1 + 999;
	sum[7] = 9999 + 1 + 999;
	sum[8] = 9999 + 1 + 9999;
	sum[9] = 99999 + 1 + 9999;
	sum[10] = 99999 + 1 + 99999;
	sum[11] = 999999 + 1 + 99999;
	sum[12] = 999999 + 1 + 999999;
	sum[13] = 9999999 + 1 + 999999;
	sum[14] = 9999999 + 1 + 9999999;
	
	repi(i, 1, 14)	sum[i] += sum[i-1];
}

ll solve(ll n){
	int i, len;
	char s[50], xau[50];
	
	if (n == 1)	return 1;
	
	sprintf(s, "%I64d", n);
	len = strlen(s);
	ll res = sum[len-1];

	////////
	if (s[len-1] > '0'){
		repi(i, len/2, len-1)	s[i] = '0';
		s[len-1] = '1';
	}
	else{
		int nho = 1;
		repi(i, len/2, len-1){
			if (s[i] != '0')	nho = 0;
			s[i] = '0';
		}
		s[len-1] = '1';
		ford(i, len/2){
			s[i] -= nho;
			if (s[i] < '0')	s[i] = '9', nho = 1;
			else break;
		}
		
	}
	
	strcpy(xau, s);
	reverse(s, s + len);
	
	ll t = 0, z = 0;
	fori(i, len){
		t = t * 10 + s[i] - '0';
		z = z * 10 + xau[i] - '0';
	}
	ll p = 1;
	fori(i, len-1)	p *= 10;
	/////////////
	res += timmin(t - p + 1 + n - z, n - p);
	
	return res;
}

void input()
{
	int itest, ntest;
	ll n;
	
	precal();
	scanf("%d", &ntest);
	repi(itest, 1, ntest){
		scanf("%I64d", &n);
		printf("Case #%d: %I64d\n", itest, solve(n));
	}
}

int main()
{
    #ifndef ONLINE_JUDGE
    	freopen(fii,"r",stdin);
    	freopen(foo,"w",stdout);
    #endif

    input();

    return 0;
}

