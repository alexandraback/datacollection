#include<bits/stdc++.h>
using namespace std;
typedef long long lli;

int len,C1,J1,ans;
string c,j,C,J;

void func(int x,string s)
{
    int i,val,val1;

    if(x==2*len)
    {
       // cout<<s<<"\n";
        val=val1=0;

        for(i=0; i<len; i++)
            val=val*10+(s[i]-'0');

        for(i=len; i<2*len; i++)
            val1=val1*10+(s[i]-'0');

        if(ans>abs(val-val1))
        {
            ans=abs(val-val1);
            for(i=0; i<len; i++)
                c[i]=s[i];

            C1=val;
            for(i=len; i<2*len; i++)
                j[i-len]=s[i];
            J1=val1;
        }
        else if(ans==abs(val-val1))
        {
            if(val<C1)
            {
                for(i=0; i<len; i++)
                    c[i]=s[i];

                C1=val;
                for(i=len; i<2*len; i++)
                    j[i-len]=s[i];
                J1=val1;
            }
            else if(val==C1 && val1<J1)
            {
                for(i=0; i<len; i++)
                    c[i]=s[i];

                C1=val;
                for(i=len; i<2*len; i++)
                    j[i-len]=s[i];
                J1=val1;
            }
        }
        return ;
    }


    if(s[x]=='?')
    {
        for(int j=0; j<10; j++)
        {
        s[x]=j+'0';
        func(x+1,s);
        s[x]='?';
        }
    }
    else
        func(x+1,s);
}

int t,X,i;
string str;

int main()
{
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d",&t);

    while(t--)
    {
        X++;
        printf("Case #%d: ",X);

        ans=C1=J1=10000000;

        cin>>C>>J;
        len=C.length();

        str="";
        for(i=0; i<len; i++)
            str.push_back(C[i]);
        for(i=0; i<len; i++)
            str.push_back(J[i]);

        c=C;
        j=J;

        func(0,str);
        cout<<c<<" "<<j<<"\n";
    }
    return 0;
}
