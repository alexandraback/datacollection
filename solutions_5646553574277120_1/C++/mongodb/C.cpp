#include <iostream>
#define MAXN 100000
using namespace std;
struct node {
    int l, r;
    long long sum;
} tree[(MAXN<<2)+5];

void build(int id, int l, int r) {
    tree[id].l = l, tree[id].r = r;
    if (l == r) {
        tree[id].sum = a[l];
    } else {
        int next = (id << 1), mid = ((l+r) >> 1);
        build(next, l, mid);
        build(next|1, mid+1, r);
        tree[id].sum = tree[next].sum+tree[next|1].sum;
    }
}
void update(int id, int pos, long long value_change) {
    if (tree[id].l == tree[id].r) {
        tree[id].sum += value_change;
    } else {
        int next = (id << 1), mid = ((tree[id].l+tree[id].r) >> 1);
        if (pos <= mid) {
            update(next, pos, value_change);
        } else {
            update(next|1, pos, value_change);
        }
        tree[id].sum += value_change;
    }
}
long long query(int id, int l, int r) {
    if (tree[id].l == l && tree[id].r == r) {
            return tree[id].sum;
    }
    int next = (id << 1), mid = ((tree[id].l+tree[id].r) >> 1);
    if (l <= mid) {
        if (r <= mid) {
            return query(next, l, r);
        } else {
            return query(next, l, mid)+query(next|1, mid+1, r);
        }
    } else {
        return query(next|1, l, r);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
}
