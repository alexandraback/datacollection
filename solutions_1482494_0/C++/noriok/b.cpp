#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
#define For(i,x) for (int i=0; i<(int)(x); i++)
#define mp make_pair

struct D {
    int node;
    int used;
    int times;
    int star;
    bool operator<(const D& o) const {
        return times > o.times;
    }
};

bool isGoal(int n, int used) {
    For(i, n) {
        if (!(used & (1<<(2*i+1))))
            return false;
    }
    return true;
}

bool isVisited(int node, int level, int visited) {
    int x = level == 1 ? 0 : 1;
    return (visited & (1<<(2*node+x)));
}

int calc(int n, vector<pair<int, int> >& v) {


    priority_queue<D> pq;
    For(i, v.size()) {
        if (v[i].first == 0)
            pq.push((D){ i, (1<<(i*2)), 1, 1 });
        if (v[i].second == 0)
            pq.push((D){ i, (1<<(i*2+1)), 1, 2 });
    }

    map<int, int> used;

    while (!pq.empty()) {
        D d = pq.top(); pq.pop();

        if (isGoal(n, d.used)) return d.times;

        if (++used[d.used] > 1) continue;

        For(i, n) {
            if (!isVisited(i, 2, d.used) && d.star >= v[i].second) {
                //printf("visit node:%d level:2\n", i);
                int star = isVisited(i, 1, d.used) ? 1 : 2;
                pq.push((D){ i, (d.used | (1<<(2*i+1))), d.times+1, d.star+star });
            }
            if (!isVisited(i, 1, d.used) && d.star >= v[i].first) {
                if (!isVisited(i, 2, d.used)) {
                    //printf("visit node:%d level:1\n", i);
                    pq.push((D){ i, (d.used | (1<<(2*i))), d.times+1, d.star+1 });
                }
            }
        }

    }

    return -1;
}

int main() {
    int ncases;
    scanf("%d", &ncases);

    For(cc, ncases) {
        int n;
        scanf("%d", &n);
        vector<pair<int, int> > v;
        For(i, n) {
            int a, b;
            scanf("%d %d", &a, &b);
            v.push_back(mp(a, b));
        }

        printf("Case #%d: ", cc+1);
        int ans = calc(n, v);
        if (ans == -1)
            puts("Too Bad");
        else
            printf("%d\n", ans);
    }
}
