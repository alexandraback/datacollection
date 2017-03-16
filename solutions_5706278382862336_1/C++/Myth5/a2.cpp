#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{    
    freopen("a2.in", "r", stdin);
    freopen("a2.out", "w", stdout);    
    
    int t2;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        printf("Case #%d: ", t1);
        long long a, b;
		int ans = 0;
        scanf("%lld/%lld", &a, &b);         
        long long c = gcd(a, b);
        //cout << a << " " << b << " " << c << endl;
        a /= c;
        b /= c;
        while (a < b) {
        	++ans;
        	a *= 2;
        }
        if ((b & -b) == b)
        	printf("%d", ans);
        else
        	printf("impossible");
        printf("\n");
    }    
    
    return 0;
}
