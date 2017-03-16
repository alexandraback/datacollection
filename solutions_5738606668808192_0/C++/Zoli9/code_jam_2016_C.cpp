#include <bits/stdc++.h>
using namespace std;
int jegy, mennyi;
int main()
{
    int aaa;
    cin>>aaa;
    cin>>jegy>>mennyi;
    cout<<"Case #1:"<<endl;
    for(int j=1; j<=mennyi; j++)
    {
        cout<<"1";
        int akt=j;
        for(int l=1; l<=(jegy-2)/2; l++)
        {
            if(akt%2) cout<<"11";
            else cout<<"00";
            akt/=2;
        }
        cout<<"1";
        for(int u=3; u<=11; u++)
        {
            cout<<" "<<u;
        }
        cout<<endl;
    }
    return 0;
}
