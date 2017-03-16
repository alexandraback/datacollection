#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <ctime>
#include <stdio.h>
#include <memory.h>
#include <windows.h>
using namespace std;
int main()
{
    freopen("A.in","r",stdin);freopen("out.txt","w",stdout);
    int T,cas=0;
    cin>>T;
    while(T--)
    {
        cas++;
        printf("Case #%d: ",cas);
        double r,t;
        scanf("%lf %lf",&r,&t);
        double delta=(2*r-1)*(2*r-1)+8*t;
        printf("%I64d\n",(long long)((1-2*r+sqrt(delta))/4.0));
    }
    return 0;
}
