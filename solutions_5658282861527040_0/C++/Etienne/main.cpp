#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

long long countways(int src, int max)
{
    int badbits = 0;
    int diff = max-src;
    for(int i=0;(1<<i) < diff;i++)
    {
        if(src & (1<<i))
            badbits++;
    }
    int val = max-src - (2<<badbits);
    cout << src << " " << max << " " << val << endl;
    return val;
}

void testCase()
{
    int a,b,k;
    cin >> a >> b >> k;
    long long totalways=0;
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++)
        {
            if((i&j) < k)
                totalways++;
        }
    }
    cout << " " << totalways << endl;
}

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        cout << "Case #" << i+1 << ":";
        testCase();
    }
}


