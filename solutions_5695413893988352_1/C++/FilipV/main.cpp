#include <bits/stdc++.h>

using namespace std;

long long sol=99999;
string asol,bsol;
long long abss(long long x)
{
    if(x<0)return -x;
    return x;
}
long long get(string a)
{
    long long ret=0;
    for(int i=0; i<a.length(); i++)
    {
        ret*=10;
        ret+=(a[i]-'0');
    }
    return ret;
}
void updateSol(string a,string b)
{
    long long aval=get(a);
    long long bval=get(b);
    if(abss(aval-bval)==sol)
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
    if(abss(aval-bval)<sol)
    {
        sol=abss(aval-bval);
        asol=a;
        bsol=b;
    }

}
string fillString(string x,int dig)
{
    for(int i=0; i<x.length(); i++)
        if(x[i]=='?')x[i]='0'+dig;
    return x;
}
void solve(int idx,string a,string b)
{
    //printf("%d\n")
    if(idx==a.length())
    {
        updateSol(a,b);
        return;
    }
    bool aques=(a[idx]=='?'),bques=(b[idx]=='?');
    if(!aques&&!bques)
    {
        if(a[idx]==b[idx])solve(idx+1,a,b);
        else
        {
            if(a[idx]<b[idx])
                updateSol(fillString(a,9),fillString(b,0));
            else updateSol(fillString(a,0),fillString(b,9));
        }
        return;
    }
    if(aques&&bques)
    {
        a[idx]='0';
        b[idx]='0';
        solve(idx+1,a,b);
        a[idx]='1';
        b[idx]='0';
        updateSol(fillString(a,0),fillString(b,9));
        a[idx]='0';
        b[idx]='1';
        updateSol(fillString(a,9),fillString(b,0));
        return;
    }
    if(aques)
    {
        a[idx]=b[idx]-1;
        if(isdigit(a[idx]))updateSol(fillString(a,9),fillString(b,0));
        a[idx]=b[idx]+1;
        if(isdigit(a[idx]))updateSol(fillString(a,0),fillString(b,9));
        a[idx]=b[idx];
        solve(idx+1,a,b);
        return;
    }
    if(bques)
    {
        b[idx]=a[idx]-1;
        if(isdigit(b[idx]))updateSol(fillString(a,0),fillString(b,9));
        b[idx]=a[idx]+1;
        if(isdigit(b[idx]))updateSol(fillString(a,9),fillString(b,0));
        b[idx]=a[idx];
        solve(idx+1,a,b);
        return;
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
        sol=1000000000000000000LL;
        solve(0,a,b);
        cout<<"Case #"<<testno++<<": ";
        cout<<asol<<" "<<bsol<<endl;;
    }
    return 0;
}
