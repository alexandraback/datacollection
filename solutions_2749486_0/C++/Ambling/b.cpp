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

typedef long long lint;


int main()
{
    // freopen("b2.in", "r", stdin);
    // freopen("b2.out", "w", stdout);

    int t2;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        printf("Case #%d: ", t1);

        int x, y;
        cin>>x>>y;

        string s("");

        if (x < 0)
        {
            int newx = -x;
            for (int i = 0; i < newx; ++i)
            {
                s += "EW";
            }
        } else if ( x > 0){
            for (int i = 0; i < x; ++i)
            {
                s += "WE";
            }
        }

        if (y < 0)
        {
            int newy = -y;
            for (int i = 0; i < newy; ++i)
            {
                s += "NS";
            }
        } else if ( y > 0){
            for (int i = 0; i < y; ++i)
            {
                s += "SN";
            }
        }
        cout<<s;

        printf("\n");
    }
    
    return 0;
}
