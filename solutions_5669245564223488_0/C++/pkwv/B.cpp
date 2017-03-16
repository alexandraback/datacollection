#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<iostream>
#define ll long long
using namespace std;

const int mod = 1000000007;
const int MAXN = 1005;

string mp[MAXN];
struct str
{
    int len;
    char s[3];
};

str s[MAXN];

bool check_in(int n)
{
    bool mk[30];

    for(int i = 0; i < n; i++)
    {
        memset(mk, false, sizeof(mk));
        int len = mp[i].size();
        mk[mp[i][0] - 'a'] = true;

        for(int j = 1; j < len; j++)
        {
            int t = mp[i][j] - 'a';

            if(mk[t])
            {
                if(mp[i][j] == mp[i][j - 1])
                {

                }
                else
                {
                    return false;
                }
            }
            else
            {
                mk[t] = true;
            }
        }
    }

    return true;
}

bool check(string &t)
{
//    cout << t << endl;
    bool mk[30];
    memset(mk, false, sizeof(mk));
    int len = t.size();
//    printf("%d==\n", len);
    mk[t[0] - 'a'] = true;

    for(int j = 1; j < len; j++)
    {
        int tmp = t[j] - 'a';

        if(mk[tmp])
        {
            if(t[j] == t[j - 1])
            {

            }
            else
            {
                return false;
            }
        }
        else
        {
            mk[tmp] = true;
        }
    }

    return true;
}

bool check_out(int n)
{

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            string t = mp[i] + mp[j];

            if(check(t))
            {

            }
            else
            {
                t=mp[j]+mp[i];
                if(!check(t))
                return false;
            }
        }
    }

    return true;
}

ll A[MAXN];

void init()
{
    A[0] = 1;

    for(int i = 1; i < MAXN; i++)
    {
        A[i] = (A[i - 1] * (ll)i) % mod;
    }
}

int main()
{
#ifdef PKWV
//    freopen("in.in","r",stdin);
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("out.out","w",stdout);
#endif // PKWV
    int T, cas = 1;
    scanf("%d", &T);
    init();

    while(T--)
    {
        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; i++)
        {
            char t[300];
            scanf("%s", t);
            mp[i] = t;
        }

        bool tag = check_in(n);
        ll res = 0LL;

        if(!tag)
        {
            res = 0;
//            printf("==1\n");
        }
        else
        {
            tag = check_out(n);

            if(!tag)
            {
                res = 0;
//                printf("===2\n");
            }
            else
            {
                bool mk[30];
                memset(mk, false, sizeof(mk));

                for(int i = 0; i < n; i++)
                {
                    int len = mp[i].size();

                    if(mp[i][0] == mp[i][len - 1])
                    {
                        s[i].len = 1;
                        s[i].s[0] = mp[i][0];
                    }
                    else
                    {
                        s[i].len = 2;
                        s[i].s[0] = mp[i][0];
                        s[i].s[1] = mp[i][len - 1];
                    }
                }

                bool fl = false;

                for(int i = 0; i < n; i++)
                {
                    if(s[i].len == 2)
                    {
                        if(mk[s[i].s[0] - 'a'])
                        {
                            fl = true;
                            break;
                        }
                        else
                        {
                            mk[s[i].s[0] - 'a'] = true;
                        }
                    }
                }

                if(fl)
                {
                    tag = true;
                    res = 0;
                }
                else
                {
                    fl = false;
                    memset(mk, false, sizeof(mk));

                    for(int i = 0; i < n; i++)
                    {
                        if(s[i].len == 2)
                        {
                            if(mk[s[i].s[1] - 'a'])
                            {
                                fl = true;
                                break;
                            }
                            else
                            {
                                mk[s[i].s[1] - 'a'] = true;
                            }
                        }
                    }

                    if(fl)
                    {
                        tag = true;
                        res = 0LL;
                    }
                    else
                    {


//                        for(int i=0;i<26;i++) printf("%d==\n",cnt[i]);
//                        printf("\n");

                        ll t;
                        int tol = 0;
                        bool pr[30], su[30];
                        memset(pr,false,sizeof(pr));
                        memset(su,false,sizeof(su));

                        for(int i = 0; i < n; i++)
                        {
                            if(s[i].len == 2)
                            {
                                pr[s[i].s[0] - 'a'] = true;
                                su[s[i].s[1] - 'a'] = true;
                            }
                        }

                        for(int i = 0; i < 26; i++)
                        {
                            if(pr[i] && !su[i])
                            {
                                tol++;
                            }
                        }

                        for(int i=0;i<n;i++)
                        {
                            if(s[i].len==1)
                            {
                                if(!pr[s[i].s[0]-'a']&&!su[s[i].s[0]-'a'])
                                {
                                    tol++;
                                    pr[s[i].s[0]-'a']=true;
                                    su[s[i].s[0]-'a']=true;
                                }
                            }
                        }

                        res = A[tol];
//                        printf("tol: %d==\n",tol);
                        int cnt[30];
                        memset(cnt, 0, sizeof(cnt));

                        for(int i = 0; i < n; i++)
                        {
                            if(s[i].len == 1)
                            {
                                cnt[s[i].s[0] - 'a']++;
                            }
                        }

                        for(int i = 0; i < 26; i++)
                        {
                            if(cnt[i] > 0)
                            {
//                                printf("%d=\n", cnt[i]);
                                res = (res * A[cnt[i]]) % mod;
                            }

                        }
                    }
                }
            }
        }

        printf("Case #%d: %d\n", cas++, (int)res);
    }

    return 0;
}
