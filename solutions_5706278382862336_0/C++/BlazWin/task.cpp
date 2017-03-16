#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <iterator>
#include <functional>
#include <ctime>

using namespace std;

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define make_triple(x,y,z) make_pair((x), make_pair((y),(z)))
#define fr first
#define sc second
#define ts second.first
#define td second.second

typedef long long ll;
typedef unsigned long long ull; 
typedef double ld;

const long double eps = 1e-9;
const int inf = LONG_MAX;
const ll inf64 = LLONG_MAX;
const long double pi = 3.1415926535897932384626433832795;

#define N 10000

ll gcd (ll a, ll b) {
	if (b == 0)
		return a;
	else
		return gcd (b, a % b);
}

ll p[50];



int main()
{
	int t;
	scanf("%d", &t);
	freopen("output1","w",stdout);

        p[0] = 1;
        for (int i = 1; i<=40; i++)
                p[i] = p[i-1]*2; 

        for (int i = 0; i<t; i++) {
                ll j1, j2;
                scanf("%lld/%lld", &j1, &j2);
                ll j = gcd(j1, j2);
                j1/=j; j2/=j;
                
                bool ye = false;
                for (int h = 0; h<=40; h++)
                        if (p[h] == j2)
                                ye = true;
                if (!ye)
                        printf("Case #%d: impossible\n", i+1);
                else {
                        int hh = 0;
                        while (j1 != j2) {
                                j2 /= 2;
                                j1 = min(j2, j1);
                                hh++;
                        }
                        printf("Case #%d: %d\n", i+1, hh);        
                }              
        }
	return 0;	
}