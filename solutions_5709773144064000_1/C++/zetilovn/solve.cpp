#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    ifstream cin("B-large.in");
    ofstream cout("output.txt");
    int n, i;
    cin>>n;
    for (i=0;i<n;++i)
    {
        long double c, f, x, r=0, t=2, curr=0;
        cin>>c>>f>>x;
        while (c/t+x/(t+f)<x/t)
        {
            r+=c/t;
            t+=f;
        }
        r+=x/t;
        cout.precision(25);
        cout<<"Case #"<<i+1<<": "<<r<<endl;
    }
    return 0;
}
