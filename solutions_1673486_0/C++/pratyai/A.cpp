#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int A, B;
double p[100001];

#define inf 1000000000

int main()
{
    freopen("A-small-attempt0.in", "rt", stdin);
    freopen("A-small-attempt0.out", "wt", stdout);
    int T;
    cin>>T;
    for (int cas=1; cas<=T; ++cas)
    {
        cin>>A>>B;
        double ex = B+2;
        double pc = 1;
        for (int i=0; i<A; ++i)
        {
            int l = A-i;
            double _ex = (B-A+1+2*l) + (B+1)*(1-pc);
            ex = min(ex,_ex);
            cin>>p[i];
            pc *= p[i];
        }
        double _ex = (B-A+1) + (B+1)*(1-pc);
        ex = min(ex,_ex);
        printf("Case #%d: %.8lf\n", cas, ex);
    }
    return 0;
}
