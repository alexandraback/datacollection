#include<bits/stdc++.h>
using namespace std;
int mark[29];
vector<int> Ans;
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("CJ2A.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        string s;
        cin>>s;
        int l=s.length();
        for(int i=0;i<29;i++)
            mark[i]=0;
        for(int i=0;i<l;i++)
        {
            mark[s[i]-'A']++;
        }
        if(mark['Z'-'A'])
        {
           int ct=mark['Z'-'A'];
           for(int i=0;i<ct;i++)
            Ans.push_back(0);
           mark['E'-'A']-=ct;
           mark['R'-'A']-=ct;
           mark['O'-'A']-=ct;
           mark['Z'-'A']-=ct;
        }
        if(mark['W'-'A'])
        {
           int ct=mark['W'-'A'];
           for(int i=0;i<ct;i++)
            Ans.push_back(2);
           mark['T'-'A']-=ct;
           mark['W'-'A']-=ct;
           mark['O'-'A']-=ct;
        }
        if(mark['U'-'A'])
        {
           int ct=mark['U'-'A'];
           for(int i=0;i<ct;i++)
            Ans.push_back(4);
           mark['F'-'A']-=ct;
           mark['O'-'A']-=ct;
           mark['U'-'A']-=ct;
           mark['R'-'A']-=ct;
        }
        if(mark['X'-'A'])
        {
           int ct=mark['X'-'A'];
           for(int i=0;i<ct;i++)
            Ans.push_back(6);
           mark['S'-'A']-=ct;
           mark['I'-'A']-=ct;
           mark['X'-'A']-=ct;
        }
        if(mark['G'-'A'])
        {
           int ct=mark['G'-'A'];
           for(int i=0;i<ct;i++)
            Ans.push_back(8);
           mark['E'-'A']-=ct;
           mark['I'-'A']-=ct;
           mark['G'-'A']-=ct;
           mark['H'-'A']-=ct;
           mark['T'-'A']-=ct;
        }
        if(mark['F'-'A'])
        {
           int ct=mark['F'-'A'];
           for(int i=0;i<ct;i++)
            Ans.push_back(5);
           mark['F'-'A']-=ct;
           mark['I'-'A']-=ct;
           mark['V'-'A']-=ct;
           mark['E'-'A']-=ct;
        }
        if(mark['V'-'A'])
        {
           int ct=mark['V'-'A'];
           for(int i=0;i<ct;i++)
            Ans.push_back(7);
           mark['S'-'A']-=ct;
           mark['E'-'A']-=ct;
           mark['V'-'A']-=ct;
           mark['E'-'A']-=ct;
           mark['N'-'A']-=ct;
        }
        if(mark['I'-'A'])
        {
           int ct=mark['I'-'A'];
           for(int i=0;i<ct;i++)
            Ans.push_back(9);
           mark['N'-'A']-=ct;
           mark['I'-'A']-=ct;
           mark['N'-'A']-=ct;
           mark['E'-'A']-=ct;
        }
        if(mark['O'-'A'])
        {
           int ct=mark['O'-'A'];
           for(int i=0;i<ct;i++)
            Ans.push_back(1);
           mark['O'-'A']-=ct;
           mark['N'-'A']-=ct;
           mark['E'-'A']-=ct;
        }
        if(mark['H'-'A'])
        {
           int ct=mark['H'-'A'];
           for(int i=0;i<ct;i++)
            Ans.push_back(3);
           mark['T'-'A']-=ct;
           mark['H'-'A']-=ct;
           mark['R'-'A']-=ct;
           mark['E'-'A']-=ct;
           mark['E'-'A']-=ct;
        }
        sort(Ans.begin(),Ans.end());
        int siz=Ans.size();
        cout<<"Case #"<<k<<": ";
        for(int i=0;i<siz;i++)
            printf("%d",Ans[i]);
        cout<<endl;
        Ans.clear();
    }
    return 0;
}
