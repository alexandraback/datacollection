#include <iostream>
#include <cstring>
#include <cstring>
#include <cmath>
using namespace std;

long long r,t;
bool check(long long mid)
{
    //cout <<mid <<endl;
    if(mid==0) return 0;
    long long a = 2*mid +2*r-1;
    long long b = t/mid;
    if(a<=b) return 1;
    else return 0;
}
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
    int d;
    scanf(" %d",&d);
    int k = 0;
    while(d--)
    {
        k++;
        scanf(" %lld %lld",&r,&t);
        long long ll = 0;
        long long rr = t;
        long long mid;
        long long ans = 0;
        while(ll<=rr)
        {
            mid = (ll+rr)/2;
            if(ll==0 && rr==1) mid = 1;
            if(check(mid))
            {

                ans = mid;
                ll = mid +1;
            }
            else
                rr = mid - 1;

        }
        printf("Case #%d: %lld\n",k,ans);
    }
    //fclose(stdin);
    return 0;
}
