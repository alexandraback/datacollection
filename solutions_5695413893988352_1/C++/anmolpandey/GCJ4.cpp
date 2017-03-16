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

int main()
{
freopen("ix.in","r",stdin);
freopen("ox.in","w",stdout);
    int t;
    string s1,s2,g1,g2;
    cin>>t;
    int tc=1;
    while(t--)
    {
        cin>>s1>>s2;
        int  tk=0,left;
        int len=s1.length();
        for(int i=0;i<len;i++)
        {
            if(s1[i]=='?'&&s2[i]=='?' & tk==0)
            {
                s1[i]='0';
                s2[i]='0';
                continue;
            }
            if(s1[i]=='?' && tk==0)
            {
                s1[i]=s2[i];
                continue;
            }

            if(s2[i]=='?' && tk==0)
            {
                s2[i]=s1[i];
                continue;
            }
            if(s1[i]!=s2[i] && tk==0)
            {

                if(s1[i]>s2[i])
                {
                    left=1;
                }
                else
                {
                    left=0;
                }
                tk=1;
                continue;
            }
            if(s1[i]=='?'&&s2[i]=='?' & tk==1)
            {
                if(left==1){
                s1[i]='0';
                s2[i]='9';
                }
                else
                {
                s1[i]='9';
                s2[i]='0';
                }
                continue;
            }
            if(s1[i]=='?' && tk==1)
            {
                if(left==1){
                s1[i]='0';
               // s2[i]='9';
                }
                else
                {
                s1[i]='9';
               // s2[i]='0';
                }
                continue;

            }

            if(s2[i]=='?' && tk==1)
            {   if(left==1){
                //s1[i]='0';
                s2[i]='9';
                }
                else
                {
               // s1[i]='9';
                s2[i]='0';
                }
                continue;

            }


        }
        cout<<"Case #"<<tc<<": "<<s1<<" "<<s2<<endl;
        tc++;
    }
    return 0;
}
