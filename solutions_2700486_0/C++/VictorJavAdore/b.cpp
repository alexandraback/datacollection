#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

double combi(int n, int r)
{
    if(r<0 || n<0 || r>n)
        return 0.0;
    double c = 1;
    for(int i=1; i<=r; i++)
    {
        c *= n+1-i;
        c /= i;
    }
    return c;
}

int main()
{
    int T;
    cin >> T;
    for(int t=0; t<T; t++)
    {
        int n,x,y;
        cin >> n >> x >> y;
        if(x<0)
            x = -x;
        int i=0;
        while(4*i+1 <= n)
        {
            n -= 4*i+1;
            i++;
        }
        double prob(0);
        if(x+y<2*i)
            prob=1;
        else if(x+y == 2*i)
        {
            if(y >= 2*i)
                prob=0;
            else if(n >= 2*i+1+y)
            {
                prob=1;
            }
            else
            {
                int needed = y + 1;
                for(int r=needed; r <= n; r++)
                {
                    prob += combi(n,r);
                }
                for(int p=0; p<n; p++)
                    prob /= 2;
            }
        }
        else
            prob=0;
        cout << "Case #" << t+1 << ": " << prob << endl;
    }
}
