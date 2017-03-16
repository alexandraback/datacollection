#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;



int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("op.txt", "w", stdout);

    int T,TT;
    int i,j,k;
    int x,y,n,r,cc;
    int st;


    cin>>T;TT=1;
    while (T--)
    {
        string s;
        cin>>s>>n;
        r=0;cc=0;st=0;

        for (i=0;i<s.size();i++)
        {
            if (s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u') cc++;
            else {cc=0;}
            if (cc>=n) {st=i-n+2;}
            r+=st;
        }

        cout<<"Case #"<<TT<<": "<<r<<endl;
        TT++;
    }

    return 0;
}
