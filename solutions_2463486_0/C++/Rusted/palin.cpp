#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <set>
#include <cmath>
#include <sstream>

using namespace std;

bool ispalin(int n)
{
    int r=0;
    int k=n;
    while(n!=0)
    {
        r=r*10+(n%10);
        n/=10;
    }
    return r==k;
}

int main()
{
    int t,a,b,i;
    cin>>t;
    for(int ch=1;ch<=t;ch++)
    {
        int ans=0;
        cin>>a>>b;
        for(i=a;i<=b;i++)
        {
            if(ispalin(i) && (floor(sqrt(i))==ceil(sqrt(i))) && ispalin((int)sqrt(i)))ans++;
        }
        printf("Case #%d: %d\n",ch,ans);
    }
return 0;
}
