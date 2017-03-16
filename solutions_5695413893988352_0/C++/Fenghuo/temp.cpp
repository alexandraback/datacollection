#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <set>
#include <vector>
using namespace std;

string ccc,jjj;
string cc,jj;
long long c;
long long j;
long long d;

long long tran(string s)
{
    long long result=0;
    for (int i=0;i<s.size();i++)
    {
        result*=10;
        result+=(s[i]-'0');
    }
    return result;
}

void go(int p)
{
    if (p==cc.size())
    {
        long long tempc=tran(cc);
        long long tempj=tran(jj);
        long long tempd=tempc-tempj;
        if (tempd<0) tempd*=-1;

        if (tempd<d)
        {
            d=tempd;
            c=tempc;
            j=tempj;
            ccc=cc;
            jjj=jj;
        }
        else if(tempd==d)
        {
            if (tempc<c)
            {
                d=tempd;
                c=tempc;
                j=tempj;
                ccc=cc;
                jjj=jj;
            }
            else if (tempc==c)
            {
                if (tempj<j)
                {
                    d=tempd;
                    c=tempc;
                    j=tempj;
                    ccc=cc;
                    jjj=jj;
                }
            }
        }
    }

    else
    {
        if (cc[p]=='?' && jj[p]=='?')
        {
            cc[p]='0';
            jj[p]='0';
            go(p+1);
            cc[p]='0';
            jj[p]='1';
            go(p+1);
            cc[p]='1';
            jj[p]='0';
            go(p+1);
            cc[p]='9';
            jj[p]='0';
            go(p+1);
            cc[p]='0';
            jj[p]='9';
            go(p+1);
            cc[p]='?';
            jj[p]='?';
        }

        else if (cc[p]=='?' && jj[p]!='?')
        {
            cc[p]=jj[p]+1;
            if (jj[p]=='9') cc[p]='0';
            go(p+1);
            cc[p]=jj[p]-1;
            if (jj[p]=='0') cc[p]='9';
            go(p+1);
            cc[p]=jj[p];
            go(p+1);
            cc[p]='0';
            go(p+1);
            cc[p]='9';
            go(p+1);
            cc[p]='?';
        }

        else if (jj[p]=='?' && cc[p]!='?')
        {
            jj[p]=cc[p]+1;
            if (cc[p]=='9') jj[p]='0';
            go(p+1);
            jj[p]=cc[p]-1;
            if (cc[p]=='0') jj[p]='9';
            go(p+1);
            jj[p]=cc[p];
            go(p+1);
            jj[p]='0';
            go(p+1);
            jj[p]='9';
            go(p+1);
            jj[p]='?';
        }

        else
        {
            go(p+1);
        }
    }
}

int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("op.txt", "w", stdout);

    long long T,t,tt;
    long long i,j,k;

    cin>>T;
    for(tt=1;tt<=T;tt++)
    {
        cc.clear();
        jj.clear();
        ccc.clear();
        jjj.clear();
        cin>>cc;
        cin>>jj;

        c=1000000000000000000;
        j=1000000000000000000;
        d=1000000000000000000;
        go(0);


        cout<<"Case #"<<tt<<": "<<ccc<<" "<<jjj<<endl;


    }


    return 0;
}


