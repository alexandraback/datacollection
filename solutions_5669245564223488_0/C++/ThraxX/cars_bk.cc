#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <cmath>

using namespace std;

#define DBG(z) cerr << #z << ": " << (z) << endl
#define NEWL cerr << endl
#define passert(x, m) {if (!(x)) {cerr << m << "  ::  ";} assert(x);}
#define err(s) cerr << "[92m" << s << "[0m" << endl
#define err1(s) cerr << "[91m" << s << "[0m" << endl
#define LINE cerr << "DEBUG LINE: " << __LINE__ << endl

#define IT(v) __typeof((v).begin())
#define mem(f, a) memset(f, a, sizeof(f))
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define for_each(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define next_int() ({int __t; scanf("%d", &__t); __t;})

const int MOD = 1000000007;

//int N, MSK, dp[12][1 << 12], st[12], en[12], adj[12][12], vis[12], bad[50];


/*
int get(int top, int msk) {
    if (msk == SUPER)
        return 1;
    int &ret = dp[top][msk];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < N; ++i)
        if (st[i] == top && en[i] != top && (mask[i] & msk & ~(1 << top)) == 0)
            ret = (ret + get(en[i], msk | mask[i])) % MOD;
    for (int c = 0; c < 26; ++c)
        if (!(msk & (1 << c)))
            ret = (ret + get(c, msk | (1 << c)));
    return ret;
}
*/

char inp[1000001];
int N, st[120], en[120], mask[120], fact[120];

vector <int> topology;
int adj[26][26], vis[26];

void top_sort(int node) {
    if (vis[node]) return ;
    vis[node] = true;
    for (int nd = 0; nd < 26; ++nd)
        if (adj[node][nd] != -1)
            top_sort(nd);
    topology.push_back(node);
}

bool good(int n) {
    for (int i = 0, msk = 0, lst = -1; i < n; ++i) {
        int c = inp[i] - 'a';
        if (!(msk & (1 << c)) || (lst == c))
            msk |= 1 << c, lst = c;
        else
            return false;
    }
    return true;
}


vector <int> msks;
bool propagate(int c, int msk) {

    if (vis[c]) return false;
    vis[c] = true;
    int deg = 0, r = -1;
    bool ret = true;
    for (int nx = 0; nx < 26; ++nx)
        if (adj[c][nx] != -1)
            ++deg, r = nx;
    if (deg > 1) return false;

    if (r != -1) {
        ret &= (!(adj[c][r] & msk & ~(1 << c)));
        ret &= propagate(r, msk | adj[c][r]);
    } else {
        msks.push_back(msk);
    }
    return ret;
}

bool seen[26];

int main() {
    fact[0] = 1;
    for (int i = 0; i < 100; ++i)
        fact[i + 1] = (long long) (i + 1) * fact[i] % MOD;
    int T = next_int();
    for (int kase = 1; kase <= T; ++kase) {
        N = next_int();
        bool solve = true;
        mem(seen, 0);
        for (int i = 0; i < N; ++i) {
            scanf("%s", inp);
            int k = strlen(inp);
            st[i] = inp[0] - 'a';
            en[i] = inp[k - 1] - 'a';
            mask[i] = 0;
            for (int j = 0; j < k ; ++j)
                mask[i] |= 1 << (inp[j] - 'a');
            seen[st[i]] = seen[en[i]] = true;
            bool gd = good(k);
            solve &= gd;
            //err(st[i] << " " << en[i] << " " << mask[i] << " " << gd);
        }


        int res = 0;

        mem(adj, -1);
        for (int i = 0; i < N; ++i)
            if (st[i] != en[i]) {
                if (adj[st[i]][en[i]] == -1)
                    adj[st[i]][en[i]] = mask[i];
                else { solve = false; break; }
            }


        if (solve) {
            mem(vis, 0), topology.clear(), msks.clear();
            for (int c = 0; c < 26; ++c)
                top_sort(c);

            mem(vis, 0);
            int comp = 0;
            for (int i = topology.size() - 1; i >= 0; --i) {
                int nd = topology[i];
                if (!vis[nd] && seen[nd]) {
                    //err1("\t" << (char) (nd + 'a'));
                    ++comp;
                    solve &= propagate(nd, 0);
                    if (!solve) break;
                }
            }
            for (int i = 0; i < msks.size(); ++i)
                for (int j = 0; j < i; ++j)
                    solve &= !(msks[i] & msks[j]);
            //err(comp);
            
            if (solve) {
                res = fact[comp];
                for (int c = 0; c < 26; ++c) {
                    int cnt = 0;
                    for (int i = 0; i < N; ++i)
                        if (st[i] == en[i] && st[i] == c) ++cnt;
                    res = (long long) res * fact[cnt] % MOD;
                }
            }
        }

        printf("Case #%d: %d\n", kase, res);
    }
}

