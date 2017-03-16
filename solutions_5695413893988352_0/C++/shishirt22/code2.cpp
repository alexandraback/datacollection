#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mp make_pair
#define lf long double
#define VI vector<ll>
#define ppl pair<ll,ll>
#define ppi pair<int,int>
#define  F first
#define S Second
#define ML map<ll,ll>
#define itm map<ll,ll>::iterator
#define f_inp ios_base::sync_with_stdio(false)
int ans1,ans2,diff;
string r1,r2;
string str1,str2;
int comp2(int a,int num,int num2)
{
    if(a==str2.length())
    {
        if(diff>abs(num-num2))
        {
            diff=abs(num-num2);
            ans2=num;
            r1=str1;
            r2=str2;
            ans1=num2;

        }
        else if(diff==abs(num-num2))
        {
            if(ans1>num2)
            {
                ans1=num2;
                r1=str1;
                r2=str2;
                ans2=num;
            }
        }
        return 0;
    }
    else
    {
        if(str2[a]!='?')
            comp2(a+1,num*10+(str2[a]-'0'),num2);
        else
        {
            int i;
            for(i=0;i<10;i++)
            {
                str2[a]='0'+i;
                comp2(a+1,num*10+i,num2);
                str2[a]='?';
            }
        }
    }
}
int comp(int a,int num)
{
    if(a==str1.length())
    {
       // cout<<"HELLO";
        comp2(0,0,num);
        return 0;
    }
    else
    {
        if(str1[a]!='?')
            comp(a+1,num*10+(str1[a]-'0'));
        else
        {
            int i;
            for(i=0;i<10;i++)
            {
                str1[a]='0'+i;
                comp(a+1,num*10+i);
                str1[a]='?';
            }
        }
    }
}
int main()
{
    f_inp;
    ll n,m,a,b,c,d;
   freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
  cin>>n;
  int test=1;
  while(n>0)
  {
      n--;
      ans1=ans2=diff=100000;
      cin>>str1>>str2;
      comp(0,0);
      cout<<"Case #"<<test<<": "<<r1<<" "<<r2<<endl;
      test++;
  }
    return 0;

}
