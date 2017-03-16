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
void solve()
{
    int i;
    for(i = 0; i < n; i++) ans[i] = bs(i);
    for(i = 0; i < n - 1; i++) printf("%.6lf ", ans[i]*100);
    printf("%.6lf\n", ans[i]*100);
}

int main()
{
    int d;

    int a;
    int i;
    int j;
    int c;
 //freopen("in", "r", stdin);    freopen("out", "w", stdout);
    scanf("%d", &c);
    for(i = 1; i <= c; i++) {
        scanf("%d", &n);
        sum = 0;
        for(j = 0; j < n; j++){
         scanf("%d", &n1[j]);
         sum += n1[j];
        }
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
