#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <locale>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <climits>
#include <cfloat>
#include <map>
#include <functional>
using namespace std;
const double PI=acos(-1);

int main() // Google Codejam 1C Round
{
    freopen ("A-large.in.txt", "r", stdin);
    freopen ("output-large.txt", "w", stdout);
    
    int tc_N;
    scanf("%d", &tc_N);
    for(int tc=0; tc<tc_N; tc++)
    {
        int r, c, w;
        scanf("%d %d %d", &r, &c, &w);
        
        int ans = (c==w)? c : (c-1)/w + w;
        ans += (r-1) * c/w;

        printf("Case #%d: %d\n", tc+1, ans);
    }
    
    fclose(stdin);
    fclose(stdout);
    
    return 0;
}