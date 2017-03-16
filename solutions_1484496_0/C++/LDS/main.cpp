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
#define N 2000010
char s1[N];
char s2[N];
char f[N];
int n1[N];
int n2[N];
int pre[N];
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
int sum;

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


double ans[N];

double bs(int x)
{
    double low = 0;
    double high = 1;
    double mid = (low + high) /2;
    double pmid = mid;
    double mys;
    double on;
    double oth;
    int i;
    while(1) {
        mys = n1[x] + sum * mid;
        oth = sum * (1-mid);
        on = 0;
        for(i = 0; i < n; i++) {
            if(i != x && n1[i] < mys) {
                on += mys-n1[i];
            }
        }
        if(high >= low && high - low <= 0.000000009 ||
           low >= high && low - high <= 0.000000009)break;
     //  printf("x = %d pmid = %.9lf mid=%.9lf oth=%.6lf on=%.6lf low=%.9lf high = %.9lf\n", x, pmid, mid, oth, on, low, high);

       if(on>=oth && on - oth <=0.000000001 ||
          oth > on && oth - on <=0.000000001)break;
        if(oth > on) low = mid;
        else high = mid;
        pmid = mid;
        mid = (low + high) / 2;
       // if(pmid <= mid && mid - pmid < 0.000000001 ||
         //  mid > pmid && pmid - mid  < 0.000000001) break;



    }
    return mid;
}
int q[N];
int q1[N];
int q2[N];
int c1,c2;
void solve()
{
    int i;
    int qh, qt;
    int j;
    int hj;
    int f;
    int s;
    int ss;
    memset(pre, -1, sizeof(pre));
    for(i = 0; i < n; i++) pre[n1[i]] = i;
    qh = 1;
    qt = 0;
    q[0] = n1[0];

    for(i = 1; i < n; i++) {
        hj = qh;
        for(j = 0; j < hj; j++) {
          s = n1[i] + q[j];
          if(pre[s] != -1) {
            //  printf("s = %d pre[s]=%d\n", s, pre[s]);
            f = 1;
            break;
          }
          pre[s] = i;
          q[qh++] = s;
        }
        if(f==1)break;
    }
    if(f == 0) {
        printf("Impossible\n");
        return;
    }
    c1 = 0;
    q1[c1++] = n1[i];
    ss  = s;
    while(ss != n1[i]) {
        ss -= n1[i];
        i = pre[ss];
        q1[c1++] = n1[i];
    }
    i = pre[s];
    c2 = 0;
    ss = s;
    q2[c2++] = n1[i];
    while(ss != n1[i]) {
        ss -= n1[i];
        i = pre[ss];
        q2[c2++] = n1[i];
    }

    for(i = 0; i < c1; i++) {
        for(j = 0; j < c2; j++) {
            if(q1[i] == q2[j]) break;
        }
        if(j != c2) {
            for(; j < c2 - 1; j++) q2[j] = q2[j+1];
            c2--;
            for(j = i; j < c1-1; j++) q1[j] = q1[j+1];
            c1--;
            i--;
        }
    }

    for(i = 0; i < c1-1; i++) printf("%d ", q1[i]);printf("%d\n", q1[i]);
    for(i = 0; i < c2-1; i++) printf("%d ", q2[i]);printf("%d\n", q2[i]);
}

int main()
{
    int d;

    int a;
    int i;
    int j;
    int c;
// freopen("in", "r", stdin);    freopen("out", "w", stdout);
    scanf("%d", &c);
    for(i = 1; i <= c; i++) {
        scanf("%d", &n);
        sum = 0;
        for(j = 0; j < n; j++){
         scanf("%d", &n1[j]);
        }
        printf("Case #%d:\n", i);
        solve();
    }
    return 0;
}
