#include <iostream>
#include <iomanip>
#include <cstdio>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;

struct MCMF {
    static const int szE = 200000;
    static const int szV = 10000;
    int topE = 0;

    int to[szE] = { 0 };
    int cost[szE] = { 0 };
    int flow[szE] = { 0 };
    int mxflow[szE] = { 0 };
    int prev_[szE] = { 0 };

    int topV = 0;

    int last[szV] = { 0 };
    int poten[szV] = { 0 };
    int from[szV] = { 0 };
    pii dst[szV] = { {0, 0} };
    bool was[szV] = { 0 };
    
    MCMF() {
        memset(prev_, -1, sizeof prev_);
        memset(last, -1, sizeof last);
    }

    void _add_(int f, int t, int mf, int cs)
    {
        mxflow[topE] = mf;
        cost[topE] = cs;
        to[topE] = t;
        prev_[topE] = last[f];
        last[f] = topE;
        ++topE;
    }

    void add(int f, int t, int mf, int cs) {
        _add_(f, t, mf, cs);
        _add_(t, f, 0, -cs);
    }

    int inf = 1e9;

    void warshall(int from, int n)
    {
        for (int i = 0; i<n; ++i)
            poten[i] = inf;
        poten[from] = 0;
        bool b = true;
        for (int i = 0; b&&i<n; ++i)
        {
            b = false;
            for (int j = 0; j<n; ++j)
                for (int k = last[j]; k != -1; k = prev_[k])
                    if (mxflow[k] - flow[k]>0 && poten[j] + cost[k]<poten[to[k]])
                    {
                        poten[to[k]] = poten[j] + cost[k];
                        b = true;
                    }
        }
    }

    set<pii> st;

    pii dijkstra(int FROM, int trg, int n)
    {
        for (int i = 0; i<n; ++i)
        {
            dst[i].first = inf;
            dst[i].second = 0;
            was[i] = false;
        }
        dst[FROM] = pii(0, inf);
        st.insert(pii(0, FROM));
        while (!st.empty())
        {
            pii curr = *st.begin();
            st.erase(curr);
            was[curr.second] = 1;
            for (int k = last[curr.second]; k != -1; k = prev_[k])
            {
                if (!was[to[k]] && mxflow[k] - flow[k]>0 && dst[to[k]].first >= dst[curr.second].first - poten[to[k]] + cost[k] + poten[curr.second])
                {
                    st.erase(pii(dst[to[k]].first, to[k]));
                    dst[to[k]].first = dst[curr.second].first - poten[to[k]] + cost[k] + poten[curr.second];
                    dst[to[k]].second = min(dst[curr.second].second, mxflow[k] - flow[k]);
                    from[to[k]] = k;
                    st.insert(pii(dst[to[k]].first, to[k]));
                }
            }
        }
        if (dst[trg].second>0)
        {
            int curr = trg;
            while (curr != FROM)
            {
                flow[from[curr]] += dst[trg].second;
                flow[from[curr] ^ 1] -= dst[trg].second;
                curr = to[from[curr] ^ 1];
            }
        }
        return pii(dst[trg].first + poten[trg], dst[trg].second);
    }

    pii mcmf(int from, int trg, int n)
    {
        warshall(from, n);
        pii f = dijkstra(from, trg, n);
        int answ = 0;
        int flow = 0;
        while (f.second>0 && f.first < 0)
        {
            answ += f.first*f.second;
            flow += f.second;
            f = dijkstra(from, trg, n);
        }
        return {answ, flow};
    }
};

void init() {
}

void test() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> edges;
    map<string, int> ws[2];
    rep(i, 0, n) {
        vector<int> curEdge;
        rep(j, 0, 2) {
            char buf[1000];
            scanf(" %s", buf);
            auto &cm = ws[j];
            if (cm.find(buf) == cm.end()) {
                int sz = cm.size();
                cm[buf] = sz;
            }
            curEdge.push_back(cm[buf]);
        }
        edges.push_back(curEdge);
    }

    MCMF *_mcmf = new MCMF, &mcmf = *_mcmf;
    int leftSize = ws[0].size(), rightSize = ws[1].size();
    int S = 0, T = 1, fps = 2, sps = fps + leftSize, total = sps + rightSize;
    rep(i, 0, leftSize) {
        mcmf.add(S, fps + i, 1, -1005);
        mcmf.add(S, fps + i, 1005, 0);
    }
    rep(i, 0, rightSize) {
        mcmf.add(sps + i, T, 1, -1005);
        mcmf.add(sps + i, T, 1005, 0);
    }
    rep(i, 0, edges.size()) {
        int fn = edges[i][0], sn = edges[i][1];
        mcmf.add(fps + fn, sps + sn, 1, 1);
    }

    auto res = mcmf.mcmf(S, T, total);
    int flw = res.second;
    int unused = n - flw;

	printf("%d\n", unused);
    delete _mcmf;
}

void run()
{
	init();
	int tc;
	scanf("%d", &tc);
	rep(i, 0, tc) {
		printf("Case #%d: ", i + 1);
		test();
	}
}

//#define prob "fence"

int main()
{
#ifdef LOCAL_DEBUG
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#else 
#ifdef prob
    freopen(prob".in","r",stdin);
    freopen(prob".out","w",stdout);
#endif
#endif

    run();

#ifdef LOCAL_DEBUG
    fprintf(stderr, "\n=============\n");
    fprintf(stderr, "Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
    
    return 0;
}