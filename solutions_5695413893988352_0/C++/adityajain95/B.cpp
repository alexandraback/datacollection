#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define f first
#define s second
#define si(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define CLR(x)  memset(x,0,sizeof(x))
#define RESET(x,a) memset(x,a,sizeof(x))
#define pi pair<int,int>
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<">value ("<<#x<<") : "<<x<<endl;

char s[20],c[20];
char tmp[20];
int val;
set<int > ff,ss;

void rec(int i,int n)
{
    if(i==n)
    {
        ff.insert(val);
        return;
    }
    if(s[i]!='?')
    {
        val=val*10+(s[i]-'0');
        rec(i+1,n);
        val=val/10;
        return ;
    }
    for(int ii=0;ii<10;ii++)
    {
        val=val*10+ii;
        rec(i+1,n);
        val=val/10;
    }
}

void rec2(int i,int n)
{
    if(i==n)
    {
        ss.insert(val);
        return;
    }
    if(c[i]!='?')
    {
        val=val*10+(c[i]-'0');
        rec2(i+1,n);
        val=val/10;
        return ;
    }
    for(int ii=0;ii<10;ii++)
    {
        val=val*10+ii;
        rec2(i+1,n);
        val=val/10;
    }
}

int main()
{
    freopen("2.in","r",stdin);
    freopen("B-out.txt","w",stdout);
    int tt,t,j,n,m,i;
    si(tt);
    for(t=1;t<=tt;t++)
    {
        scanf("%s",s);
        scanf("%s",c);
        bool eq=true;
        n=strlen(s);
        for(i=0;i<n;i++)
        {
            if(s[i]!='?'&&c[i]!='?')
            {
                eq=false;
                break;
            }
        }
        if(eq)
        {
            for(i=0;i<n;i++)
            {
                if(s[i]=='?'&&c[i]=='?')
                    s[i]='0';
                else if(s[i]=='?')
                    s[i]=c[i];
            }
            printf("Case #%d: %s %s\n",t,s,s);
        }
        else
        {
            val=0;
            ff.clear();
            rec(0,n);
            val=0;
            ss.clear();
            rec2(0,n);
            int diff=1000000;
            int v1=-1,v2=-1;
            for(set<int>::iterator it=ff.begin();it!=ff.end();it++)
            {
                //cout<<*it<<" "<<diff<<"\n";
                set<int>::iterator jt=ss.lower_bound(*it);
                if(jt!=ss.end())
                {
                    int tl=abs((*jt)-(*it));
                    if(tl<diff)
                    {
                        diff=tl;
                        v1=*it;
                        v2=*jt;
                    }
                }
                if(jt!=ss.begin())
                {
                    jt--;
                    int tl=abs((*jt)-(*it));
                    if(tl<diff ||(tl==diff&&v1==*it))
                    {
                        diff=tl;
                        v1=*it;
                        v2=*jt;
                    }
                }
            }
            printf("Case #%d: ",t);
            sprintf(tmp,"%d",v1);
            m=strlen(tmp);
            if(m<n)
            {
                for(i=0;i<(n-m);i++)
                    printf("0");
            }
            printf("%d ",v1);
            sprintf(tmp,"%d",v2);
            m=strlen(tmp);
            if(m<n)
            {
                for(i=0;i<(n-m);i++)
                    printf("0");
            }
            printf("%d\n",v2);
        }
    }
    return 0;
}

