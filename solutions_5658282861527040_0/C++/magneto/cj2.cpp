#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <limits.h>
#define ll long long int
#define mod 1000000009
using namespace std;


int main()
{

 // freopen("C:\\Users\\jack\\Desktop\\in.txt","r",stdin);
 //freopen("C:\\Users\\jack\\Desktop\\out.txt","w",stdout);

    int test,tt,a,b,k;
    scanf("%d",&tt);
     test=1;
    
    while(test<=tt)
    {
       
       scanf("%d %d %d",&a,&b,&k);
       
       ll cnt=0;
       
       for(int i=0;i<a;i++)
       for(int j=0;j<b;j++)
       if( (i&j) <k)cnt++;
    
       printf("Case #%d: %d\n",test,cnt);

      test++;
      
                 }

    }
