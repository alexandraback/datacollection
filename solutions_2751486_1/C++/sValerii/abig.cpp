// abig.cpp : Defines the entry point for the console application.
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

const int N = 1020000;
char s[N];
vector< PII > t;

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
	int tnum,k;
	scanf("%d\n",&tnum);
	rep(tc,tnum) {
		scanf("%s %d\n",&s,&k);
		printf("Case #%d: ",tc+1);
		int len = strlen(s);
		t.clear();
		int sti=0,f=0;
		rep(i,len){
			if (isGood(s[i])) {
				if (!f) {
					f = 1;
					sti = i;
				}
			} else {
				if (f) {
					int d = i-sti;
					if (d>=k) t.pb( mp(sti,i-1) );
					f = 0;
				}
			}
		}
		int d = len-sti;
		if (f && d>=k) t.pb( mp(sti,len-1));

		i64 ans = 0;
		if (!t.empty()) {
			int ind = 0;
			int m = t.size();
			rep(i,len)
				if (ind<m) {
					if (i+k-1 > t[ind].Y) ind++;
					if (ind < m) {
						int d = max(i+k-1,t[ind].X+k-1);
						ans+=i64(len-d);
					}
				}
		}
		cout << ans << "\n";


	}

	return 0;
}

