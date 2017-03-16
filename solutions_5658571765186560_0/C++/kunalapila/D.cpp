#include<bits/stdc++.h>

using namespace std;

#define s(n) scanf("%d",&n)

int main()
{
    int T, X, R, C;
    s(T);
    for(int i=1;i<=T;i++)
    {
        cout<<"Case #"<<i<<": ";
        s(X);
        s(R);
        s(C);
        if(X==1)
            cout<<"GABRIEL\n";
        else if(X==2)
        {
            if((R*C)%X==0)
                cout<<"GABRIEL\n";
            else
                cout<<"RICHARD\n";
        }
        else if(X==3)
        {
            if((R*C)%X!=0)
                cout<<"RICHARD\n";
            else if(R*C==3)
                cout<<"RICHARD\n";
            else
                cout<<"GABRIEL\n";
        }
        else
        {
            if((R*C)%X!=0)
                cout<<"RICHARD\n";
            else if((R*C)==4 || R*C==8)
                cout<<"RICHARD\n";
            else
                cout<<"GABRIEL\n";
        }

    }
}
