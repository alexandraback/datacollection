#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>

using namespace std;
 
void display()
{
    int Case;
    scanf("%d", &Case);
    for (int ca=1;ca<=Case;ca++) {
        printf("Case #%d: ", ca);
        int a, n, p[101], ans = 0x7fffffff;
        scanf("%d%d", &a, &n);
        for(int i=0;i<n;i++)
            scanf("%d", &p[i]);
        sort(p, p+n);
        int add=0;
        if (a==1) {
            printf("%d\n", n);
            continue;
        }
        for(int i=0;i<n;i++) {
            if (a>p[i]) a+=p[i];
            else {
                ans = min(ans, add+n-i);
                while (a<=p[i]) {
                    a+=a-1;
                    add++;
                }
                a+=p[i];
            }
        }
        printf("%d\n", min(ans, add));
    }
}
int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("test.out", "w", stdout);
    display();
    return 0;
}
