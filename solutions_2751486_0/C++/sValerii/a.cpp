// a.cpp : Defines the entry point for the console application.
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

const int N = 200;

char s[N];
int k;

bool isGood(char ch) {
	if ('a' == ch) return false;
	if ('e' == ch) return false;
	if ('i' == ch) return false;
	if ('o' == ch) return false;
	if ('u' == ch) return false;

	return true;
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int tnum;
	scanf("%d\n",&tnum);
	rep(tc,tnum) {
		scanf("%s %d\n",&s,&k);
		printf("Case #%d: ",tc+1);
		int ans = 0;
		int n = strlen(s);
		rep(i,n) {
			int f = 0;
			int len = 0;			
			forr(j,i,n-1){
				if (isGood(s[j])) len++;
				else len = 0;
				if (len >= k) f = 1;
				if (f) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

