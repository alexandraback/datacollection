#include <bits/stdc++.h>

using namespace std;
string title1[210];
string title2[210];
int n;
int included[210];
map<string,bool> leftt,rightt;
int sol=0;
void solve(int idx)
{
    if(idx==n)
    {
        leftt.clear();
        rightt.clear();
        int fakers=0;
        for(int i=0;i<n;i++)
            if(included[i])fakers++;
        for(int i=0;i<n;i++)
        {
            if(!included[i])
            {
                leftt[title1[i]]=true;
                rightt[title2[i]]=true;
            }
        }
        bool ok=true;
        for(int i=0;i<n;i++)
        {
            if(included[i])
            {
                if(leftt[title1[i]]==false||rightt[title2[i]]==false)ok=false;
            }
        }
        if(ok)
        {
            if(fakers>sol)
            {
                sol=fakers;
            }
        }
        return;
    }
    included[idx]=1;
    solve(idx+1);
    included[idx]=0;
    solve(idx+1);
}
int main()
{
    int t,testno=1;
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            cin>>title1[i]>>title2[i];
        sol=0;
        solve(0);
        printf("Case #%d: %d\n",testno++,sol);
    }
    return 0;
}
