#include <algorithm>
#include <iostream>
#include <limits>
#include <set>
#include <vector>

using namespace std;

const int MAXL = 1000000;
const int ADD = 500000;

class segment_tree {
public:
    explicit segment_tree(int _size)
        : size(_size),
        tree(4 * _size + 1) {}

    int query(int left, int right) {
        return query(1, LEFTMOST, RIGHTMOST, left, right);
    }

    void update(int left, int right, int val) {
        update(1, LEFTMOST, RIGHTMOST, left, right, val);
    }

private:
    int query(int node, int left, int right, int x, int y) {
        if (x <= left && right <= y) {
            return tree[node];
        } else {
            int mid = (left + right) / 2;

            int res = numeric_limits<int>::max();
            if (x <= mid)
                res = min(res, query(2 * node, left, mid, x, y));
            if (y > mid)
                res = min(res, query(2 * node + 1, mid + 1, right, x, y));

            return res;
        }
    }

    void update(int node, int left, int right, int x, int y, int val) {
        if (x <= left && right <= y) {
            tree[node] = max(tree[node], val);
        } else {
            int mid = (left + right) / 2;

            if (x <= mid) 
                update(2 * node, left, mid, x, y, val);
            if (y > mid)
                update(2 * node + 1, mid + 1, right, x, y, val);

            tree[node] = max(tree[node], max(tree[2 * node], 
                        tree[2 * node + 1]));
        }
    }

    static const int LEFTMOST = -1000000;
    static const int RIGHTMOST = 1000000;

    int size;
    vector<int> tree;
};

struct assault {
    int id;
    int d;
    int x, y, h;

    assault(int _id, int _d, int _x, int _y, int _h)
        : id(_id), d(_d), x(_x), y(_y), h(_h) {}
};

struct comp {
    bool operator() (const assault& lhs, const assault& rhs) {
        if (lhs.d == rhs.d)
            return lhs.id < rhs.id;
        return lhs.d < rhs.d;
    }
};

int main()
{
    int T;
    cin >> T;

    for (int id = 1; id <= T; ++id) {
        vector<assault> v;

        int N;
        cin >> N;

        for (int i = 0; i < N; ++i) {
            int d, n, w, e, s, delta_d, delta_p, delta_s;
            cin >> d >> n >> w >> e >> s >> delta_d >> delta_p >> delta_s;

            for (int j = 0; j < n; ++j) {
                v.push_back(assault(j, d, 2 * w, 2 * e, s));
                d += delta_d;
                w += delta_p;
                e += delta_p;
                s += delta_s;
            }
        }
        sort(begin(v), end(v), comp());

        int cnt = 0;
        vector<int> height(2 * MAXL);
        for (int i = 0; i < v.size();) {
            int j;
            for (j = i; j < v.size(); ++j) {
                if (v[j].d != v[i].d)
                    break;
                for (int k = v[j].x + ADD; k <= v[j].y + ADD; ++k)
                    if (height[k] < v[j].h) {
                        ++cnt;
                        break;
                    }
            }
            for (int k = i; k < j; ++k) {
                for (int l = v[k].x + ADD; l <= v[k].y + ADD; ++l) 
                    height[l] = max(height[l], v[k].h);
            }
            i = j;
        }

        cout << "Case #" << id << ": " << cnt << "\n";
    }

    return 0;
}
