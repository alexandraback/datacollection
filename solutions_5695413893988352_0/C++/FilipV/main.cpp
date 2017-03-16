#include <bits/stdc++.h>

using namespace std;

int sol=99999;
string asol,bsol;
int get(string a)
{
    int ret=0;
    for(int i=0;i<a.length();i++)
    {
        ret*=10;
        ret+=(a[i]-'0');
    }
    return ret;
}
void solve(int idx,string a,string b)
{
    if(idx==a.length())
    {
        int aval=get(a);
        int bval=get(b);
        if(abs(aval-bval)==sol)
        {
            if(asol>a)
            {
                asol=a;
                bsol=b;
            }
            if(bsol>b)
            {
                bsol=b;
            }
        }
        if(abs(aval-bval)<sol)
        {
            sol=abs(aval-bval);
            asol=a;
            bsol=b;
        }

        return;
    }
    bool aques=(a[idx]=='?'),bques=(b[idx]=='?');
    for(int i=0;i<=9;i++)
    {

        for(int j=0;j<=9;j++)
        {
            if(aques)a[idx]=i+'0';
            if(bques)b[idx]=j+'0';
            solve(idx+1,a,b);
        }
    }
}

int main()
{
    int t,testno=1;
    freopen("in.in","r",stdin);
  freopen("out.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        sol=9999;
        solve(0,a,b);
        cout<<"Case #"<<testno++<<": ";
        cout<<asol<<" "<<bsol<<endl;;
    }
    return 0;
}
