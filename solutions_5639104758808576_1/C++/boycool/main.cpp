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
    int sm;int coun=0,valuetr=0;
    cin>>sm;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        int a=s[i]-48;
        //cout<<a<<" ";
        if(i==0)
        {
            valuetr+=a;
        }
        else{
                int t=0;
            if(i>=valuetr && a>0)
            {
                coun+=i-valuetr;
                t=i-valuetr;
            }
            valuetr+=a+t;
        }
        //cout<<valuetr<<" ";
    }
    cout<<coun;

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




























