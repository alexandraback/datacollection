#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
char s[10004],ps[10004],ss[10004];
main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int T;scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int l,x;
        scanf("%d%d",&l,&x);
        scanf("%s",s+1);
        ps[0]='1';ss[l+1]='1';
        for(int i=1;i<=l;i++)
        {
            if(ps[i-1]=='1') ps[i]=s[i];
            else if(ps[i-1]=='0')
            {
                if(s[i]=='i') ps[i]='I';
                else if(s[i]=='j') ps[i]='J';
                else ps[i]='K';
            }
            else if(ps[i-1]=='i')
            {
                if(s[i]=='i') ps[i]='0';
                else if(s[i]=='j') ps[i]='k';
                else ps[i]='J';
            }
            else if(ps[i-1]=='j')
            {
                if(s[i]=='i') ps[i]='K';
                else if(s[i]=='j') ps[i]='0';
                else ps[i]='i';
            }
            else if(ps[i-1]=='k')
            {
                if(s[i]=='i') ps[i]='j';
                else if(s[i]=='j') ps[i]='I';
                else ps[i]='0';
            }
            else if(ps[i-1]=='I')
            {
                if(s[i]=='i') ps[i]='1';
                else if(s[i]=='j') ps[i]='K';
                else ps[i]='j';
            }
            else if(ps[i-1]=='J')
            {
                if(s[i]=='i') ps[i]='k';
                else if(s[i]=='j') ps[i]='1';
                else ps[i]='I';
            }
            else if(ps[i-1]=='K')
            {
                if(s[i]=='i') ps[i]='J';
                else if(s[i]=='j') ps[i]='i';
                else ps[i]='1';
            }
        }
        for(int i=l;i>=1;i--)
        {
            if(ss[i+1]=='1') ss[i]=s[i];
            else if(ss[i+1]=='0')
            {
                if(s[i]=='i') ss[i]='I';
                else if(s[i]=='j') ss[i]='J';
                else ss[i]='K';
            }
            else if(ss[i+1]=='i')
            {
                if(s[i]=='i') ss[i]='0';
                else if(s[i]=='j') ss[i]='K';
                else ss[i]='j';
            }
            else if(ss[i+1]=='j')
            {
                if(s[i]=='i') ss[i]='k';
                else if(s[i]=='j') ss[i]='0';
                else ss[i]='I';
            }
            else if(ss[i+1]=='k')
            {
                if(s[i]=='i') ss[i]='J';
                else if(s[i]=='j') ss[i]='i';
                else ss[i]='0';
            }
            else if(ss[i+1]=='I')
            {
                if(s[i]=='i') ss[i]='1';
                else if(s[i]=='j') ss[i]='k';
                else ss[i]='J';
            }
            else if(ss[i+1]=='J')
            {
                if(s[i]=='i') ss[i]='K';
                else if(s[i]=='j') ss[i]='1';
                else ss[i]='i';
            }
            else if(ss[i+1]=='K')
            {
                if(s[i]=='i') ss[i]='j';
                else if(s[i]=='j') ss[i]='I';
                else ss[i]='1';
            }
        }
        int ch=1;
        long long L=100000000000000000LL,R=100000000000000000LL;

        if(ps[l]=='1') ch=0;
        else if(ps[l]=='0')
        {
            if(x%2==0) ch=0;
            else
            {
                for(int i=0;i<=l;i++)
                {
                    if(ps[i]=='i') L=min(L,1LL*i);
                    if(ps[i]=='I') L=min(L,1LL*l+i);
                }
                for(int i=l+1;i>=1;i--)
                {
                    if(ss[i]=='k') R=min(R,1LL*l-i+1);
                    if(ss[i]=='K') R=min(R,1LL*l-i+1+l);
                }
                if(L+R<=1LL*l*x) ch=1;
                else ch=0;
            }
        }
        else if(ps[l]=='i')
        {
            if(x%2) ch=0;
            else
            {
                if((x/2)%2==0) ch=0;
                else
                {
                    for(int i=0;i<=l;i++)
                    {
                        if(ps[i]=='i') L=min(L,1LL*i);
                        if(ps[i]=='1') L=min(L,1LL*l+i);
                        if(ps[i]=='I') L=min(L,2LL*l+i);
                        if(ps[i]=='0') L=min(L,3LL*l+i);
                    }
                    for(int i=l+1;i>=1;i--)
                    {
                        if(ss[i]=='k') R=min(R,l-i+1LL);
                        if(ss[i]=='J') R=min(R,l-i+1LL+l);
                        if(ss[i]=='K') R=min(R,l-i+1LL+2*l);
                        if(ss[i]=='j') R=min(R,l-i+1LL+3*l);
                    }
                    if(L+R<=1LL*l*x) ch=1;
                    else ch=0;
                }
            }
        }
        else if(ps[l]=='j')
        {
            if(x%2) ch=0;
            else
            {
                if((x/2)%2==0) ch=0;
                else
                {
                    for(int i=0;i<=l;i++)
                    {
                        if(ps[i]=='i') L=min(L,1LL*i);
                        if(ps[i]=='k') L=min(L,1LL*l+i);
                        if(ps[i]=='I') L=min(L,2LL*l+i);
                        if(ps[i]=='K') L=min(L,3LL*l+i);
                    }
                    for(int i=l+1;i>=1;i--)
                    {
                        if(ss[i]=='k') R=min(R,l-i+1LL);
                        if(ss[i]=='i') R=min(R,l-i+1LL+l);
                        if(ss[i]=='K') R=min(R,l-i+1LL+2*l);
                        if(ss[i]=='I') R=min(R,l-i+1LL+3*l);
                    }
                    if(L+R<=1LL*l*x) ch=1;
                    else ch=0;
                }
            }
        }
        else if(ps[l]=='k')
        {
            if(x%2) ch=0;
            else
            {
                if((x/2)%2==0) ch=0;
                else
                {
                    for(int i=0;i<=l;i++)
                    {
                        if(ps[i]=='i') L=min(L,1LL*i);
                        if(ps[i]=='J') L=min(L,1LL*l+i);
                        if(ps[i]=='I') L=min(L,2LL*l+i);
                        if(ps[i]=='j') L=min(L,3LL*l+i);
                    }
                    for(int i=l+1;i>=1;i--)
                    {
                        if(ss[i]=='k') R=min(R,l-i+1LL);
                        if(ss[i]=='1') R=min(R,l-i+1LL+l);
                        if(ss[i]=='K') R=min(R,l-i+1LL+2*l);
                        if(ss[i]=='0') R=min(R,l-i+1LL+3*l);
                    }
                    if(L+R<=1LL*l*x) ch=1;
                    else ch=0;
                }
            }
        }
        else if(ps[l]=='I')
        {
            if(x%2) ch=0;
            else
            {
                if((x/2)%2==0) ch=0;
                else
                {
                    for(int i=0;i<=l;i++)
                    {
                        if(ps[i]=='i') L=min(L,1LL*i);
                        if(ps[i]=='0') L=min(L,1LL*l+i);
                        if(ps[i]=='I') L=min(L,2LL*l+i);
                        if(ps[i]=='1') L=min(L,3LL*l+i);
                    }
                    for(int i=l+1;i>=1;i--)
                    {
                        if(ss[i]=='k') R=min(R,l-i+1LL);
                        if(ss[i]=='j') R=min(R,l-i+1LL+l);
                        if(ss[i]=='K') R=min(R,l-i+1LL+2*l);
                        if(ss[i]=='J') R=min(R,l-i+1LL+3*l);
                    }
                    if(L+R<=1LL*l*x) ch=1;
                    else ch=0;
                }
            }
        }
        else if(ps[l]=='J')
        {
            if(x%2) ch=0;
            else
            {
                if((x/2)%2==0) ch=0;
                else
                {
                    for(int i=0;i<=l;i++)
                    {
                        if(ps[i]=='i') L=min(L,1LL*i);
                        if(ps[i]=='K') L=min(L,1LL*l+i);
                        if(ps[i]=='I') L=min(L,2LL*l+i);
                        if(ps[i]=='k') L=min(L,3LL*l+i);
                    }
                    for(int i=l+1;i>=1;i--)
                    {
                        if(ss[i]=='k') R=min(R,l-i+1LL);
                        if(ss[i]=='I') R=min(R,l-i+1LL+l);
                        if(ss[i]=='K') R=min(R,l-i+1LL+2*l);
                        if(ss[i]=='i') R=min(R,l-i+1LL+3*l);
                    }
                    if(L+R<=1LL*l*x) ch=1;
                    else ch=0;
                }
            }
        }
        else if(ps[l]=='K')
        {
            if(x%2) ch=0;
            else
            {
                if((x/2)%2==0) ch=0;
                else
                {
                    for(int i=0;i<=l;i++)
                    {
                        if(ps[i]=='i') L=min(L,1LL*i);
                        if(ps[i]=='j') L=min(L,1LL*l+i);
                        if(ps[i]=='I') L=min(L,2LL*l+i);
                        if(ps[i]=='J') L=min(L,3LL*l+i);
                    }
                    for(int i=l+1;i>=1;i--)
                    {
                        if(ss[i]=='k') R=min(R,l-i+1LL);
                        if(ss[i]=='0') R=min(R,l-i+1LL+l);
                        if(ss[i]=='K') R=min(R,l-i+1LL+2*l);
                        if(ss[i]=='1') R=min(R,l-i+1LL+3*l);
                    }
                    if(L+R<=1LL*l*x) ch=1;
                    else ch=0;
                }
            }
        }
        printf("Case #%d: ",cas);
        if(ch==1) puts("YES");
        else puts("NO");
    }
}
