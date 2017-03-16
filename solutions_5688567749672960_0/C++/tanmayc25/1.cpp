#include<bits/stdc++.h>
using namespace std;

long long flip(long long n)
{
    int arr[15];
    int i=0;
    while(n)
    {
        arr[i++]=n%10;
        n/=10;
    }
    long long res=0, p=1;
    for(int j=i-1;j>=0;j--)
    {
        res+=(arr[j]*p);
        p*=10;
    }
    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    long long n;
    long long ans=0;
    cin >> t;
    for(int tt=1;tt<=t;tt++)
    {
        cin >> n;
        long long itr=1;
        ans=1;
        while(itr!=n)
        {
            long long temp=flip(itr);
            if(temp<=n)
                itr=max(itr+1,temp);
            else
                itr=itr+1;
            ans++;
        }
        cout << "Case #"<< tt << ": " << ans<<endl;
    }
    return 0;
}
