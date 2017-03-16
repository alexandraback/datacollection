#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 128;
const int ALPHA = 32;
const int MOD = 1000000007;

typedef long long llint;

struct node {
    int st, end, nr;
    node(){}
    node(int ist, int iend, int inr):
            st(ist), end(iend), nr(inr){}
};

int n;
int pure[ALPHA];
int mid[ALPHA];
int father[SIZE];
int out[SIZE];
int circle[ALPHA][ALPHA];
int afront[ALPHA], aend[ALPHA];
vector<node> nodes;

llint calc_permutation(int v)
{
    llint res = 1;
    for (int i = 1; i <= v; i++) {
        res *= i;
        res %= MOD;
    }
    return res;
}

int findfather(int x)
{
    if (x == father[x]) return x;
    else return father[x] = findfather(father[x]);
}

void init()
{
    memset(pure, 0, sizeof(pure));
    memset(mid, -1, sizeof(mid));
    memset(out, -1, sizeof(out));
    memset(circle, 0, sizeof(circle));
    memset(afront, 0, sizeof(afront));
    memset(aend, 0, sizeof(aend));
    for (int i = 0; i < SIZE; i++) {
        father[i] = i;
    }
    nodes.clear();
}

int clean_str(const string& buffer, int len, int nr, node& resnode)
{
    // TEST CASE:
    // * A
    // * ABC
    // * ABBC
    // * ABBBBCCCDD
    // * ABCBCBCBCDD

    // PURE such as AAA or BBB
    set<char> st;
    for (int i = 0; i < len; i++) {
        st.insert(buffer[i]);
    }
    if (st.size() == 1) {
        int now = buffer[0] - 'a';
        if (mid[now] != -1) {
            return -1;
        }
        pure[buffer[0] - 'a']++;
        return 0;
    }
    // NOT PURE such as ABD or ABBBBBBCCD
    st.clear();
    for (int i = 0; i < len; i++) {
        char now = buffer[i];
        if (i) {
            char pre = buffer[i - 1];
            if (now != pre && st.find(now) != st.end()) {
                // ABAC -> wrong!!!!
                return -1;
            }
        }
        st.insert(now);
    }
    int l = 0, r = len - 1;
    while (l + 1 < len && buffer[l + 1] == buffer[l]) l++;
    while (r - 1 >= 0 && buffer[r - 1] == buffer[r]) r--;
    l++;r--;
    while (l <= r) {
        int now = buffer[l] - 'a';
        if (pure[now] || out[now] != -1 || (mid[now] != -1 && mid[now] != nr)) {
            return -1;
        } else if (mid[now] == -1) {
            mid[now] = nr;
        }
        l++;
    }
    if (buffer[0] - 'a' == buffer[len - 1] - 'a') {
        return -1;
    }
    resnode = node(buffer[0] - 'a', buffer[len - 1] - 'a', nr);
    out[buffer[0] - 'a'] = out[buffer[len - 1] - 'a'] = nr;
    int a = buffer[0] - 'a', b = buffer[len - 1] - 'a';

    if (circle[b][a]) return -1;
    else circle[a][b] = nr;

    if (afront[a]) return -1;
    else afront[a] = nr;

    if (aend[a]) return -1;
    else aend[a] = nr;
    return 1;
}

llint solve()
{
    for (int i = 0; i < (int)nodes.size(); i++) {
        int a = nodes[i].st;
        int b = nodes[i].end;

        father[findfather(b)] = findfather(a);
    }
    set<int> st;
    for (int i = 0; i < (int)nodes.size(); i++) {
        int a = nodes[i].st;
        int b = nodes[i].end;
        st.insert(findfather(a));
        st.insert(findfather(b));
    }
    int v = (int)st.size();

    for (int i = 0; i < ALPHA; i++) {
        if (pure[i] && out[i] == -1) {
            v++;
        }
    }

    llint res = calc_permutation(v);
    for (int i = 0; i < ALPHA; i++) {
        if (pure[i]) {
            res *= calc_permutation(pure[i]);
            res %= MOD;
        }
    }
    return res;
}

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int cas = 1;
    int T;
    string buffer;
    input(T);
    while (T--) {
        bool clean = true;
        init();
        input(n);
        for (int i = 1; i <= n; i++) {
            input(buffer);
            int len = buffer.size();
            node resnode;
            int res = clean_str(buffer, len, i, resnode);
            if (res == 1) {
                nodes.push_back(resnode);
            } else if (res == -1) {
                // printf("%s is NOT CLEAN\n", buffer.c_str());
                clean = false;
            }
        }
        if (clean) {
            printf("Case #%d: %lld\n", cas++, solve());
        } else {
            printf("Case #%d: %lld\n", cas++, 0LL);
        }
    }
    return 0;
}
