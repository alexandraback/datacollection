#include <iostream>!
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
#define fo(i,b) for(int (i) = 0;(i) < (b);++(i))
#define fo2(i,a,b) for(int (i) = (a);(i) < (b);++(i))
#define N 100010
char s1[N];
char s2[N];
char f[N];
int n1[N];
int n2[N];
int A, B;
typedef struct T
{
    int one;
    int two;
    int fo;
    int fw;
    int inq;
}T;

T t[N];
int n;

typedef struct node {
     int idx;
}node;

struct pcmp {
     bool operator() (const node &a, const node &b)
     {
        return (a.idx < b.idx);
        // else return true;
     }
};

priority_queue<node, vector<node>, pcmp> p;
int cmp(const void *aa, const void *bb)
{
    T *a = (T*)aa;
    T *b = (T*)bb;
    if(a->two == b->two) return b->one - a->one;
    return a->two - b->two;
}



void solve()
{
    int i;
    int j;
    int ans = 0;
    int s = 0;
    qsort(t, n, sizeof(t[0]), cmp);
    while(!p.empty()) p.pop();
    for(i = 0; i < n; i++) {
        if(t[i].one == 0 && t[i].inq == 0) {
            node nn;nn.idx = i;
            t[i].inq =1;
            p.push(nn);
        }
    }
 /*   for(i = 0; i < n; i++) {
        node nn;
        nn.idx = i;
        nn.one = t[i].one;
        p.push(nn);
    }*/
    for(i = 0; i < n; i++) {
        if(t[i].two <= s) {
            t[i].fw = 1;
            if(t[i].fo == 0) {
                t[i].fo = 1;
                s += 2;
                for(j = i; j < n; j++) {
                    if(t[j].one > s - 2 && t[j].one <= s && t[j].inq == 0) {
                        node nn;nn.idx = j;
                        t[j].inq =1;
                        p.push(nn);
                    }
                }
            } else {
                s += 1;
                for(j = i; j < n; j++) {
                    if(t[j].one > s - 1 && t[j].one <= s && t[j].inq == 0) {
                        node nn;nn.idx = j;
                        t[j].inq =1;
                        p.push(nn);
                    }
                }
            }
            ans++;
        } else {
            while(!p.empty()) {
                node nn = p.top();
                p.pop();
                if(nn.idx < i) continue;
                if(t[nn.idx].fo == 0) {
                    t[nn.idx].fo = 1;
                    ans++;
                    s++;
                    for(j = i; j < n; j++) {
                        if(t[j].one > s - 1 && t[j].one <= s && t[j].inq == 0) {
                            node nn;nn.idx = j;
                            t[j].inq =1;
                            p.push(nn);
                        }
                    }
                    if(s >= t[i].two) break;
                }
            }/*
            while(1) {
              for(j = n-1; j >= i; j--)  {
                if(t[j].one <= s && t[j].fo == 0) {
                    t[j].fo = 1;
                    s+= 1;
                    ans++;
                    break;
                }
              }*/
              //if( s >= t[i].two)break;
              if(s < t[i].two) { printf("Too Bad\n");return ;}

            i--;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    int d;

    int a;
    int i;
    int j;
    int ans;
    int c;
 //freopen("in", "r", stdin);    freopen("out", "w", stdout);
    scanf("%d", &c);
    for(i = 1; i <= c; i++) {
        scanf("%d", &n);
        for(j = 0; j < n; j++){
         scanf("%d %d", &t[j].one, &t[j].two);
         t[j].fo = t[j].fw = t[j].inq = 0;
        }
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
