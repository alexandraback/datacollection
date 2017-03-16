#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
const int n=521196;
string s,a[521200];
int cnt[20];
char buf[4010];
set <string> S[15];
void init()
{
    FILE *in=fopen("dict.txt","r");
    for (int i=1;i<=n;i++)
    {
        fscanf(in,"%s",buf);
        a[i]=buf;
        S[a[i].size()].insert(a[i]);
    }
    fclose(in);
}
int f[4010][6];
inline void update(int &a,int b)
{
    a=min(a,b);
}
inline bool find(const string &s)
{
    return(S[s.size()].count(s));
}
void dp(int num,int l,int r,int index)
{
    string now=s.substr(l-1,r-l+1);
    if (find(now))
    {
        update(f[r][max(0,index-(r-l+1))],num);
        return;
    }
    for (int i=index;i<now.size();i++)
    {
        char t1=now[i];
        for (char c1='a';c1<='z';c1++)
        {
            now[i]=c1;
            if (find(now))
            {
                update(f[r][max(0,4-(int(now.size())-i-1))],num+1);
                return;
            }
            for (int j=i+5;j<now.size();j++)
            {
                char t2=now[j];
                for (char c2='a';c2<='z';c2++)
                {
                    now[j]=c2;
                    if (find(now))
                        update(f[r][max(0,4-(int(now.size())-j-1))],num+2);
                }
                now[j]=t2;
            }
        }
        now[i]=t1;
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",buf);
        s=buf;
        memset(f,63,sizeof(f));
        int inf=f[0][0];
        f[0][0]=0;
        for (int i=0;i<s.size();i++)
            for (int j=0;j<5;j++)
            {
                if (f[i][j]==inf)
                    continue;
                for (int k=1;k<=10;k++)
                {
                    if (i+k>s.size())
                        break;
                    dp(f[i][j],i+1,i+k,j);
                }
            }
        int ans=inf;
        for (int i=0;i<5;i++)
            ans=min(ans,f[s.size()][i]);
        static int id=0;
        printf("Case #%d: %d\n",++id,ans);
    }
}

