//Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
using namespace std;

string aa,ss;
vector<int>vec;
int ar[100],pr[100];

int check(int i)
{
    int n,j;
    n=aa.size();
    vec.clear();
    for(j=0;j<n;j++)
    {
        vec.push_back(i%10);
        i/=10;
    }

    reverse(vec.begin(),vec.end());

    for(j=0;j<n;j++)
    {
        if(ar[j]==-1) continue;
        if(ar[j]!=vec[j]) return 0;
    }
    return 1;
}

int checkk(int i)
{
    int n,j;
    n=ss.size();
    vec.clear();
    for(j=0;j<n;j++)
    {
        vec.push_back(i%10);
        i/=10;
    }

    reverse(vec.begin(),vec.end());

    for(j=0;j<n;j++)
    {
        if(pr[j]==-1) continue;
        if(pr[j]!=vec[j]) return 0;
    }
    return 1;
}

void prnt(int i,int n)
{
    int j;
    vec.clear();
    for(j=0;j<n;j++)
    {
        vec.push_back(i%10);
        i/=10;
    }
    reverse(vec.begin(),vec.end());

    for(j=0;j<n;j++)
    {
        cout<<vec[j];
    }

}

int main()
{
    freopen("out.txt","rt",stdin);
    freopen("out1.txt","wt",stdout);
    int i,j,k,l,n,cas,test,flag,temp,tot;
    pair<int,pair<int,int> > ans,now;

    cin>>test;
    for(cas=1;cas<=test;cas++)
    {
        cin>>aa>>ss;

        for(i=0;i<aa.size();i++)
        {
            ar[i]=aa[i]-'0';
            if(aa[i]=='?') ar[i]=-1;
        }

        for(i=0;i<ss.size();i++)
        {
            pr[i]=ss[i]-'0';
            if(ss[i]=='?') pr[i]=-1;
        }

        n=aa.size();

        if(n==1) tot=9;
        if(n==2) tot=99;
        if(n==3) tot=999;

        ans=make_pair(1000000000,make_pair(1000000000,1000000000));

        for(i=0;i<=tot;i++)
        {
            for(j=0;j<=tot;j++)
            {
                if(check(i) && checkk(j))
                {
                    now=make_pair(abs(i-j),make_pair(i,j));
                    if(now<ans) ans=now;
                }
            }
        }

        printf("Case #%d: ",cas);
        prnt(ans.second.first,n);
        cout<<" ";
        prnt(ans.second.second,n);
        cout<<endl;

    }



}
