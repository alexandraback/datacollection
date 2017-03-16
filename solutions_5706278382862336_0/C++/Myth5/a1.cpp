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

int main()
{    
    freopen("a1.in", "r", stdin);
    freopen("a1.out", "w", stdout);    
    
    int t2;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        printf("Case #%d: ", t1);
        int a, b, ans = 0;
        scanf("%d/%d", &a, &b); 
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
