#include <bits/stdc++.h>
#define pb          emplace_back
#define TEST        long t,T;cin>>T;for(t=1;t<=T;t++)
#define X           first
#define Y           second
#define pi          3.141592653589793238462643383279

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    TEST
    {
        int w,r,c,j=0;
        cout<<"Case #"<<t<<": ";
        cin>>r>>c>>w;
        int k=0;
            for( j=w-1 ; j<c ; j+=w)
            {
                k++;
            }
        
        cout<<r*k+w-(c%w==0)<<endl;
        
        
    }
    
    
    
}
