//
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<climits>
#include<fstream>
#include<iomanip>
#include<queue>
#include<stack>
#define lli long long

using namespace std;

string s,s1;
vector<int>v,v1;

void rec(int k,int x)
{
    if(k==s.size())
    {
        v.push_back(x);
        return;
    }
    if(s[k]!='?')
    {
        rec(k+1,x*10+s[k]-'0');
        return;
    }

    for(int i=0;i<=9;i++)
    {
        rec(k+1,x*10+i);
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("B.in");
    ofstream cout("B.out");

    lli mn,T,Ans,Ans1,c,c1,p,p1;
    cin>>T;

    for(int t1=1;t1<=T;t1++)
    {
        cout<<"Case #"<<t1<<": ";
        v.clear();
        v1.clear();

        mn=LLONG_MAX;

        cin>>s1;
        s=s1;
        rec(0,0);
        v1=v;
        v.clear();

        cin>>s;
        rec(0,0);

        for(int i=0;i<v1.size();i++)
        {
            for(int j=0;j<v.size();j++)
            {
                if(abs(v1[i]-v[j])==mn)
                {
                    if(v1[i]==Ans)
                    {
                        if(v[j]<Ans1)Ans1=v[j];
                    }
                    else if(v1[i]<Ans){ Ans=v1[i]; Ans1=v[j];}

                }
                if(abs(v1[i]-v[j])<mn)
                {
                    mn=abs(v1[i]-v[j]);
                    Ans=v1[i];
                    Ans1=v[j];
                }
            }
        }

        c=0; c1=0; p=Ans; p1=Ans1;
        if(Ans==0)c=1;
        if(Ans1==0)c1=1;

        while(p)
        {
            p/=10;
            c++;
        }
        while(p1)
        {
            p1/=10;
            c1++;
        }

        for(int i=0;i<s1.size()-c;i++)cout<<0;
        cout<<Ans<<" ";
        for(int i=0;i<s.size()-c1;i++)cout<<0;
        cout<<Ans1<<"\n";



    }

    return 0;
}


