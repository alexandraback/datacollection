//Solution by Zhusupov Nurlan
#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;

typedef long long LL;
typedef map<string , int> MSI;
typedef vector<int> VI;

#define pb(x) push_back(x)
#define sqr(x) ((x) * (x))
#define F first
#define S second
#define SZ(t) ((int) t.size())
#define len(t) ((int) t.length())
#define base 10
#define fname ""
#define sz 55
#define EPS (1e-8)
#define INF ((int)1e9 + 9)
#define write(xx) printf("%d" , xx);
#define readln(xx) getline(cin , xx)
#define read(xx) scanf("%d" , &xx)
#define for(xx1 , yy1 , zz1) for(int zz1 = xx1 ; zz1 <= yy1 ; zz1++)
#define mp make_pair
const double PI  = acos(-1.0);

LL d[sz][sz][sz], g, T, ans, K, A, B, c, k[sz], a[sz], b[sz];

int main(){
	freopen(fname"in", "r", stdin);
	freopen(fname"out", "w", stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (1, T, t)
    {
    	cout << "Case #" << t << ": ";
    	cin >> A >> B >> K;
    	ans = 0;
		for (0, A - 1, i)
			for (0, B - 1, j)
			{
				if ((i & j) < K)
					ans++;
			}
	 	cout <<ans << "\n";
	}
    return 0;
}

