#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <string>

using namespace std;

int T,t;
unsigned long long d,s;

unsigned long long min(unsigned long long a, unsigned long long b)
{
    if (a<b) return a;
    return b;
}

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    cin>>T;
    while (t<T){
        t++;
        cin>>d>>s;
        unsigned long long l = 1, r = min(s/d,1000000000ll),mid,ans = 0;
        while (l<=r){
            mid = (l+r)/2;
            unsigned long long tmp = (2*d)*mid+(4*mid-3+1)*mid/2;
            if (tmp>s) r = mid-1;
            else if(tmp<s){
                l = mid+1;
                if (mid>ans) ans = mid;
            }
            else{
                ans = mid;
                break;
            }
        }
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
