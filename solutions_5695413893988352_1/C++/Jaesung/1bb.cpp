#pragma warning(disable:4996)

#include <stdio.h>

#include <sstream>
#include <string>
using namespace std;

char a[24], b[24];
string p, q;
long long ans1, ans2;
string s1, s2;
long long diff=-1;

void getans(int x, int comp)
{
    if (a[x]==0)
    {
        long long sa, sb;
        istringstream(p) >> sa;
        istringstream(q) >> sb;
        long long d = abs(sa-sb);
        if (diff==-1 || diff > d || (diff==d && ans1 > sb) || (diff==d && ans1==sa && ans2>sb))
            diff = d, ans1 = sa, ans2 = sb, s1=p, s2=q;
        return;
    }

    if (a[x]=='?' && b[x] == '?')
    {
        if (comp==-1)
        {
            p[x] = '9';
            q[x] = '0';
            getans(x+1, comp);
        }
        else if (comp==0)
        {
            p[x] = '0';
            q[x] = '0';
            getans(x+1, comp);
            p[x] = '1';
            q[x] = '0';
            getans(x+1, 1);
            p[x] = '0';
            q[x] = '1';
            getans(x+1, -1);
        }
        else if (comp==1)
        {
            p[x] = '0';
            q[x] = '9';
            getans(x+1, comp);
        }
    }
    else if (a[x]=='?')
    {
        q[x] = b[x];
        if (comp==-1)
        {
            p[x] = '9';
            getans(x+1, comp);
        }
        else if (comp==0)
        {
            p[x] = q[x];
            getans(x+1, comp);
            if (q[x]!='0')
            {
                p[x] = q[x]-1;
                getans(x+1, -1);
            }
            if (q[x]!='9')
            {
                p[x] = q[x]+1;
                getans(x+1, 1);
            }
        }
        else if (comp==1)
        {
            p[x] = '0';
            getans(x+1, comp);
        }
    }
    else if (b[x]=='?')
    {
        p[x] = a[x];
        if (comp==-1)
        {
            q[x] = '0';
            getans(x+1, comp);
        }
        else if (comp==0)
        {
            q[x] = p[x];
            getans(x+1, comp);
            if (p[x]!='0')
            {
                q[x] = p[x]-1;
                getans(x+1, 1);
            }
            if (p[x]!='9')
            {
                q[x] = p[x]+1;
                getans(x+1, -1);
            }
        }
        else if (comp==1)
        {
            q[x] = '9';
            getans(x+1, comp);
        }
    }
    else
    {
        p[x] = a[x];
        q[x] = b[x];
        if (comp==-1)
        {
            getans(x+1, comp);
        }
        else if (comp==0)
        {
            getans(x+1, p[x] < q[x] ? -1 : p[x] == q[x] ? 0 : 1);
        }
        else if (comp==1)
        {
            getans(x+1, comp);
        }
    }
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);

    int t,tt=0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s%s", a, b);
        p=a, q=b; diff=-1;
        getans(0, 0);
        printf("Case #%d: %s %s\n", ++tt, s1.c_str(), s2.c_str());
    }

    return 0;
}
