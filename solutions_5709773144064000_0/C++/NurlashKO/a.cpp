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
#define sz 1000 * 1000
#define EPS (1e-8)
#define INF ((int)1e9 + 9)
#define write(xx) printf("%d" , xx);
#define readln(xx) getline(cin , xx)
#define read(xx) scanf("%d" , &xx)
#define for(xx1 , yy1 , zz1) for(int zz1 = xx1 ; zz1 <= yy1 ; zz1++)
#define mp make_pair
const double PI  = acos(-1.0);

int t;
double C, F, X, v, ans;

int main(){
	freopen(fname"in", "r", stdin);
	freopen(fname"out", "w", stdout);
	//ios_base::sync_with_stdio(false);
    //cin.tie(0);

    cin >> t;
    for (1, t, T)
    {
      	cout << "Case #" << T << ": ";
    	cin >> C >> F >> X;
    	v = 2;
    	ans = 0;
    	while (1)
    	{
    		if (C / v + X / (v + F) < X / v)
    			ans += C / v, v += F;
    		else
    		{
    			ans += X / v;
    			break;
    		}
    	}
    	printf("%.7f\n", ans);
    }
    return 0;
}

