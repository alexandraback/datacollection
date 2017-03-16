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
int shi[222], m, n, wei;

int getit(int p) {
	int i, j, k=0, t1, t2, t3, pp;
	set <int> s;
	pp=p;
	for (i=0; i<wei; i++) {
		t1=p%10;
		p/=10;
		p+=t1*shi[wei];
		if ((t1>0)&&(p>pp)&&(p<=m)) {
			s.insert(p);
			//k++;
			//cout << pp << " " << p << endl;
		}
	}
	//cout << endl;
	return s.size();
}

int main() {
	int i, j, k, tt , t, ans;
	freopen("c.txt", "w", stdout);
 	freopen("C-large.in" , "r" , stdin);
	shi[1]=1;
	for (i=2; i<8; i++) shi[i]=shi[i-1]*10;
	cin >> t;	
	for (tt=1; tt<=t; tt++) {
		ans=0;
		wei=0;
		cin >> n >> m;
		j=n;
		while (j>0) {
			wei++;
			j/=10;
		}
		for (i=n; i<m; i++) ans+=getit(i);
		printf("Case #%d: %d\n" , tt, ans);
	}
	
	return 0;
}