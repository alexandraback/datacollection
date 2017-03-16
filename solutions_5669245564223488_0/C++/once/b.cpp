#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define LL long long
#define N 107
#define MOD 1000000007
using namespace std;
char str[N][N];
int t[26],w[26];
bool m[26],vis[N];
int a[26];
LL p[N];
int main()
{
    freopen("Bs.in","r",stdin);
    freopen("A.out","w",stdout);
    int run,l,n,cnt,now,ss;
    scanf("%d",&run);
    bool ok,flag;
    LL ans;
    p[0]=1;
    for (int i=1;i<N;i++)
        p[i]=p[i-1]*i%MOD;
    for (int cas=1;cas<=run;cas++)
    {
        ok=true;
        memset(t,0,sizeof t);
        memset(w,0,sizeof w);
        memset(m,0,sizeof m);
        memset(a,0,sizeof a);
        memset(vis,0,sizeof vis);
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%s",str[i]);
            //cout << str[i] << endl;
            l=strlen(str[i]);
            flag=true;
            for (int j=0;j<l;j++)
                if (str[i][j]!=str[i][0])
                {
                    flag=false;
                    break;
                }
            if (!flag)
            {
                if (t[str[i][0]-'a']||m[str[i][0]-'a'])
                    ok=false;//,putchar(str[i][0]),putchar('1');
                t[str[i][0]-'a']=i;
                if (w[str[i][l-1]-'a']||m[str[i][l-1]-'a'])
                    ok=false;//,putchar(str[i][l-1]),putchar('2');
                w[str[i][l-1]-'a']=i;
                ss=0;
                for (int j=0;j<l-1;j++)
                    if (str[i][j]!=str[i][j+1])
                    {
                        ss++;
                        if (ss>1)
                        {
                            if (m[str[i][j]-'a']) ok=false;//,putchar(str[i][j]),putchar('3');
                            m[str[i][j]-'a']=true;
                        }
                        //putchar(str[i][j]);

                    }
                //putchar('\n');
            }
            else
            {
                a[str[i][0]-'a']++;
                vis[i]=true;
            }
        }
        printf("Case #%d: ",cas);
        if (ok)
        {
            cnt=0;
            for (int i=0;i<26;i++)
                if (m[i]&&a[i]>0)
                    ok=false;
                else if (!t[i]&&!w[i]&&a[i]>0)
                    cnt++;
            if (!ok)
            {
                cout << 0 << endl;
                continue;
            }

            for (int i=0;i<26;i++)
                if (t[i]&&!w[i])
                {
                    now=t[i];vis[now]=true;
                    while (now)
                    {
                        now=t[str[now][strlen(str[now])-1]-'a'];
                        vis[now]=true;
                    }
                    cnt++;
                }
            for (int i=1;i<=n;i++)
                if (!vis[i])
                {
                    ok=false;
                    break;
                }
            if (!ok)
            {
                cout << 0 << endl;
                continue;
            }
            ans=p[cnt];
            for (int i=0;i<26;i++)
                ans=ans*p[a[i]]%MOD;
            cout << ans << endl;
        }
        else
            cout << 0 << endl;


    }
    return 0;
}
