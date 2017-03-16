#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int same(int a, string s)
{
    if(s.size()==3)
    {
        int b=a%10;
        if((b==s[2]-'0')||s[2]=='?')
        {
            a=a/10;
            b=a%10;
            if((b==s[1]-'0')||s[1]=='?')
            {
                a=a/10;
                b=a%10;
                if((b==s[0]-'0')||s[0]=='?')
                    return 1;
            }
        }
    }
    else if(s.size()==2 && a<100)
    {
        int b=a%10;
        if((b==s[1]-'0')||s[1]=='?')
        {
            a=a/10;
            b=a%10;
            if((b==s[0]-'0')||s[0]=='?')
            {
                return 1;
            }
        }
    }
    else if(s.size()==1 && a<10)
    {
        int b=a%10;
        if((b==s[0]-'0')||s[0]=='?')
        {
            return 1;
        }
    }
    return 0;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("in3.in", "r", stdin);
    freopen("out3.txt", "w", stdout);
    int t=1, i, l, j, k, a, b, n;
    cin>>t;
    string x, y, p, q;
    for(l=1; l<=t; l++)
    {
        k=1000;
        cin>>x>>y;
        n=x.size();
        for(i=0; i<1000; i++)
        {
            for(j=0; j<1000; j++)
            {
                if(same(i, x) && same(j, y))
                {
                    if(abs(i-j)<k || (abs(i-j)==k && i<a) || (abs(i-j)==k && i==a && j<b))
                    {
                        k=abs(i-j);
                        a=i;
                        b=j;
                    }
                }
            }
        }
        p="";
        q="";
        if(n==3)
        {
            if(a<10)
                p="00";
            else if(a<100)
                p="0";
            if(b<10)
                q="00";
            else if(b<100)
                q="0";
        }
        else if(n==2)
        {
            if(a<10)
                p="0";
            if(b<10)
                q="0";
        }
        cout<<"Case #"<<l<<": "<<p<<a<<" "<<q<<b<<endl;

    }
    return 0;
}
