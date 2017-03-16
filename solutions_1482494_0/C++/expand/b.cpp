#include<iostream>
#include<vector>
#include<map>
#include<fstream>
#include<string>
#include<math.h>
#include<queue>
#include<stack>
#include<sstream>
#include<algorithm>
#include<set>
#include<stdio.h>
#include<stdlib.h>

#define vint vector <int>
#define vstring vector <string>
#define np(a) next_permutation(a.begin(),a.end())
#define ff(i,n) for (i=0; i<n; i++)
#define pb(a,b) a.push_back(b)
#define mkp make_pair
#define all(a) a.begin() , a.end()

/*

sort(a.begin(),a.end(),f) for vint a;
sort(a,a+n) for int a[n] where a[0] is smallest;

reverse(a.begin(),a.end()) for vint a;
reverse(a,a+n) for int a[n];

pair <int , string> a;

multiset<int> mymultiset (myints,myints+5);

*/

using namespace std;
typedef __int64 ll;
stringstream ss;

double p[111111] , e[111111] , ans , r[111111];

int main() {
	int i, j, k, tt , t , a[1111] , b[1111] , fen[1111] , tol , n , ans , me;
	bool b1 , b2;
	int t1 , tval;
	bool done2[1111] , done1[1111];

	freopen("b.txt", "w", stdout);
 	freopen("B-small-attempt0.in" , "r" , stdin);

	cin >> t;
	for (tt=1; tt<=t; tt++) {
		cin >> n;
		for (i=1; i<=n; i++) cin >> a[i] >> b[i];
		for (i=1; i<=n; i++) fen[i]=2;
		for (i=1; i<=n; i++) done2[i] = done1[i] = false;
		tol=0;
		ans=0;
		me=0;
		while (1) {
			b1=b2=false;
			for (i=1; i<=n; i++) if ((!done2[i]) && (me>=b[i])) {
				b2=true;
				if (done1[i]) me++;
				else me += 2;
				ans++;
				done2[i] = done1[i] = true;
				tol++;
			}
			if (b2) continue;
			tval = -11111;
			for (i=1; i<=n; i++) if ((!done1[i]) && (me>=a[i]) && (b[i]>tval)) {
				tval = b[i];
				t1 = i;
			}
			if (tval!=-11111) {
				done1[t1] = true;
				me += 1;
				ans++;
				b1=true;
			}
			else break;
		}
		if (tol!=n) printf("Case #%d: Too Bad\n", tt);
		else printf("Case #%d: %d\n", tt , ans);
	}
	return 0;
}