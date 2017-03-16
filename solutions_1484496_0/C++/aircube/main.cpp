#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <stack>

#pragma comment(linker, "/STACK:64777216")
using namespace std;


typedef long long ll;
typedef unsigned long long ull;

template<typename T> int size(T & a) { return (int) a.size(); }
template<typename T> T sqr(T a) {return a * a; }

#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vpi vector<pii > 
#define _(a, b) memset((a), (b), sizeof(a))
#define REP(i, a, b) for(int i=(a); i<(b); ++i)
#define all(a) a.begin(),a.end()

int a[20];
bool ok;
int n;
int b[20];
int c[20];
bool different(int p1, int p2) {
	int l=0, r=0;
	while (l < p1 && r < p2) {
		if (b[l] == c[r]) return false;
		if (b[l] < c[r])
			++l;
		else
			++r;
	}
	return true;
}
void go(int pos, int p1, int p2, int s1, int s2) {
	if(ok)return;
	if (s1==s2 && s1>0) {
		
		if (!different(p1, p2))
			return;
		ok=true;
		REP(i,0,p1) printf("%d%c", b[i], " \n"[i+1==p1]);
		REP(i,0,p2) printf("%d%c", c[i], " \n"[i+1==p2]);
	} else {
		if(pos==n)return;
		b[p1]=a[pos];
		go(pos+1,p1+1,p2,s1+a[pos],s2);
		c[p2]=a[pos];
		go(pos+1,p1,p2+1,s1,s2+a[pos]);
		go(pos+1,p1,p2,s1,s2);
	}
}
void solve(int tn) {
	
	
	cin >> n;
	REP(i, 0,n ) cin >> a[i];

	sort(a,a+n);
	ok=false;
	
	printf("Case #%d:\n", tn);
	go(0,0,0,0,0);
	

	if(!ok)
		printf("Impossible\n");
	
}
int main() {            
#ifdef air
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

	char buf[1024];
	gets(buf);
	int tc;
	sscanf(buf, "%d", &tc);
	REP(t, 1, tc + 1) {
		solve(t);
	}

}