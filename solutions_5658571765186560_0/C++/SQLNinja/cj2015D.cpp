#include<iostream>
#include<cstdio>
using namespace std;
int main()
{

    freopen("D.in","r",stdin);
    freopen("D.out","w",stdout);
    int v;
    cin>>v;
    for(int t=1;t<=v;t++){
        int n,x,y;
        cin>>n>>x>>y;
        int s=x*y;
        cout<<"Case #"<<t<<": ";
        if(x<n-1||y<n-1||s%n)
            cout<<"RICHARD\n";
        else
            cout<<"GABRIEL\n";


    }
}
