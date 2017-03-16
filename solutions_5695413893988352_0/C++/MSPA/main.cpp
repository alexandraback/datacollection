#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>

const int N = 1e2+3;
const int inf = 1e9;

typedef long long ll;

using namespace std;

char s1[N], s2[N];
char s[N];
bool solve()
{
    scanf("%s%s", s1,s2);
    int n = strlen(s1);
    
    int m = 1;
    for (int i = 0; i < n; ++i)
        m  *= 10;
    int x=inf,y=0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            sprintf(s, "%0*d", n, i);
            bool f;
            f = 1;
            for (int k = 0; k < n; ++k)
                f &= (s1[k]=='?' || s1[k]==s[k]);
            if (!f)
                continue;
            f = 1;
            sprintf(s, "%0*d", n, j);
            for (int k = 0; k < n; ++k)
                f &= (s2[k]=='?' || s2[k]==s[k]);
            if (!f)
                continue;
            //printf("%d %d %d %d\n",x,y,i,j);
            if (abs(x-y) > abs(i-j)) {
                x = i, y = j;
            } else if (abs(x-y) == abs(i-j)) {
                if (i < x || (i ==x && j < y))
                    x=i,y=j;
            }
        }
    }
    printf("%0*d ", n, x);
    printf("%0*d\n", n,y);
    fflush(stdout);
    return false;
}

int main()
{
        freopen("input.txt","r", stdin);
        freopen("output.txt", "w", stdout);
    int countTests;
    scanf("%d", &countTests);
    for (int curTest = 1; curTest <= countTests; ++curTest) {
        printf("Case #%d: ", curTest);
        solve();
    }
    
    return 0;
}
