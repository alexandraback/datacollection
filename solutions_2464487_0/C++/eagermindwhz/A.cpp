#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
    freopen("A.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    for (int cas = 1; cas <= T; cas++){
        long long r,t;
        cin>>r>>t;
        double dr = 1.0*r, dt=1.0*t, dn = ((1-2*dr)+sqrt((2*dr-1)*(2*dr-1)+8*t))/4;
        cout<<"Case #"<<cas<<": "<<(int)dn<<endl;
        /*long long tn = (int)dn, ans;
        for (i = -delta;i < delta; i++){
            ans =
        }*/
    }
    return 0;
}

