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
int z(int i,int n)
{
    int ct=0;
    while(n>0)
    {
        if(i%2==0)
        {
            ct++;
        }
        i/=2;
        n/=2;
    }
    return ct;
}
int main()
{
freopen("ix3.in","r",stdin);
freopen("ox.in","w",stdout);
    int t;
    string s1,s2,g1,g2;
    cin>>t;
    int tc=1;
    while(t--)
    {
        int n,ans=-1;
        cin>>n;
        string s1[30],s2[30];
        fora(i,n)
        {
            cin>>s1[i]>>s2[i];
        }
        int flag=0;
        for(int i=0; i<(1<<n); i++)
        {
            set<string>x,y;
            flag=0;
            int ct=0;
            for(int j=0; j<n; j++)
            {
                if(i&(1<<j))
                {
                    x.insert(s1[j]);
                    y.insert(s2[j]);
                }
                else
                {
                    ct++;
                }
            }
            if(ct>ans)
            {
                for(int j=0; j<n; j++)
                {
                    if((i&(1<<j))==0)
                    {
                    /*    if(i==3)
                        {
                            cout<<"YES";
                            cout<<s1[j]<<" "<<s2[j]<<endl;
                        }*/


                        if(x.find(s1[j])==x.end() || y.find(s2[j])==y.end() )
                        {
                            flag=1;
                            break;
                        }
                    }

                }
                if(flag==0)
                {
                    ans=ct;
                }
            }
        }

        cout<<"Case #"<<tc<<": "<<ans<<endl;
        tc++;
    }
    return 0;
}
