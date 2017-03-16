#include <iostream>
using namespace std;

int main()
{
    int numOfCases;
    cin>>numOfCases;
    for(int i=1; i<=numOfCases; ++i)
    {
        long long r, t;
        cin>>r>>t;
        long long left=1, right=707106780, mid, ans=1;
        while(left<=right)
        {
            mid=(left+right)/2;
            long long a = -2*mid*mid+t;
            a/=mid;
            if(a>=2*r-1)
            {
                ans=ans>mid?ans:mid;
                left=mid+1;
            } else
            {
                right=mid-1;
            }
        }
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
    return 0;
}
