#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <limits.h>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#define mod 1000000007
#define LL long long
using namespace std;


int main()
{
 freopen("D-small-attempt0.in","r",stdin);freopen("output.in","w",stdout);
    ios_base::sync_with_stdio(0);
    int t;
    cin >>t;
    int tc=1;
    while(t--)
    {
        int x,r,c;
        cin >>x >> r >>c;
        bool flag =true;
        if(r*c % x !=0 || (x/2>=min(r,c)&& x != 2))
            flag = false;
        cout << "Case "<<"#" << tc++ << ": "<<(flag?"GABRIEL":"RICHARD")<<endl;
    }
    return 0;
}


