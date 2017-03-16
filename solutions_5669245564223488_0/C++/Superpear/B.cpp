#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>
#include <complex>
#include <ctime>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound
#define w1 first
#define w2 second

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

const int bigp=1000000007;

int TT,N,flag,ll,rr,ss,s1,s2,xx,yy,ans,oo,v,jc;
int chun[105],f[105][105],you[105][105],use[105],zhong[105],z[105];
string s[105];

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    scanf("%d",&TT);

    for (int gb=1;gb<=TT;gb++)
    {
        scanf("%d",&N);
        for (int i=1;i<=N;i++) cin>>s[i];
        memset(chun,0,sizeof(chun));
        for (int i=1;i<=N;i++)
        {
            flag=1;
            for (int j=1;j<s[i].size();j++)
                if (s[i][j]!=s[i][j-1]) flag=0;
            if (flag==1) chun[s[i][0]-96]++;
        }
        memset(you,0,sizeof(you));
        for (int i=1;i<=N;i++)
            for (int j=0;j<s[i].size();j++)
                you[i][s[i][j]-96]=1;
        memset(zhong,0,sizeof(zhong));
        ans=0;
        for (int i=1;i<=N;i++)
        {
            ll=0;
            while ((ll<s[i].size()-1)&&(s[i][ll]==s[i][ll+1])) ++ll;
            rr=s[i].size()-1;
            while ((rr>0)&&(s[i][rr]==s[i][rr-1])) --rr;
            for (int j=ll+1;j<rr;j++)
            {
                for (int k=1;k<=N;k++)
                    if ((k!=i)&&(you[k][s[i][j]-96]))
                    {
                        ans=-1;
                        break;
                    }
                if (ans==-1) break;
            }
            if (ans==-1) break;
        }
        for (int i=1;i<=N;i++)
        {
            for (int j=1;j<=26;j++)
            {
                ss=0;
                for (int k=0;k<s[i].size();k++)
                    if (((s[i][k]-96)==j)&&((k==0)||((s[i][k-1]-96)!=j))) ++ss;
                if (ss>1)
                {
                    ans=-1;
                    break;
                }
            }
            if (ans==-1) break;
        }
        if (ans!=-1)
        {
            memset(f,0,sizeof(f));
            for (int i=1;i<=N;i++)
                if (s[i][0]!=s[i][s[i].size()-1])
                {
                    xx=s[i][0]-96;
                    yy=s[i][s[i].size()-1]-96;
                    f[xx][yy]++;
                }
            for (int i=1;i<=26;i++)
            {
                s1=0,s2=0;
                for (int j=1;j<=26;j++) s1+=f[i][j],s2+=f[j][i];
                if ((s1>1)||(s2>1))
                {
                    ans=-1;
                    break;
                }
            }
            if (ans!=-1)
            {
                //if (gb==6) cout<<"E"<<endl;
                ans=1;
                oo=0;
                for (int i=1;i<=26;i++)
                    if (chun[i]>0)
                    {
                        ++oo;
                        for (int j=1;j<=chun[i];j++) ans=(LL)ans*j%bigp;
                    }
                /*if (gb==95)
                {
                    cout<<oo<<" "<<ans<<endl;
                    for (int i=1;i<=26;i++)
                        for (int j=1;j<=26;j++)
                            if (f[i][j]!=0) cout<<i<<"    "<<j<<endl;
                }*/
                memset(use,0,sizeof(use));
                for (int i=1;i<=26;i++)
                    if (use[i]==0)
                    {
                        flag=1;
                        for (int j=1;j<=26;j++)
                            if (f[j][i]==1) flag=0;
                        if (flag==0) continue;
                        v=1,z[1]=i;
                        use[i]=1;
                        while (true)
                        {
                            jc=-1;
                            for (int j=1;j<=26;j++)
                                if (f[z[v]][j]==1)
                                {
                                    jc=j;
                                    break;
                                }
                            if ((jc!=-1)&&(use[jc]==1))
                            {
                                ans=-1;
                                break;
                            }
                            if (jc==-1) break;
                            use[jc]=1;
                            ++v,z[v]=jc;
                        }
                        if (v==1) v=0,use[i]=0;
                        for (int j=1;j<=v;j++)
                            if (chun[z[j]]>0) --oo;
                        if (v>0) ++oo;
                    }
                for (int i=1;i<=26;i++)
                {
                    ss=0;
                    for (int j=1;j<=26;j++)
                        ss+=f[i][j];
                    if ((ss!=0)&&(use[i]==0)) ans=-1;
                }
                if (ans!=-1)
                {
                    for (int i=1;i<=oo;i++) ans=(LL)ans*i%bigp;
                }
                else ans=0;
            }
            else ans=0;
        }
        else ans=0;
        printf("Case #%d: %d\n",gb,ans);
    }
    return 0;
}
