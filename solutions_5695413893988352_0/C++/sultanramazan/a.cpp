#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define sqr(x) (x) * (x)
#define forn(i, l, r) for(int i = l; i < r; i ++)
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define y1 salnk
#define N 200100              
#define sz(a) (int)a.size()
#define ll long long
const int inf = (int)1e9;
const double pi = acos(-1.0);
const double eps = 1e-9;

string s, t;
char a[N];
int n, qq, resa, resb, res ;

void rec(int v) {
 	if (v == n) {
 	      int f1 = 0, f2 = 0;
 	      for (int i = 0; i < n / 2; i++)
 	      	f1 = f1 * 10 + a[i] - '0';
 	      for (int i = n / 2; i < n; i++)
 	      	f2 = f2 * 10 + a[i] - '0';

 		if (abs(f1 - f2) < res) {
 	 	 	res = abs(f1 - f2);
 	 	 	resa = f1;
 	 	 	resb = f2;
 	 	}
 	 	return;
 	}
 	if (s[v] != '?') {
 	 	a[v] = s[v];
 	 	rec(v+1);
 	 	return;;

 	}
 	for (int i = 0; i < 10; i++) {
 	 	a[v] = char(i+'0');
 	 	rec(v + 1);
 	 	a[v] = '0';
 	}
}
int nn;
void out(int x) {
 	if (x < 10) {
 		if (nn == 1) {
 			cout << x;
 			return;
 		}
 		if (nn == 2) {
 		 	cout << 0<<x;
 		 	return;
 		}
 	 	cout << 0 << 0 << x;
 	 	return;
 	}
 	if (x < 100) {
 		if (nn==3) {
 	 		cout << 0 << x;
 	 		return;
 	 	}
 	 	cout << x;
 	 	return;		
 	}
 	cout <<x;
}
int tf;
int main () {
    //freopen("in", "r", stdin);
    cin >> tf;
    while (tf--) {
     	qq++;
     	cout << "Case #"<<qq<<": ";
     	cin >> s >> t;
     	s += t;
     	res = 10000;
     	n = s.size();
     	nn=n/2;
     	rec(0);
     	out(resa);
     	cout<<" ";
     	out(resb);
     	cout << endl;
    }
    return 0;
}
