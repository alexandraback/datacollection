#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int T, N;
int a[1003], b[1003], v[1003];

struct info
{
    int r, i;
    info(int _r, int _i) : r(_r), i(_i) {}
    bool operator<(const info& o) const // priority queue
    {
        return r>o.r; // <
    }
};

int main()
{
    //freopen("in.txt", "rt", stdin);
    freopen("B-large.in", "rt", stdin);
    freopen("B-large.out", "wt", stdout);
    cin>>T;
    for (int cas=1; cas<=T; ++cas)
    {
        memset(v, 0, sizeof v);
        priority_queue<info> B;
        cin>>N;
        for (int i=0; i<N; ++i)
        {
            cin>>a[i]>>b[i];
            B.push(info(b[i],i));
        }
        int cnt = 0, hav = 0;
        bool toobad = false;
        while (!B.empty())
        {
            if (!B.empty() && B.top().r<=hav)
            {
                info t = B.top(); B.pop();
                if (v[t.i]==2) continue;
                hav += 2-v[t.i];
                v[t.i] = 2;
                ++cnt;
                continue;
            }
            int bigi = -1;
            for (int i=0; i<N; ++i) if (!v[i] && a[i]<=hav && (bigi==-1 || b[bigi]<b[i])) bigi = i;
            if (bigi==-1)
            {
                toobad = true;
                break;
            }
            else
            {
                v[bigi] = 1;
                hav += 1;
                ++cnt;
            }
        }
        if (toobad) printf("Case #%d: Too Bad\n", cas);
        else printf("Case #%d: %d\n", cas, cnt);
    }
    return 0;
}
