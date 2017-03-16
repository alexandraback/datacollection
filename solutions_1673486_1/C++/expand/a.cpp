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
	int i, j, k, tt , t , B , A;

	freopen("a.txt", "w", stdout);
 	freopen("A-large.in" , "r" , stdin);
	cin >> t;
	for (tt=1; tt<=t; tt++) {
		cin >> A >> B;
		for (i=1; i<=A; i++) cin >> p[i];
		r[0]=1;
		for (i=1; i<=A; i++) r[i] = r[i-1]*p[i];
		ans = 1+B+1;
		for (i=0; i<=A; i++) {
			e[i] = (B-A+1+2*i) * r[A-i] + (B-A+1+2*i + B+1) * (1-r[A-i]);
			if (e[i]<ans) ans=e[i];
		}
		printf("Case #%d: %.6lf\n" , tt , ans);
	}
	return 0;
}