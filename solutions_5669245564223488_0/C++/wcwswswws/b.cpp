#include<stdio.h>
#include<string.h>
#include<map>
#include<queue>
using namespace std;
priority_queue<int> qe;
int head[26],tail[26],mid[26],all[26],b[100][2],h1[26],t1[26];
char s[200];
long long jc[101];
long long mod=1000000007;
long long a[100000000];
bool used[1<<26];
int dig,tot;
map<pair<int,int>,int> st;

void work(int d,int t)
{
    if ((t<0)||(head[t]+all[t]==0)||(d&(1<<t)))
    {
        if ((t>=0)&&((d&(1<<t))==0)&&(head[t]+all[t]==0))
        {
            if (st.find(pair<int,int>(d|(1<<t),t))==st.end())
            {
                st[pair<int,int>(d|(1<<t),t)]=++tot;
                a[tot]=0;
            }
            if (used[d|(1<<t)]==false)
            {
                used[d|(1<<t)]=true;
                qe.push(-(d|(1<<t)));
            }
            a[st[pair<int,int>(d|(1<<t),t)]]=a[st[pair<int,int>(d,t)]];
            d|=(1<<t);
        }
        for (int i=0;i<26;i++)
        if (((d&(1<<i))==0)&&(tail[i]==0)&&(head[i]+all[i]>0))
        {
            if (t<0)
            {
                int p=i;
                if (head[i]>0) p=b[h1[i]][1];
                if (used[d|(1<<i)]==false)
                {
                    used[d|(1<<i)]=true;
                    qe.push(-(d|(1<<i)));
                }
                if (st.find(pair<int,int>(d|(1<<i),p))==st.end())
                {
                    st[pair<int,int>(d|(1<<i),p)]=++tot;
                    a[tot]=0;
                }
                a[st[pair<int,int>(d|(1<<i),p)]]=(a[st[pair<int,int>(d|(1<<i),p)]]+jc[all[i]])%mod;
            } else
            {
                int p=i;
                if (head[i]>0) p=b[h1[i]][1];
                if (st.find(pair<int,int>(d|(1<<i),p))==st.end())
                {
                    st[pair<int,int>(d|(1<<i),p)]=++tot;
                    a[tot]=0;
                }
                if (used[d|(1<<i)]==false)
                {
                    used[d|(1<<i)]=true;
                    qe.push(-(d|(1<<i)));
                }
                a[st[pair<int,int>(d|(1<<i),p)]]=(a[st[pair<int,int>(d|(1<<i),p)]]+a[st[pair<int,int>(d,t)]]*jc[all[i]]%mod)%mod;
            }
        }
    } else
    {
        int p=t;
        if (head[p]) p=b[h1[p]][1];
        if (st.find(pair<int,int>(d|(1<<t),p))==st.end())
        {
            st[pair<int,int>(d|(1<<t),p)]=++tot;
            a[tot]=0;
        }
        if (used[d|(1<<t)]==false)
        {
            used[d|(1<<t)]=true;
            qe.push(-(d|(1<<t)));
        }
        if ((d&(1<<t))==0) a[st[pair<int,int>(d|(1<<t),p)]]=(a[st[pair<int,int>(d|(1<<t),p)]]+a[st[pair<int,int>(d,t)]]*jc[all[t]]%mod)%mod;
    }
}

bool checkins(char s[])
{
    int m=strlen(s);
    int h=0;
    while (h<m)
    {
        while ((h+1<m)&&(s[h]==s[h+1])) h++;
        if (h==m-1) return true;
        for (int i=h+1;i<m;i++) if (s[h]==s[i]) return false;
        h++;
    }
}

int main()
{
    jc[1]=jc[0]=1;
    for (long long i=2;i<=100;i++) jc[i]=(jc[i-1]*i)%mod;
    freopen("B-small-attempt3.in","r",stdin);
    freopen("B-small-attempt3.out","w",stdout);
    int tt;scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        st.clear();
        tot=0;
        printf("Case #%d: ",t);
        memset(head,0,sizeof(head));
        memset(tail,0,sizeof(tail));
        memset(mid,0,sizeof(mid));
        memset(all,0,sizeof(all));
        memset(used,false,sizeof(used));
        int n;scanf("%d",&n);
        bool check=true;
        for (int i=0;i<n;i++)
        {
            scanf("%s",s);int m=strlen(s);
            bool p=true;
            for (int j=1;j<m-1;j++) if ((s[j]!=s[0])&&(s[j]!=s[m-1]))
            {
                if (s[j]!=s[j-1]) mid[s[j]-'a']++;
                p=false;
            }
            check&=checkins(s);
            if (s[0]==s[m-1])
            {
                all[s[0]-'a']++;
                b[i][0]=b[i][1]=s[0]-'a';
                if (!p) check=false;
            }
            else
            {
                head[s[0]-'a']++;b[i][0]=s[0]-'a';h1[s[0]-'a']=i;
                tail[s[m-1]-'a']++;b[i][1]=s[m-1]-'a';t1[s[m-1]-'a']=i;
            }
        }
        for (int i=0;i<26;i++)
        if ((head[i]>1)||(tail[i]>1)||(mid[i]>1)||((mid[i]>0)&&((head[i])||(tail[i])||(all[i])))) check=false;
        if (!check)
        {
            printf("0\n");
            continue;
        }
        dig=0;
        for (int i=0;i<26;i++)
        if (head[i]+tail[i]+all[i]) dig|=(1<<i);
        while (qe.size()) qe.pop();
        work(0,-1);
        while (qe.size())
        {
            int i=-qe.top();qe.pop();
            for (int j=0;j<26;j++)
            if (st.find(pair<int,int>(i,j))!=st.end()) work(i,j);
        }
        long long ans=0;
        for (int i=0;i<26;i++)
            ans=(ans+a[st[pair<int,int>(dig,i)]])%mod;
        int ans1=ans;
        printf("%d\n",ans1);
    }
    return 0;
}
