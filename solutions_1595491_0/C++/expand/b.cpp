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
#define sort(a) sort(a.begin(),a.end())
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

int getit(int p) {
	if (p<2) return -1;
	return (p+1)/3+1;
}

int main() {
	int i, j, k, tt , t, ans, tmp, m, n , t1;
	freopen("b.txt", "w", stdout);
 	freopen("B-small-attempt1.in" , "r" , stdin);
	cin >> t;
	
	for (tt=1; tt<=t; tt++) {
		cin >> n >> m >> k;
		ans=0;
		vector <int> p;
		for (i=0; i<n; i++) {
			cin >> tmp;
			pb(p,tmp);
		}
		sort(p);
		// for (i=0; i<n; i++) cout << p[i] << " ";
		for (i=n-1; i>=0; i--) {
			if (p[i]%3==0) tmp=p[i]/3;
			else tmp=p[i]/3+1;
			if (tmp>=k) ans++;
			else {
				t1=getit(p[i]);
				if ((m>0)&&(t1>=k)) {
					ans++;
					m--;
				}
			}
		}
		printf("Case #%d: %d\n" , tt, ans);
	}
	
	return 0;
}