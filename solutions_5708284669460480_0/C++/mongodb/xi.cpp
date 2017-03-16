#include <cstdio>
#define MAXN 100000

typedef long long int int64;

struct node {
    int64 left, right;
    int64 sum;
    int64 lazy;
};

node tree[4*MAXN+3];
int64 a[MAXN+3];

void build(node *tree, int64 id, int64 left, int64 right, int64 *a) {
    tree[id].left = left; tree[id].right = right; tree[id].lazy = 0;
    if (left == right) {
        tree[id].sum = a[left];
    } else {
        int64 mid = (left+right)/2, next = id*2;
        build(tree, next, left, mid, a);
        build(tree, next+1, mid+1, right, a);
        tree[id].sum = tree[next].sum+tree[next+1].sum;
    }
}
void push_down(node *tree, int64 id) {
    if (tree[id].left == tree[id].right) return;
    int64 next = id*2;
    tree[next].sum += tree[id].lazy*(tree[next].right-tree[next].left+1);
    tree[next].lazy += tree[id].lazy;
    tree[next+1].sum += tree[id].lazy*(tree[next+1].right-tree[next+1].left+1);
    tree[next+1].lazy += tree[id].lazy;
    tree[id].lazy = 0;
}
void update(node *tree, int64 id, int64 left, int64 right, int64 value_change) {
    if (tree[id].left == left && tree[id].right == right) {
        tree[id].lazy += value_change;
        tree[id].sum += value_change*(right-left+1);
        if (tree[id].lazy != 0) push_down(tree, id);
        return;
    }
    if (tree[id].lazy != 0) push_down(tree, id);
    int64 mid = (tree[id].right+tree[id].left)/2, next = id*2;
    if (right <= mid) {
        update(tree, next, left, right, value_change);
    } else {
        if (left > mid) {
            update(tree, next+1, left, right, value_change);
        } else {
            update(tree, next, left, mid, value_change);
            update(tree, next+1, mid+1, right, value_change);
        }
        //tree[id].sum = tree[next].sum+tree[next+1].sum;
    }
    tree[id].sum = tree[next].sum+tree[next+1].sum;
}
int64 query(node *tree, int64 id, int64 left, int64 right) {
    if (tree[id].lazy != 0) push_down(tree, id);
    if (tree[id].left == left && tree[id].right == right) {
        return tree[id].sum;
    }
    int64 mid = (tree[id].left+tree[id].right)/2, next = id*2;
    if (right <= mid) return query(tree, next, left, right);
    if (left > mid) return query(tree, next+1, left, right);
    return query(tree, next, left, mid)+query(tree, next+1, mid+1, right);
}

int main() {
    int64 n, m, tmp, position, value_change, left, right;
    scanf("%lld", &n);
    for (int64 i = 1; i <= n; i++) scanf("%lld", &a[i]); scanf("%lld", &m);
    build(tree, 1, 1, n, a);
    for (int64 i = 0; i < m; i++) {
        scanf("%lld%lld%lld", &left, &right, &value_change);
        update(tree, 1, left, right, value_change);
        printf("%lld\n", query(tree, 1, left, right));
    }
    return 0;
}
