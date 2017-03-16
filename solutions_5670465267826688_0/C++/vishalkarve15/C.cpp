#include<bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define ll long long

char a[800010];

int main()
{
    int t;
    scanf("%d",&t);

    map<char,char> Ne;
    Ne['i']='j';
    Ne['j']='k';
    Ne['k']='i';

    for(int tt=1;tt<=t;tt++)
    {
        int l;
        ll x;
        scanf("%d%lld",&l,&x);
        scanf("%s",a);

        if(x<=8)
        {
            for(int i=l;i<x*l;i++)
                a[i]=a[i-l];
            a[x*l]='\0';
            l=x*l;
            char pref='1';
            int sgn=0;
            int iind=-1;
            int kind=-1;
            for(int i=0;i<l;i++)
            {
                if(pref=='1')
                    pref=a[i];
                else if(pref==a[i])
                    pref='1',sgn=1-sgn;
                else if(Ne[pref]==a[i])
                    pref=Ne[a[i]];
                else
                    pref=Ne[pref],sgn=1-sgn;

                if(pref=='i' && sgn==0)
                {
                    if(i<iind || iind==-1)
                        iind=i;
                }
            }
            if(pref!='1' || sgn!=1 || iind==-1)
            {
                printf("Case #%d: NO\n",tt);
                continue;
            }
            char suff='1';
            sgn=0;
            for(int i=l-1;i>iind;i--)
            {
                if(suff=='1')
                    suff=a[i];
                else if(suff==a[i])
                    suff='1',sgn=1-sgn;
                else if(suff==Ne[a[i]])
                    suff=Ne[suff];
                else
                    suff=Ne[a[i]],sgn=1-sgn;

                if(suff=='k' && sgn==0)
                {
                    kind=i;
                    break;
                }
            }
            if(kind==-1)
            {
                printf("Case #%d: NO\n",tt);
                continue;
            }
            printf("Case #%d: YES\n",tt);
            continue;
        }

        /* x>8 */

        char pref='1';
        int sgn=0;

        for(int i=0;i<l;i++)
        {
            if(pref=='1')
                pref=a[i];
            else if(pref==a[i])
                pref='1',sgn=1-sgn;
            else if(Ne[pref]==a[i])
                pref=Ne[a[i]];
            else
                pref=Ne[pref],sgn=1-sgn;
        }

        if(pref=='1')
        {
            if(sgn==1 && x%2!=1)
            {
                printf("Case #%d: NO\n",tt);
                continue;
            }
            else if(sgn==0)
            {
                printf("Case #%d: NO\n",tt);
                continue;
            }
        }
        else
        {
            if(x%4!=2)
            {
                printf("Case #%d: NO\n",tt);
                continue;
            }
        }

        for(int i=l;i<4*l;i++)
            a[i]=a[i-l];
        a[4*l]='\0';
        l=4*l;
        pref='1';
        sgn=0;
        int iind=-1;
        int kind=-1;
        for(int i=0;i<l;i++)
        {
            if(pref=='1')
                pref=a[i];
            else if(pref==a[i])
                pref='1',sgn=1-sgn;
            else if(Ne[pref]==a[i])
                pref=Ne[a[i]];
            else
                pref=Ne[pref],sgn=1-sgn;

            if(pref=='i' && sgn==0)
            {
                iind=i;
                break;
            }
        }
        if(iind==-1)
        {
            printf("Case #%d: NO\n",tt);
            continue;
        }
        char suff='1';
        sgn=0;
        for(int i=l-1;i>=0;i--)
        {
            if(suff=='1')
                suff=a[i];
            else if(suff==a[i])
                suff='1',sgn=1-sgn;
            else if(suff==Ne[a[i]])
                suff=Ne[suff];
            else
                suff=Ne[a[i]],sgn=1-sgn;

            if(suff=='k' && sgn==0)
            {
                kind=i;
                break;
            }
        }
        if(kind==-1)
        {
            printf("Case #%d: NO\n",tt);
            continue;
        }
        printf("Case #%d: YES\n",tt);
    }
    return 0;
}
