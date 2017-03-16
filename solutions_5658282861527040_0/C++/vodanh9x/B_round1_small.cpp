#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>
using namespace std;
#define length(x) (int)x.size()
const double pi=acos(-1);

void xuli()
{
    int A, B, K;
    cin>>A>>B>>K;
    int res = 0;
    for(int i=0; i<A; i++)
        for(int j=0; j<B; j++)
            if ((i&j)<K) res++;
    cout<<res<<endl;
}
int main()
{
     freopen("input.inp","r",stdin);
     freopen("output.out","w",stdout);
     int test;
     cin>>test;
     for(int t=1; t<=test; t++)
     {
         cout<<"Case #"<<t<<": ";
         xuli();
     }
     return 0;
}
