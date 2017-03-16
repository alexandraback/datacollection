#include<iostream>
#include<stack>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<string>
#include<iomanip>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<cstring>
#include<time.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define pll pair<ll,ll>
#define ppll pair<ll, pair<ll,ll> >
#define inf 1000000007

ll convert(string s)
{
    ll num=0,i=0;
    while(i<s.length())
    {
        num+=int(s[i])-48;
        num*=10;
        i++;
    }
    num/=10;
    return num;
}

int main()
{
    ll t,i,j,k,n,flag,n1,n2,n3,n4;
    string code,jam,code1,jam1;
    cin>>t;
    for(k=1;k<=t;k++)
    {
        cin>>code>>jam;
        code1.assign(code);
        jam1.assign(jam);
        n=code.length();
        i=j=flag=0;
        while(i<n && j<n)
        {
            //cout<<i<<" "<<j<<" "<<flag<<endl;
            if(code[i]!=jam[i])
            {
                if(code[i]=='?' && flag==0)
                    code[i]=jam[i];
                else if(jam[i]=='?' && flag==0)
                    jam[i]=code[i];
                else if(jam[i]=='?' && flag==1)
                    jam[i]=code[i];
                else if(jam[i]=='?' && flag==-1)
                    jam[i]='0';
                else if(code[i]=='?' && flag==1)
                    code[i]='0';
                else if(code[i]=='?' && flag==-1)
                    code[i]=jam[i];
                else if(code[i]>jam[i])
                    flag=1;
                else if(jam[i]>code[i])
                    flag=-1;
            }
            else
            {
                if(code[i]=='?' && flag==0)
                    code[i]=jam[i]='0';
                else if(code[i]=='?' && flag==1)
                {
                    code[i]='0';
                    jam[i]='9';
                }
                else if(code[i]=='?' && flag==-1)
                {
                    code[i]='9';
                    jam[i]='0';
                }
            }
            i++;
            j++;
        }
        //cout<<code<<" "<<jam<<" ";
        while(i>=0 && j>=0)
        {
            //cout<<i<<" "<<j<<" "<<flag<<endl;
            if(code1[i]!=jam1[i])
            {
                if(code1[i]=='?' && flag==0)
                    code1[i]=jam1[i];
                else if(jam1[i]=='?' && flag==0)
                    jam1[i]=code1[i];
                else if(jam1[i]=='?' && flag==1)
                    jam1[i]=code1[i];
                else if(jam1[i]=='?' && flag==-1)
                    jam1[i]='0';
                else if(code1[i]=='?' && flag==1)
                    code1[i]='0';
                else if(code1[i]=='?' && flag==-1)
                    code1[i]=jam1[i];
                else if(code1[i]>jam1[i])
                    flag=1;
                else if(jam1[i]>code1[i])
                    flag=-1;
            }
            else
            {
                if(code1[i]=='?' && flag==0)
                    code1[i]=jam1[i]='0';
                else if(code1[i]=='?' && flag==1)
                {
                    code1[i]='0';
                    jam1[i]='9';
                }
                else if(code1[i]=='?' && flag==-1)
                {
                    code1[i]='9';
                    jam1[i]='0';
                }
            }
            i--;
            j--;
        }
        //cout<<code1<<" "<<jam1<<endl;
        n1=convert(code);
        n2=convert(jam);
        n3=convert(code1);
        n4=convert(jam1);
        //cout<<n1<<" "<<n2<<" "<<n3<<" "<<n4<<endl;
        if((abs(n1-n2)>abs(n3-n4)) || ((abs(n1-n2)==abs(n3-n4)) && (code.compare(code1)>0 || (code.compare(code1)==0 && jam.compare(jam1)>0))))
        {
            code.assign(code1);
            jam.assign(jam1);
        }
        cout<<"Case #"<<k<<": ";
        for(i=0;i<n;i++)
            cout<<code[i];
        cout<<" ";
        for(i=0;i<n;i++)
            cout<<jam[i];
        cout<<endl;
        code.clear();
        jam.clear();
    }
}
