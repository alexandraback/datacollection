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
int f[400];
void rm(int x,string s[10])
{
    for(int i=0;i<s[x].size();i++)
    {
        f[s[x][i]]--;
    }
}
int main()
{
freopen("ix.in","r",stdin);
freopen("ox.in","w",stdout);
string s[10]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
int t;
cin>>t;
int tc=1;
int ans[30];
while(t--)
{
    for(int i=0;i<400;i++)
    {
        f[i]=0;
    }
    string str;
    cin>>str;
    int  len=str.length();

    for(int i=0;i<len;i++)
    {
        f[str[i]]++;
    }

    ans[0]=f['Z'];
    for(int j=0;j<ans[0];j++)
    rm(0,s);
    ans[2]=f['W'];
    for(int j=0;j<ans[2];j++)
    rm(2,s);
    ans[6]=f['X'];
    for(int j=0;j<ans[6];j++)
    rm(6,s);
    ans[8]=f['G'];
    for(int j=0;j<ans[8];j++)
    rm(8,s);
    ans[7]=f['S'];
    for(int j=0;j<ans[7];j++)
    rm(7,s);
    ans[5]=f['V'];
    for(int j=0;j<ans[5];j++)
    rm(5,s);
    ans[9]=f['I'];
    for(int j=0;j<ans[9];j++)
    rm(9,s);
    ans[4]=f['F'];
    for(int j=0;j<ans[4];j++)
    rm(4,s);
    ans[3]=f['R'];
    for(int j=0;j<ans[3];j++)
    rm(3,s);
    ans[1]=f['O'];
    for(int j=0;j<ans[1];j++)
    rm(1,s);
    /*for(int i=0;i<26;i++)
    {
        cout<<char('A'+i)<<" "<<f['A'+i]<<endl;
    }*/
    string fans="";
    for(int i=0;i<=9;i++)
    {
    //    cout<<ans[i]<<" ";
        for(int j=0;j<ans[i];j++)
        {
            fans+=char('0'+i);
        }
    }
    cout<<"Case #"<<tc<<": "<<fans<<endl;
    tc++;
}
return 0;
}
