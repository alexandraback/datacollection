#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const double PI = 3.1415926;

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);

    int T,g,i;
    long long r,t;
    scanf(" %d",&T);
    for(g=0;g<T;g++){
        scanf(" %lld %lld",&r,&t);
        double low,up,mid,ans;
        low = 0;
        up = 1e10;
        for(i=0;i<100;i++){
            mid = (up+low)/2;
            if(((2*mid-1)*mid+2*mid*r) <= t){
                ans = low = mid;
            }else
                up = mid;
        }
        printf("Case #%d: %lld\n",g+1,(long long)(ans));
    }

    return 0;
}
