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
    bool a=true;
    if(x>=7)
        a=false;
    else if(x > r and x > c)
        a=false;
    else if(r * c % x != 0)
        a=false;
    else if (floor((x + 1) / 2) > min(r, c))
        a = false;
    else if (x ==1||x== 2||x== 3)
        a = true;
    else if (x == 4)
        a = min(r, c) > 2;
    else if (x == 5)
        a = not(min(r, c) == 3 and max(r, c) == 5);
    else if (x == 6)
        a = min(r, c) > 3;
    if(a) cout<<"GABRIEL";
    else cout<<"RICHARD";
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




























