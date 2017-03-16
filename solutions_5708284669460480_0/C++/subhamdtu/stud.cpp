#include<bits/stdc++.h>
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define p(n) printf("%d\n",n)
#define ll long long
#define pb push_back
#define mp make_pair

#define LN 21
ll mod=1000000007;
using namespace std;
string s1,s2;
int k,l,ss;
ll num,ban;
ll check(string tmp)
{
    //cout<<tmp<<endl;
    int i,j;
    ll an=0;
    for(i=0;i<tmp.length();++i)
    {
        if(i+s2.length()>tmp.length())
            break;
        int f=1;

        for(j=i;j<=i+s2.length()-1;++j)
                if(tmp[j]!=s2[j-i])
                {
                    f=0;
                    break;
                }

        if(f)
        an++;
    }
    return an;
}
void rec(string tmp,int id)
{
int i;
    if(id==ss)
    {
        num+=check(tmp);
        ban=max(ban,check(tmp));
        return;
    }
    for(i=0;i<s1.length();++i)
    {
        if(i==0)
        tmp.pb(s1[i]);
        else
            tmp[id]=s1[i];
        rec(tmp,id+1);
    }
}
int main()
{

   int t,i,p,j,r;


   cin>>t;

   for(p = 1 ;p<=t;++p)
   {

    cin>>k>>l>>ss;
cin>>s1>>s2;

printf("Case #%d: ",p);


         int has[26];
         memset(has,0,sizeof(has));
         for(i=0;i<s1.length();++i)
            has[s1[i]-'A']++;

         int f = 1;
         for(i=0;i<s2.length();++i)
         {
            if(has[s2[i]-'A']==0)
                f = 0;
         }

        if(f==0)
            cout<<"0.000000"<<endl;
        else
        {
             ban = 0;
            double tot = 1;
            for(i=1;i<=ss;++i)
                tot = tot * k;
            num = 0;
            string tmp;
             rec(tmp,0);
             double ans = (double)ban;
             double an1 = (double)num;
             an1 = an1/tot;
             ans = ans - an1;
             printf("%0.6lf\n",ans);
        }

   }



    return 0;
}
