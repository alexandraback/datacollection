#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <deque>
#include <map>
#include <set>
#include <vector>

using namespace std;

#ifdef DDEBUG
const int32_t M = 100;
const int32_t INF = 100;
#else
const int32_t M = 676061;
const int32_t INF = 0x7fffffff;
#endif

typedef struct TNode {
    int32_t west, east, height;
    TNode *left, *right;
    TNode() {}
    TNode(int32_t _w, int32_t _e, int32_t _h) : west(_w), east(_e), height(_h), left(NULL), right(NULL) {}
}TNode;

typedef struct Attack {
    int32_t west, east, strength;
    Attack(int32_t _w, int32_t _e, int32_t _s) : west(_w), east(_e), strength(_s) {}
}Attack;

vector<Attack> P[M];
TNode mem[10000000];
int32_t cnt;
TNode *root;
int32_t N;

bool Success(TNode *root, const Attack &att) {
#ifdef DDEBUG
    printf("att (%d, %d, %d) to (%d, %d, %d)\n", att.west, att.east, att.strength, root->west, root->east, root->height);
#endif
    if (root->left == NULL || root->west == att.west && root->east  == att.east) {
        return att.strength > root->height;
    }
    root->left->height = max(root->left->height, root->height);
    root->right->height = max(root->right->height, root->height);
    int32_t mid = (root->west + root->east) / 2;
    if (att.east <= mid) {
        return Success(root->left, att);
    } else if (att.west >= mid) {
        return Success(root->right, att);
    } else {
        Attack tmp = att;
        tmp.east = mid;
        if (Success(root->left, tmp)) return true;
        tmp = att;
        tmp.west = mid;
        return Success(root->right, tmp);
    }
}
void Update(const Attack &att, TNode **root) {
    if (att.west == (*root)->west && att.east == (*root)->east) {
        (*root)->height = max((*root)->height, att.strength);
        return;
    }
    int32_t mid = ((*root)->west + (*root)->east) / 2;
    if ((*root)->left == NULL) {
        mem[cnt] = TNode((*root)->west, mid, (*root)->height);
        mem[cnt + 1] = TNode(mid, (*root)->east, (*root)->height);
        (*root)->left = &mem[cnt];
        (*root)->right = &mem[cnt + 1];
        cnt += 2;
    }
    if (att.east <= mid) {
        Update(att, &(*root)->left);
    } else if (att.west >= mid) {
        Update(att, &(*root)->right);
    } else {
        Attack tmp = att;
        tmp.east = mid;
        Update(tmp, &(*root)->left);
        tmp = att;
        tmp.west = mid;
        Update(tmp, &(*root)->right);
    }
}
int32_t main() {
    int32_t cas = 0;
    scanf("%d", &cas);
    for (int32_t ic = 1; ic <= cas; ic++) {
        scanf("%d", &N);
        for (int32_t i = 0; i < M; i++) {
            P[i].clear();
        }
        for (int32_t i = 0; i < N; i++) {
            int32_t d, n, w, e, s, dd, dp, ds;
            scanf("%d%d%d%d%d%d%d%d", &d, &n, &w, &e, &s, &dd, &dp, &ds);
            for (int32_t j = 0; j < n; j++) {
                P[d + dd * j].push_back(Attack(w + dp * j, e + dp * j, s + ds *j));
            }
        }
        int32_t ans = 0;
        mem[0] = TNode(-INF, INF, 0);
        root = &mem[0];
        cnt = 1;
        for (int32_t i = 0; i < M; i++) {
            for (uint32_t j = 0; j < P[i].size(); j++) {
#ifdef DDEBUG
                printf("day %d: att (%d, %d, %d)\n", i, P[i][j].west, P[i][j].east, P[i][j].strength);
#endif
                if (Success(root, P[i][j])) {
#ifdef DDEBUG
                    printf("Success\n");
#endif
                    ans++;
                }
            }
            for (uint32_t j = 0; j < P[i].size(); j++) {
                Update(P[i][j], &root);
            }
        }
        printf("Case #%d: %d\n", ic, ans);
    }
    return 0;
}
