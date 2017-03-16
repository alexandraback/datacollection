#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int calt(string s, char c)
{
    if (s.length()==0)
        return -1;
    int i,tmp=0;
    for (i=0;i<s.length();i++)
    {
        if (s[i]==c)
            continue;
        else
            break;
    }
    if (i==s.length())
        return 0;
    if (i>0)
        tmp=1;
    for (i=s.length()-1;i>=0;i--)
    {
        if (s[i]==c)
            continue;
        else
            break;
    }
    if (tmp==1)
    {
        if (i==s.length()-1)
            return 1;
        else
            return -1;
    }
    if (i==s.length()-1)
        return 3;
    else
        return 2;
}

int chk(string s,char c)
{
    bool flag = false, inte = false;
    for (int i=0;i<s.length();i++)
    {
        if (s[i]==c)
        {
            if (flag == false)
                flag = true;
            else
                if (inte == true)
                    return -1;
        }else
        {
            if (flag == true)
                inte = true;
        }
    }
    return 1;
}

int main()
{
    int T;
    int mod = 1000000007;
    freopen("B-small-attempt1.in","r",stdin);
    freopen("out.out","w",stdout);
    cin>>T;
    for (int tt=1;tt<=T;tt++)
    {
        int n,len;
        bool flag = false;
        string lst[105];
        long long prop[105];
        cin>>n;
        len=n;
        for (int i=1;i<=n;i++)
        {
            prop[i]=1;
            cin>>lst[i];
        }
        for (char c='a';c<='z';c++)
        {
            int tl[3][105];
            bool bb[105];
            memset(bb,0,sizeof(bb));
            memset(tl,0,sizeof(tl));
            for (int i=1;i<=len;i++)
            {
                int ty = calt(lst[i],c);
                if (ty >= 0 && ty <= 2)
                {
                    tl[ty][++tl[ty][0]]=i;
                    bb[i]=true;
                }
            }
            if (tl[1][0]>1 || tl[2][0]>1)
            {
                flag = true;
                break;
            }
            string tmps = "";
            long long tmpp = 1;
            if (tl[2][0]>0)
            {
                tmps=lst[tl[2][1]];
                tmpp=prop[tl[2][1]];
            }
            for (int i=1;i<=tl[0][0];i++)
            {
                tmpp=(tmpp*prop[tl[0][i]])%mod;
                tmpp=(tmpp*i)%mod;
                tmps+=lst[tl[0][i]];
            }
            if (tl[1][0]>0)
            {
                tmpp=(tmpp*prop[tl[1][1]])%mod;
                tmps+=lst[tl[1][1]];
            }
            int tmp[105];
            tmp[0]=0;
            for (int i=1;i<=len;i++)
                if (bb[i]==false)
                    tmp[++tmp[0]]=i;
            len=tmp[0];
            for (int i=1;i<=tmp[0];i++)
            {
                lst[i]=lst[tmp[i]];
                prop[i]=prop[tmp[i]];
            }
            lst[++len]=tmps;
            prop[len]=tmpp;
        }
        string sss = "";
        for (int i=1;i<=len;i++)
            sss+=lst[i];
        for (char c='a';c<='z';c++)
            if (chk(sss,c)==-1)
                flag = true;

        cout<<"Case #"<<tt<<": ";
        if (flag)
            cout<<0<<endl;
        else
        {
            long long ans=1;
            for (int i=1;i<=len;i++)
            {
                if (lst[i].length()==0)
                    break;
                ans=(ans*prop[i])%mod;
                ans=(ans*i)%mod;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
