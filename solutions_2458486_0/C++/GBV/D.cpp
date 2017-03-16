#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <list>
#include <set>
#include <ctime>
#include <list>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define vi vector<int>
#define vd vector<double>
#define pii pair<int,int>
#define pdd pair<double,double>
#define ll long long
#define INF (1<<30)
using namespace std;

const int MAXS = (1<<20);
const int MAXN = 32;
vector<int> DP[MAXS];
vector<pii> avail[MAXS];
int K, N;
vector<int> tp;
int key[MAXN];
vector<int> get[MAXN];

void reset()
{
    for(int i = 0; i < MAXS; ++i)
    {
        DP[i].clear();
        avail[i].clear();
    }
}

vector<pii> get_av(vector<int> tp)
{
    vector<pii> ret;
    sort(tp.begin(), tp.end());
    int i, l = 1;
    for(i = 1; i < tp.size(); ++i)
    {
        if(tp[i] == tp[i - 1]) ++l;
        else
        {
            ret.pb(mp(tp[i - 1], l));
            l = 1;
        }
    }
    ret.pb(mp(tp[tp.size() - 1], l));
    return ret;
}

void solve_case(int case_id)
{
    printf("Case #%d: ", case_id);
    int i, j, mask, l;
    reset();
    cin >> K >> N;
    tp.clear(); tp.resize(K);
    for(i = 0; i < K; ++i) cin >> tp[i];
    avail[0] = get_av(tp);

    for(i = 0; i < N; ++i)
    {
        cin >> key[i] >> l;
        get[i].clear(); get[i].resize(l);
        for(j = 0; j < l; ++j) cin >> get[i][j];
    }

    vector<int> all, g;
    vector<pii> pr;
    bool sd[MAXN];
    for(mask = 1; mask < (1 << N); ++mask)
    {
        all = tp;
        for(i = 0; i < N; ++i) sd[i] = ((mask & (1<<i)) > 0);
        for(i = 0; i < N; ++i)
        {
            if(sd[i])
            {
                for(j = 0; j < get[i].size(); ++j) all.pb(get[i][j]);
            }
        }
        bool ok = true;
        pr = get_av(all);
        for(i = 0; i < N; ++i)
        {
            if(sd[i])
            {
                for(j = 0; j < pr.size(); ++j)
                {
                    if(pr[j].x == key[i])
                    {
                        --pr[j].y;
                        if(pr[j].y < 0)
                        {
                            ok = false;
                            break;
                        }
                    }
                }
                if(!ok) break;
            }
        }
        if(!ok) continue;
        avail[mask] = pr;
        for(i = 0; i < N; ++i)
        {
            if(!sd[i]) continue;
            l = mask - (1<<i);
            if(l != 0 && DP[l].size() == 0) continue;
            ok = false;
            for(j = 0; j < avail[l].size(); ++j)
            {
                if(avail[l][j].x == key[i] && avail[l][j].y > 0)
                {
                    ok = true;
                    break;
                }
            }
            if(!ok) continue;
            g = DP[l];
            g.pb(i + 1);
            if(DP[mask].size() == 0 || DP[mask] > g) DP[mask] = g;
        }
    }
    l = (1<<N) - 1;
    if(DP[l].size() == 0) printf("IMPOSSIBLE\n");
    else
    {
        for(i = 0; i < DP[l].size() - 1; ++i) printf("%d ", DP[l][i]);
        printf("%d\n", DP[l][DP[l].size() - 1]);
    }
}

int main()
{
    int i, t;
    scanf("%d", &t);
    for(i = 1; i <= t; ++i) solve_case(i);
    return 0;
}
