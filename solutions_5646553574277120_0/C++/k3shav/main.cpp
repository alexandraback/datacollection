#include <bits/stdc++.h>
#define pb          emplace_back
#define TEST        long t,T;cin>>T;for(t=1;t<=T;t++)
#define X           first
#define Y           second
#define pi          3.141592653589793238462643383279

using namespace std;

int msb (long long v)
{
    int r=0;
    while (v >>= 1)
    {
        r++;
    }
    return r;
}


int main()
{
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    TEST
    {
        int c,d,v,ans=0;
        cout<<"Case #"<<t<<": ";
        cin>>c>>d>>v;
        
        vector <long long> a(d);
        
        for(int i=0 ; i<d ; i++)
        {
            cin>>a[i];
        }
        
        sort(a.begin(),a.end());
        
        if (a[0]!=1)
        {
            ans++;
            a.insert(a.begin(), 1);
        }
        
        long long lsum=1;
        
        for(int i=1 ; i<d ; i++)
        {
            long long x=a[i-1];
            while (lsum<a[i]-1)
            {
                ans++;
                x=1<<(msb(a[i])-1);
                lsum+=x;
            }
            lsum+=a[i];
        }
        long long x=1<<(msb(a[d-1])+1);
        
        while (lsum<v)
        {
            ans++;
            lsum+=x;
            x<<=1;
        }
        cout<<ans<<"\n";
        
    }
    
    
    
}
