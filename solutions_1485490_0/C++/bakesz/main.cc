#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <set>
using namespace std;

#include <vector>
#include <set>
#include <map>

struct o{
    unsigned long long int t,n;
};

struct state{
    unsigned long long bt,bn;//box
    unsigned long long tt,tn;//toy
    unsigned long long profit;
    int bpoz,tpoz,sor;
};

std::set<int> boxtypes;
std::set<int> toytypes;


vector<o> b;
vector<o> t;

unsigned long long sim(vector<int> u)
{
    //return 0;
    state s;
    s.bpoz=0;
    s.tpoz=-1;
    s.sor=0;
    s.bt=0;
    s.bn=0;
    s.profit=0;


    int upoz=0;
    int ik;

    for (int i=0;i<t.size()+u.size();i++)
    {
        ik=i-upoz;
        if (u[upoz]==ik)
        {
            if (s.bt==b[upoz].t)
            {
                s.bn+=b[upoz].n;
            }
            else
            {
            s.bt=b[upoz].t;
            s.bn=b[upoz].n;
}
        upoz++;
        }
        else
        {
            if (s.tt==t[ik].t)
            {
                s.tn+=b[ik].n;
            }
            else
            {
            s.tt=t[ik].t;
            s.tn=t[ik].n;
}
        }
        if (s.bt==s.tt)
        {
            unsigned long long int oo=std::min(s.bn,s.tn);
            s.profit+=oo;
            s.bn-=oo;
            s.tn-=oo;
        }
    }
    return s.profit;
}

unsigned long int r(state s)
{

//    printf("%d %d\n",s.poz,s.sor);
    if (s.bt==s.tt)
    {
        int oo=std::min(s.bn,s.tn);
        s.profit+=oo;
        s.bn-=oo;
        s.tn-=oo;
    }
    unsigned long int akt_profit=s.profit;
    for (int i=s.bpoz+1/*siman felfele nincs ut*/;i<b.size();i++)
    {
        if (!(s.tt==b[i].t || s.bt==b[i].t) ) continue;
        if (toytypes.find(t[i].t)==toytypes.end()) continue;
        state s2=s;
        s2.bpoz=i;
        s2.sor=0;
        if (s2.bt==b[i].t)
        {
            s2.bn+=b[i].n;
        }
        else
        {
            s2.bn=b[i].n;
            s2.bt=b[i].t;
        }
        unsigned long int q=r(s2);
        akt_profit=max(akt_profit,q);
    }

    if (s.bn!=0)
    for (int i=s.tpoz+1;i<t.size();i++)
    {
        if (!(s.bt==t[i].t || s.tt==t[i].t) ) continue;
        if (boxtypes.find(t[i].t)==boxtypes.end()) continue;
        state s2=s;
        s2.tpoz=i;
        s2.sor=1;
        if (s2.tt==t[i].t)
        {
            s2.tn+=t[i].n;
        }
        else
        {
            s2.tn=t[i].n;
            s2.tt=t[i].t;
        }
        unsigned long int q=r(s2);
        akt_profit=max(akt_profit,q);
    }
    return akt_profit;
}

void solve()
{
    int n,m;
    scanf("%d",&n);//box type
    scanf("%d",&m);//toy type
    b=vector<o> (n);
    t=vector<o> (m);

    boxtypes.clear();
    for (int i=0;i<n;i++)
    {
        scanf("%llu",&b[i].n);
        scanf("%d",&b[i].t);
        boxtypes.insert(b[i].t);
    }
    for (int i=0;i<m;i++)
    {
        scanf("%llu",&t[i].n);

        scanf("%d",&t[i].t);
        toytypes.insert(b[i].t);
    }
    vector<int> u;
    //lusta vagyok permutalast irni.
    unsigned long long maxp=0;
    if (b.size()==1)
    {
        for (int i=0;i<t.size()+1;i++)
{
            u.clear();
u.push_back(i);
maxp=std::max(maxp,sim(u));
}
    }
    if (b.size()==2)
    {
        for (int i=0;i<t.size()+1;i++)
{
            for (int j=i;j<t.size()+1;j++)
            {
                u.clear();
                u.push_back(i);
                   u.push_back(j);
                   maxp=std::max(maxp,sim(u));
            }
}}
        if (b.size()==3)
        {
            for (int i=0;i<t.size()+1;i++)
    {
                for (int j=i;j<t.size()+1;j++)
                    for (int k=j;k<t.size()+1;k++)
                {
                    u.clear();
                    u.push_back(i);
                       u.push_back(j);
                       u.push_back(k);
                       maxp=std::max(maxp,sim(u));
                }
    }
        }


    printf("%llu\n",maxp);
}

int main()
{
    int casenum;
    scanf("%d",&casenum);
    for (int i=0;i<casenum;i++)
    {
        printf("Case #%d: ",i+1);
        solve();
    }

}
