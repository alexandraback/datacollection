#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
using namespace std;
typedef unsigned long long ull;
const int maxn = 105;
const int inf = 0x3f3f3f3f;
ull cal(ull a,ull b,ull k)
{
    ull ans=a*k+b*k-k*k;
    if(a<k) return a*b;
    for(ull i=k;i<a;i++) for(ull j=k;j<b;j++) if((i&j)<k) ans++;
    return ans;
}
int main()
{
    int T,ncase=0;
    cin>>T;
    while(T--){
        ull a,b,k;
        cin>>a>>b>>k;
        if(a>b) swap(a,b);
        printf("Case #%d: ",++ncase);
        cout<<cal(a,b,k)<<endl;
    }
    return 0;
}

