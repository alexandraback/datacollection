#include<bits/stdc++.h>
//Definitions
#define LL long long
#define LLU unsigned long long
#define fora(var,end) for(int var=0;var<end;var++)
#define fore(var,start,end) for(int var=start;var<end;var++)
#define forit(it1,a) for(typeof(a.begin()) it1=a.begin();it1!=a.end();it1++)
#define pub push_back
#define fst first
#define snd second
#define MOD 1000000007
#define mkp make_pair
#define beg begin
#define ed end
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define P(a,b) cout<<a<<" "<<b<<" "
#define PNL printf("\n")
#define vi vector<int>
#define vpi vector<pair<pair<int,int>,int> >
#define FL(a,n,x) fill(a,a+n,x)
#define db1(a) cout<<#a<<":"<<a<<endl;
#define db2(a,b) cout<<#a<<":"<<a<<" , "<<#b<<" : "<<b<<endl;
#define db3(a,b,c) cout<<#a<<":"<<a<<" , "<<#b<<":"<<b<<" , "<<#c<<":"<<c<<endl;
//AP_HAWKDOWN from hereon
using namespace std;
string TS(int x,int len)
{
    string str;
    int ct=3;
    while(len--)
    {
        str+=char(x%10)+'0';
        x/=10;
    }
    reverse(str.begin(),str.end());
    return str;
}

int main()
{
freopen("ix2.in","r",stdin);
freopen("ox.in","w",stdout);
    int t;
    string s1,s2,g1,g2;
    cin>>t;
    int tc=1;
    int ans[30];
    while(t--)
    {
        int mn=INT_MAX,x,y;
        cin>>s1>>s2;
        int len=s1.length();
        int mx=1;
        for(int i=0; i<len; i++)
        {
            mx*=10;
        }
        mx--;
        int flag=0;
        for(int i=0; i<=mx; i++)
        {
            flag=0;
            g1=TS(i,len);
            //cout<<i<<" "<<g1<<endl;
            for(int k=0; k<len; k++)
            {
                if(s1[k]=='?'||(s1[k]==g1[k]))
                {

                }
                else
                {
                    flag=1;
                    break;
                }

            }
            if(flag==0)
            {
              //  cout<<"YES"<<" "<<g1<<endl;
                for(int j=0; j<=mx; j++)
                {
                    flag=0;
                    g2=TS(j,len);
                   // cout<<g2<<" "<<j<<endl;

                    for(int k=0; k<len; k++)
                    {
                        if(s2[k]=='?'||(s2[k]==g2[k]))
                        {

                        }
                        else
                        {
                            flag=1;
                            break;

                        }
                    }
                    if(flag==0&&abs(i-j)<mn)
                    {
                      //  cout<<"YES";
                        x=i;
                        y=j;
                    //    cout<<"hello"<<" "<<TS(x,len)<<" "<<TS(y,len);
                        mn=abs(i-j);
                    }
                }
            }
        }
        cout<<"Case #"<<tc<<": "<<TS(x,len)<<" "<<TS(y,len)<<endl;
        tc++;
    }
    return 0;
}
