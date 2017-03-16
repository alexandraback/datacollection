#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for( int i=1;i<=t;++i )
    {
        int n,s,p;
        cin>>n>>s>>p;
        int ans = 0;
        if( p==0 )
        {
            ans = n;
            while(n--) cin>>s;
            cout<<"Case #"<<i<<": "<<ans<<endl;
            continue;
        }
        while(n--)
        {
            int g;
            cin>>g;
            if( g/3>=p ) ++ans;
            else if( s && g && g%3==0 && g/3+1>=p )
            {
                ++ans;--s;
            }
            else if( g%3==2 )
            {
                if( g/3+1>=p ) ++ans;
                else if ( s && g/3+2>=p ) ++ans,--s;
            }
            else if( g%3==1 && g/3+1>=p )
                ++ans;

        }
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
}
