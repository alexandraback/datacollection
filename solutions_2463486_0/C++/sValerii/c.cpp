// c.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <list>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <ctime>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define forr(i,a,b) for (int i=a; i<=b; i++)
#define ford(i,a,b) for (int i=a; i>=b; i--)
#define mset(a,b) memset(a,b,sizeof(a))
#define sz(a) int( a.size() )
#define all(A) A.begin(),A.end()
#define sqr(q) q*q
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define X first
#define Y second

typedef long long i64;
typedef vector<int> VI;
typedef vector< VI > VVI;
typedef pair<int,int> PII;
typedef vector<string> VS;

int isPalindrome(i64 ch) {
	i64 r = 0;
	i64 u = ch;
	while (u) {
		r = r*10+u%10;
		u/=10;
	}
	return r == ch;
}

/*
freopen("data.in","w",stdout);
	int k=0;
	forr(i,1,10000000) {
		if (isPalindrome(i)) {
			i64 r = (i64)i * (i64)i;
			if (isPalindrome(r) ) {
				k++;
				printf("%d,",i);
				if (k%100 == 0) printf("\n");
			}
		}
	}
	printf("\n%d\n",k);
*/


int pal[39] = {
	1,2,3,11,22,101,111,121,202,212,1001,1111,2002,10001,10101,10201,11011,11111,11211,20002,20102,100001,101101,110011,111111,200002,1000001,1001001,1002001,1010101,1011101,1012101,1100011,1101011,1102011,1110111,1111111,2000002,2001002};

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int tnum;
	scanf("%d",&tnum);
	rep(tc,tnum){
		i64 a,b;
		cin >> a >> b;
		int r = 0;
		rep(i,39) {
			i64 t = pal[i];
			t = t*t;
			if (t>=a && t<=b) r++;
		}
		printf("Case #%d: %d\n",tc+1,r);
	} 
	return 0;
}

