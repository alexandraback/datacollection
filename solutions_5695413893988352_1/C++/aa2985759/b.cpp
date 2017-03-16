#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

long long ansa, ansb;
vector<int> veca,vecb;

void upd(vector<int> va, vector<int> vb)
{
    long long aa=0,ab=0;
    for (int i=0;i<va.size();i++)
    {
        aa=aa*10+va[i];
        ab=ab*10+vb[i];
    }
    if (abs(aa-ab)>abs(ansa-ansb))
        return;
    if (abs(aa-ab)<abs(ansa-ansb))
    {
        ansa=aa;
        ansb=ab;
        veca=va;
        vecb=vb;
        return;
    }
    if (aa<ansa||(aa==ansa&&ab<ansb))
    {
        ansa=aa;
        ansb=ab;
        veca=va;
        vecb=vb;
    }
}

void gao(vector<int> va, vector<int> vb, int dep, int state)
{
    if (dep>=va.size())
    {
        upd(va, vb);
        return;
    }
    int i=dep;
    if (va[i]<0||vb[i]<0)
    {
        if (state<0)
        {
            if (va[i]<0)
                va[i]=9;
            if (vb[i]<0)
                vb[i]=0;
        }
        else if(state>0)
        {
            if(va[i]<0)
                va[i]=0;
            if (vb[i]<0)
                vb[i]=9;
        }
        else
        {
            if (va[i]<0&&vb[i]<0)
            {
                va[i]=0,vb[i]=1;
                gao(va, vb, dep+1, -1);
                va[i]=1,vb[i]=0;
                gao(va,vb,dep+1,1);
                va[i]=vb[i]=0;
                gao(va,vb,dep+1,0);
            }
            else if(va[i]<0)
            {
                if (vb[i]>0)
                {
                    va[i]=vb[i]-1;
                    gao(va,vb,dep+1,-1);
                }
                va[i]=vb[i];
                gao(va,vb,dep+1,0);
                if (vb[i]<9)
                {
                    va[i]=vb[i]+1;
                    gao(va,vb,dep+1,1);
                }
            }
            else
            {
                if(va[i]>0)
                {
                    vb[i]=va[i]-1;
                    gao(va,vb,dep+1,1);
                }
                vb[i]=va[i];
                gao(va,vb,dep+1,0);
                if(va[i]<9)
                {
                    vb[i]=va[i]+1;
                    gao(va,vb,dep+1,-1);
                }
            }
            return;
        }
    }
    else if(va[i]!=vb[i])
    {
        if (state==0)
        {
            if (va[i]<vb[i])
                state=-1;
            else
                state=1;
        }
    }
    gao(va,vb,dep+1,state);
}

int main()
{
    int t;
    scanf("%d",&t);

    for (int ii=1;ii<=t;ii++)
    {
        char s1[100],s2[100];

        scanf("%s%s",s1,s2);
        vector<int> va;
        vector<int> vb;
        ansa=(1ll<<62);
        ansb=0;

        for (int i=0;s1[i];i++)
        {
            if (s1[i]=='?')
                va.push_back(-1);
            else
                va.push_back(s1[i]-'0');
            if (s2[i]=='?')
                vb.push_back(-1);
            else
                vb.push_back(s2[i]-'0');
        }

        gao(va,vb,0,0);

        printf("Case #%d: ", ii);
        for (int i=0;i<va.size();i++)
            printf("%d", veca[i]);
        printf(" ");
        for (int i=0;i<vb.size();i++)
            printf("%d", vecb[i]);
        puts("");
    }
}
