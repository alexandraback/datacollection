#pragma warning(disable:4996)

#include <stdio.h>
#include <map>
#include <memory.h>
using namespace std;

int n, n1, n2;
map<string, int> m1, m2;
int e[1000][1000];
int cnt1[1000], cnt2[1000];
int topic[1000][2];

bool strong[1000];
int back[1000];
bool chk[1000];

bool flow(int x)
{
    if (x==-1)
    {
        for (int i=0; i<n1; i++)
        {
            if (!chk[i] && !strong[i])
            {
                chk[i] = true;
                if (flow(i))
                {
                    strong[x] = true;
                    return true;
                }
            }
        }
    }
    else
    {
        for (int i=0; i<n2; i++)
        {
            if (back[i]!=-1)
            {
                strong[x] = true;
                back[i] = x;
                return true;
            }

            if (!chk[back[i]])
            {
                chk[back[i]] = true;
                if (flow(back[i]))
                {
                    back[i] = x;
                    return true;
                }
            }
        }
    }

    return false;
}

int nf()
{
    int res=0;

    memset(strong, 0, sizeof strong);
    memset(back, -1, sizeof back);
    while (true)
    {
        memset(chk, 0, sizeof chk);
        if (!flow(-1)) return res;
        res++;
        while (flow(-1)) res++;
    }
}

void remove_e1(int t, int x)
{
    if (t==0)
    {
        cnt1[x]--;
        for (int i=0; i<n2; i++)
        {
            if (e[x][i])
            {
                e[x][i] = 0;
                cnt2[i]--;
                if (cnt2[i] == 1)
                    remove_e1(1, i);
                break;
            }
        }
    }
    if (t==1)
    {
        cnt2[x]--;
        for (int i=0; i<n1; i++)
        {
            if (e[i][x])
            {
                e[i][x] = 0;
                cnt1[i]--;
                if (cnt1[i] == 1)
                    remove_e1(0, i);
                break;
            }
        }
    }
}

int main()
{
    freopen("C-small.in", "r", stdin);
    freopen("C-small.out", "w", stdout);

    int t,tt=0;
    scanf("%d", &t);
    while(t--)
    {
        n1=n2=0;
        m1.clear();
        m2.clear();
        memset(e, 0, sizeof e);
        memset(cnt1, 0, sizeof cnt1);
        memset(cnt2, 0, sizeof cnt2);
        memset(topic, 0, sizeof topic);

        scanf("%d", &n);
        for (int i=0; i<n; i++)
        {
            char s1[24], s2[24];
            scanf("%s%s", s1, s2);
            if (m1.find(s1) == m1.end()) m1[s1] = n1++;
            if (m2.find(s2) == m2.end()) m2[s2] = n2++;
            e[m1[s1]][m2[s2]]++;
            cnt1[m1[s1]]++;
            cnt2[m2[s2]]++;
            topic[i][0] = m1[s1];
            topic[i][1] = m2[s2];
        }

        int ans=0;
        for (int i=0; i<(1<<n); i++)
        {
            int req[2][16];
            int has[2][16];
            memset(req, 0, sizeof req);
            memset(has, 0, sizeof has);

            int cand=0;
            for (int j=0; j<n; j++)
            {
                if (i&(1<<j))
                {
                    cand++;
                    req[0][topic[j][0]] = req[1][topic[j][1]] = true;
                }
                else
                {
                    has[0][topic[j][0]] = has[1][topic[j][1]] = true;
                }
            }

            bool vio=false;
            for (int i=0; i<n; i++)
            {
                if (req[0][i] && !has[0][i] ||
                    req[1][i] && !has[1][i])
                    vio = true;
            }

            if (!vio && ans < cand)
                ans = cand;
        }

        /*
        for (int i=0; i<n1; i++) if (cnt1[i]==1) remove_e1(0, i);
        for (int i=0; i<n2; i++) if (cnt2[i]==1) remove_e1(1, i);
        
        int ans=0;
        for (int i=0; i<n1; i++) for (int j=0; j<n2; j++)
            ans += e[i][j];
        ans -= nf();
        */
        printf("Case #%d: %d\n", ++tt, ans);
    }

    return 0;
}
