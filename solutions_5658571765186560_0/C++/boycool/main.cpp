#include<bits/stdc++.h>
using namespace std;
const int INF = 1000*1000*1000;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
int  _pow(int base, int exp){return exp == 0 ? 1 : base * _pow(base, exp - 1);}
int prime(int p)
{
    int c=0;
    for(int i=1;i<=sqrt(p);i++)
    {
        if(p%i==0 and p!=1)
            c++;
    }
    if(c==1) return 1;
    return 0;
}
int solve()
{
    int x,r,c;
    cin>>x>>r>>c;
    if(x==1)
        cout<<"GABRIEL";

    else if(x==2 )
        {if((r==1 && c==3)|| (r==3 && c==1)|| (r==3 && c==3)|| (r==1 && c==1))
            cout<<"RICHARD";
        else cout<<"GABRIEL";
        }

    else if(x==3 )
    {if((r==2 && c==3)|| (r==3 && c==2)|| (r==3 && c==3) || (r==3 && c==4) || (r==4 && c==3))
            cout<<"GABRIEL";
            else cout<<"RICHARD";}
    else if(x==4 )
    {
        if((r==3 && c==4)|| (r==4 && c==3)|| (r==4 && c==4)) cout<<"GABRIEL";
        else cout<<"RICHARD";
    }

}
int main()
{
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        printf("Case #%d: ",c);
        int g=solve();

        cout<<endl;
    }
   return 0;
}




























