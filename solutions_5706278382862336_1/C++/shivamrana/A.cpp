//ShivamRana...
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <iterator>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <functional>
#include <numeric>
#include <algorithm>
using namespace std;
#define ll long long
int main()
{
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++)
    {
        printf("Case #%d: ",cs);
        ll a,b;
        scanf("%lld/%lld",&a,&b);
        ll res=0;
        int f=0;
       /* while(1)
        {
            if(b%2==0)
            {
                b=b/2;
                res++;
                if(b<=a&&b%2==0)break;
            }
            else
            {
                if(b>a){
                    f=1;
                    break;
                }

            }
        }*/
        ll gcd=__gcd(a,b);
        a=a/gcd;
        b=b/gcd;

        if((b&(b-1))!=0)
        {
            f=1;
        }
        else
        {
            long double tt=(a*1.0)/(b*1.0);
            long double x=1.0;
            while(x>tt)
            {
                x/=2.0;
                res++;
            }
        }
        
        if(f)
        {
            cout<<"impossible\n";
        }
        else cout<<res<<endl;
       
    }
    return 0;
}