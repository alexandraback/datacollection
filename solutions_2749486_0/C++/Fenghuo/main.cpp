#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;



int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("op.txt", "w", stdout);

    int T,TT;
    long long i,j,k;
    long long x,y,n;


    cin>>T;TT=1;
    while (T--)
    {
        string s;
        cin>>x>>y;

        if (x<0) j=-x;
        else j=x;

        if (y<0) k=-y;
        else k=y;

        cout<<"Case #"<<TT<<": ";
        for (i=0;i<j;i++)
        {
            if (x<0) cout<<"EW";
            else cout<<"WE";
        }
        for (i=0;i<k;i++)
        {
            if (y<0) cout<<"NS";
            else cout<<"SN";
        }
        cout<<endl;
        TT++;
    }

    return 0;
}
