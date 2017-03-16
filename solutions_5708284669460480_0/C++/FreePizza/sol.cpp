#include<bits/stdc++.h>
using namespace std;
typedef string ss;
typedef long long ll;
long long pow(long long b,long long p)
{
    if(!p)
        return 1;
    long long sq=pow(b,p/2);
    sq*=sq;
    if(p%2)
        sq*=b;
    return sq;
}
long int t,k,l,s,cnt,temp,tot,mx;
string s1,s2,s3;
void solve()
{
    if (s3.length()==s)
    {
        temp=0;
        for(long int i=0;i<s;i++)
            if(s3.substr(i,l)==s2)
            {
                ++cnt;
                ++temp;
            }
        mx=max(mx, temp);
        return;
    }
    for(long int i=0;i<k;i++)
    {
        s3+=s1[i];
        solve();
        s3.pop_back();
    }
}
int main()
{
    cin >> t;
    for(long int i=1;i<=t;i++)
    {
        cin >> k >> l >> s>>s1>>s2;
        cnt =0;
        mx = 0;
        tot = pow(k,s);
        solve();
        cout<<"Case #"<<i<<": ";
        cout<<fixed<<setprecision(12)<<mx-double(cnt)/tot<<"\n";
    }
}
