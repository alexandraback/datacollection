//
//  main.cpp
//  DemoTest
//
//  Created by mezheng on 10/14/13.
//
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
#include <map>
#include <math.h>

using namespace std;
int gcd(int m, int n)
{
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    if (m < n)
    {
        int tmp = m;
        m = n;
        n = tmp;
    }
    while (n != 0)
    {
        int tmp = m % n;
        m = n;
        n = tmp;
    }
    
    return m;
}

int main(int argc, const char * argv[])
{
    int t, n, l, a, b;
    int p, q;
    map<int, bool> checked;
    cin>>t;
    for (int i=1; i<=t; i++) {
        scanf("%d/%d", &p, &q);
        cout<<"Case #" << i << ": ";
        int g = gcd(p, q);
        p /= g;
        q /= g;
        if (q & (q-1)) {
            cout<<"impossible"<<endl;
        } else {
            int c=0;
            while (p < q) {
                c++;
                p*=2;
            }
            cout<<c<<endl;
        }
        
    }
    return 0;
}

