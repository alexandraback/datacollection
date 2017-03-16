#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char v[5] = {'a','e','i','o','u'},s[1100000];
int f[1100000];
int main()
{
    freopen("B1.in","r",stdin);
    freopen("B1.txt","w",stdout);
    int T;
    cin>>T;
    for (int cas = 1; cas <= T; cas++){
        int x,y,i;
        cin>>x>>y;
        //cout<<x<<y;
        cout<<"Case #"<<cas<<": ";
        string sx,sy;
        if (x < 0) sx = "EW";
        else sx = "WE";
        if (y < 0) sy = "NS";
        else sy = "SN";
        for (i = 0; i < abs(x); i++) cout<<sx;
        for (i = 0; i < abs(y); i++) cout<<sy;
        cout<<endl;
    }
    return 0;
}
