#include <bits/stdc++.h>
using namespace std;
long long k, c, s;
int test;
int main()
{
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>k>>c>>s;
        long long hat=1;
        for(int i=1; i<c; i++) hat*=k;
        cout<<"Case #"<<tt<<":";
        long long akt=1;
        for(int i=1; i<=s; i++)
        {
            cout<<" "<<akt;
            akt+=hat;
        }
        cout<<endl;
    }

    return 0;
}
