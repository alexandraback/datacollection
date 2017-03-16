#include <iostream>
#include <cstdio>
using namespace std;
#define rep(i,n) for (int i=1,n__=n;i<=n__;i++)
#define repb(i,b,n) for (int i=b,n__=n;i<=n__;i++)
bool exist[101]={0};
 string s[101];
int t[101];
int ans=0,n;
bool exch[150]={0};
void search(int lv)
{
    if (lv==n+1)
    {
        repb(i,'a','z')
            exch[i]=false;
        int i=1,j=0;
        char lc=0;
        while (i<=n)
        {
            char ch=s[t[i]][j];
            if (ch!=lc)
            {
                if (exch[ch])
                    return;
                exch[ch]=true;
            }
            j++;
            if (j>=s[t[i]].size())
                i++,j=0;
            lc=ch;
        }
        ans++;
        return;
    }
    rep(i,n)
    {
        if (!exist[i])
        {
            exist[i]=true;
            t[lv]=i;
            search(lv+1);
            exist[i]=false;
        }
    }
}
int main()
{
    freopen("B-small-attempt1.in.txt","r",stdin);
    freopen("b_sm.out","w",stdout);
    int ta;
    cin>>ta;
    rep(tz,ta)
    {
        cin>>n;
        ans=0;

        rep(i,n)
            cin>>s[i];
        search(1);
        printf("Case #%d: %d\n",tz,ans);
    }
    return 0;
}
