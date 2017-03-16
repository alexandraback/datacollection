#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int T,ca=0;
    scanf("%d",&T);
    while(T--){
        long long r,t;
        cin >> r >> t;
        long long l=1,h=t/2/r;
        while(l<h){
            LL mid=(l+h+1)/2;
            LL a=2*r+1;
            LL b=a+4*(mid-1);
            if(a+b<=2*t/mid) l=mid;
            else h=mid-1;
        }
        cout << "Case #" << ++ca << ": " << l << endl;
        
    }
}
