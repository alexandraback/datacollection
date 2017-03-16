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

int main() {
	int i, j, k, tt , t;
	string s;
	char r[222]={'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
	freopen("a.txt", "w", stdout);
 	freopen("A-small-attempt0.in" , "r" , stdin);
	cin >> t;
	getline(cin , s);
	for (tt=1; tt<=t; tt++) {
		getline(cin , s);
		printf("Case #%d: " , tt);
		for (i=0; i<s.length(); i++) {
			if (s[i]==' ') cout << ' ';
			else cout << r[s[i]-'a'];
		}
		cout << endl;
	}
	return 0;
}