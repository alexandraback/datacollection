#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(i=0;i<n;i++)
#define F1(i,n) for(i=1;i<=n;i++)
const int inf = 1000000009;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l, ans, u[26];
char ss[1000002];

void warmup(string a, string b)
{
    F0(i,SZ(a)) if (islower(a[i]))
    {
        u[a[i]-'a'] = b[i]-'a';
    }
}

int main() {
//	freopen("a.in", "r", stdin);

    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);

//	freopen("A-large.in", "r", stdin);
//	freopen("A-large.out", "w", stdout);

    memset(u, -1, sizeof(u));

    warmup("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
    warmup("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
    warmup("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");

    u[16]=25; u[25]=16;

/*    F0(i,26) {
        cout << u[i] << " ";
    }
    cout << endl; */

    int tt, tn; cin >> tn; gets(ss);
	F1(tt,tn) {
        printf("Case #%d: ", tt);
        gets(ss);
        n = strlen(ss);

        F0(i,n) if (islower(ss[i]))
        {
            k = ss[i] - 'a';
            k = u[k];
            ss[i] = k+'a';
            cout << ss[i];

        } else cout << ss[i];

        cout << endl;
	}
	
	return 0;
}
