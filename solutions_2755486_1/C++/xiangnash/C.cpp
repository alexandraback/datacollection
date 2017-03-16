/**********************************************************************
Author: Lixiang Liu
Created Time:  Sat 04 May 2013 11:39:34 PM CST
File Name: Sample.cpp
Description: 
**********************************************************************/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
const int maxint=0x7FFFFFFF;
const int MAXN = 1000010;    

struct tree_t {
    int lt, rt;
    int smin, smax;
    bool leaf;
    tree_t *lc, *rc;
};

struct tribe_t {
    int d, n, w, e, s, dd, dp, ds;
    int id;
    bool operator<(const tribe_t &another) const {
        return d > another.d;
    }
};

tree_t tree;
tribe_t tribe[1010];

void tree_init(int lt, int rt) {
    tree.lt = lt, tree.rt = rt;//FIXME:
    tree.smin = tree.smax = 0;
    tree.leaf = true;
    tree.lc = tree.rc = NULL; //FIXME:
}

void tree_dis(tree_t *now) {
    if (now == NULL) {
        return ;
    }
    tree_dis(now->lc);
    tree_dis(now->rc);
    delete now->lc;
    delete now->rc;
}

bool query(tree_t *now, int lt, int rt, int s) {
    if (now->smin >= s) {
        return false;
    }
    if (now->smax < s) {
        return true;
    }
    if (now->leaf) {
        return s > now->smin;
    }
    if (lt < now->lc->rt) {
        if (query(now->lc, lt, rt, s)) {
            return true;
        }
    }
    if (now->rc->lt < rt) {
        if (query(now->rc, lt, rt, s)) {
            return true;
        }
    }
    return false;
}

void insert(tree_t *now, int lt, int rt, int s) {
    if (now->smin > s) {
        return ;
    }
    if (now->smax < s) {
        now->smax = s;
    }
    
    if (now->leaf) {
        if (lt <= now->lt && now->rt <= rt) {
            now->smin = now->smax = s;
            return ;
        }
        else {
            if (rt < now->rt) {
                now->leaf = false;
                now->lc = new tree_t;
                now->rc = new tree_t;
                now->lc->leaf = now->rc->leaf = true;
                now->lc->lc = now->lc->rc = now->rc->lc = now->rc->rc = NULL;
                now->lc->lt = now->lt, now->lc->rt = rt;
                now->rc->lt = rt, now->rc->rt = now->rt;
                now->lc->smin = now->lc->smax = now->rc->smin = now->rc->smax = now->smin;
            }
            else if (lt > now->lt) {
                now->leaf = false;
                now->lc = new tree_t;
                now->rc = new tree_t;
                now->lc->leaf = now->rc->leaf = true;
                now->lc->lc = now->lc->rc = now->rc->lc = now->rc->rc = NULL;
                now->lc->lt = now->lt, now->lc->rt = lt;
                now->rc->lt = lt, now->rc->rt = now->rt;
                now->lc->smin = now->lc->smax = now->rc->smin = now->rc->smax = now->smin;
            }
        }
    }    
    now->leaf = false;
    if (lt < now->lc->rt) {
        insert(now->lc, lt, rt, s);
    }
    if (rt > now->rc->lt) {
        insert(now->rc, lt, rt, s);
    }
    now->smin = min(now->lc->smin, now->rc->smin);
    now->smax = max(now->lc->smax, now->rc->smax);
    if (now->smin == now->smax) {
        now->leaf = true;
        //TODO
        tree_dis(now->lc);
        tree_dis(now->rc);
        now->lc = now->rc = NULL;
    }
}
    
int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        int N;
        scanf("%d", &N);
        priority_queue<tribe_t> attack;
        int mlt = 0, mrt = 0;
        for (int i = 0; i < N; ++i) {
            scanf("%d %d %d %d %d %d %d %d", &tribe[i].d, &tribe[i].n, &tribe[i].w, &tribe[i].e, &tribe[i].s,
                    &tribe[i].dd, &tribe[i].dp, &tribe[i].ds);
            mlt = min(mlt, tribe[i].w + (tribe[i].n-1)*tribe[i].dp);
            mrt = max(mrt, tribe[i].e + (tribe[i].n-1)*tribe[i].dp);
            mlt = min(mlt, tribe[i].w);
            mrt = max(mrt, tribe[i].e);
            tribe[i].id = i;
            attack.push(tribe[i]);
        }
        
//        cout << mlt << "-->" << mrt << endl;//
        
        tree_init(mlt, mrt); //TODO
        
        int ans = 0;
        
        int ops[1010], opNum = 0, day = -1;
        while (!attack.empty()) {
            tribe_t now = attack.top(); attack.pop();
            if (now.d > day) {
                //operations
                for (int i = 0; i < opNum; ++i) {
                   insert(&tree, tribe[ ops[i] ].w, tribe[ ops[i] ].e, tribe[ ops[i] ].s); //TODO:
                }
                opNum = 0;
                day = now.d;
            }
            
            if (query(&tree, now.w, now.e, now.s)) {
//                cout << "YES" << endl;//
                ++ans;
                ops[ opNum++ ] = now.id;
            }
            
//            cout << now.d << ": " << now.w << "-->" << now.e << " " << now.s << endl;///
            tribe[ now.id ].s = now.s;
            tribe[ now.id ].w = now.w;
            tribe[ now.id ].e = now.e;
            
            --now.n;
            now.d += now.dd;
            now.w += now.dp;
            now.e += now.dp;
            now.s += now.ds;
            
            if (now.n > 0) {
                attack.push(now);
            }
        }
        
        tree_dis(&tree);
        
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}

