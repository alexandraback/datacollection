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
    freopen ("A-small-attempt0.in.txt", "r", stdin);
    freopen ("output-small.txt", "w", stdout);
    
    int tc_N;
    scanf("%d", &tc_N);
    for(int tc=0; tc<tc_N; tc++)
    {
        int c, w;
        scanf(" 1 %d %d", &c, &w);

        printf("Case #%d: %d\n", tc+1, (c==w)? c : (c-1)/w + w);
    }
    
    fclose(stdin);
    fclose(stdout);
    
    return 0;
}