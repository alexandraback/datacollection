#include <iomanip>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <complex>
#include <cassert>
#include <bitset>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define decl(v, c) typeof(c) v = c
#define forall(i, c) for(decl(i, c.begin()); i!=c.end(); ++i)
#define dforall(i, c) for(decl(i, c.rbegin()); i!=c.rend(); ++i)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define D(a) cout << #a << "=" << a << endl;
#define pb push_back
#define mp make_pair

typedef long long int tint;

#define MAXN 1024
#define MAX 2*1000010

int T, n;
tint s[MAXN];
tint used[MAX], ans1,ans2;

void print(int mask) {
	bool flag = false;
	forn(j,20) if (mask&(1<<j)) {
		if (!flag) {
			flag = true;
			cout << s[j];	
		}	else cout << " " << s[j];
	}	
	cout << endl;
}

void init() {
	memset(used,0,sizeof(used));	
}


int main () {
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	
	cin >> T;
	forn(rep,T) {
		init();
		cin >> n; forn(i,n) cin >> s[i];	
		forsn(mask,1,(1<<20)) {
			tint sum = 0;
			forn(j,20) if (mask&(1<<j)) sum+= s[j];
			if (used[sum]==0) used[sum] = mask;
			else {
				ans1 = used[sum];
				ans2 = mask;
				break;	
			}
		}
		int inters = ans1&ans2;
		ans1 = (ans1^inters);
		ans2 = (ans2^inters);
		cout << "Case #" << rep+1 << ":" << endl;
		print(ans1);
		print(ans2);
	}
	
	return 0;
}
