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
#define N 2000
char s1[N];
char s2[N];
char f[N];
long long n1[N];
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
map<long long, int> cm;

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
long long q[N];
long long q1[N];
long long q2[N];
int c1,c2;
void solve()
{
    int i;
    int qh, qt;
    int j;
    int hj;
    int f;
    long long s;
    long long ss;
    map<long long , int>::iterator iter;
    cm.clear();
    //while(!cm.empty())
    memset(pre, -1, sizeof(pre));
    //for(i = 0; i < n; i++) pre[n1[i]] = i;
    for(i= 0; i < n; i++) cm[n1[i]] = i;
    qh = 1;
    qt = 0;
    q[0] = n1[0];

    for(i = 1; i < n; i++) {
        hj = qh;
        for(j = 0; j < hj; j++) {
          s = n1[i] + q[j];
          iter = cm.find(s);
         // if(pre[s] != -1) {
         if(iter != cm.end()){
          //  printf("s = %lld pre[s]=%d\n", s, iter->second);
            f = 1;
            break;
          }
          //pre[s] = i;
          cm[s] = i;
          q[qh++] = s;
          if(cm.size() == N - 1) {

           printf("Impossible\n");
           return;
           }
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
        //i = pre[ss];
        i = cm.find(ss)->second;
        q1[c1++] = n1[i];
    }
  //  i = pre[s];
    i = cm.find(s)->second;
    c2 = 0;
    ss = s;
    q2[c2++] = n1[i];
    while(ss != n1[i]) {
        ss -= n1[i];
        //i = pre[ss];
        i = cm.find(ss)->second;
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

    for(i = 0; i < c1-1; i++) printf("%lld ", q1[i]);printf("%lld\n", q1[i]);
    for(i = 0; i < c2-1; i++) printf("%lld ", q2[i]);printf("%lld\n", q2[i]);
}

double ti[N];
double xi[N];
double vi[N];

int ta;
double ai[N];
double td;
//double
void solve1()
{
    int i, j, f;
    double v0;
    double t0, tmp;
    double a0, b0, c0, x0, s0;
    for(i = 0; i < n - 1; i++) {
        vi[i] = (xi[i+1] - xi[i]) / (ti[i+1] - ti[i]);
        vi[i+1]=vi[i];
    }
    while(n>= 2 && xi[n-2]>=td)n--;
    if(n >= 2) {
        //x[n-1] = di;
        xi[n-1]= td;
        ti[n-1] = ti[n-2] + (td-xi[n-2])/vi[n-2];
    }
  //  printf("n = %d\n", n);
 //   for(i = 0; i < n-1; i++)printf("--%.8lf\n", vi[i]);
    for(i = 0; i < ta; i++) {
        t0 = x0 = v0 = s0 = 0;f = 0;
        for(j = 0; j < n-1; j++) {
            //v0t+0.5ait^2 + s0 =xj + vjt
            //ait^2+2(v0-vj)t-2(xj-s0)=0;
            //a0 = ai;
            a0 = ai[i];
            b0 = 2*(v0-vi[j]);
            c0 = -2*(xi[j] - s0);
           // printf("a0%.6lf b0%.6lf  c0%.6lf ---%.8lf\n", a0, b0, c0, b0*b0-4*a0*c0);
            tmp = (-b0+sqrt(b0*b0-4*a0*c0))/(2*a0);
         //   printf("j = %d tmp=%.8lf\n", j, tmp);
            if(tmp <= ti[j+1]-ti[j]) {//got
                t0 = ti[j+1];
                v0 = vi[j];
                s0 = xi[j+1];
                if(j == n - 2) {
                    printf("%.9lf\n", t0);
                        //if(i == ta-1)printf("\n");
                          // else printf(" ");
                           f = 1;break;
                }
            } else {
                if(j == n - 2)break;
                s0 = v0 * (ti[j+1]-ti[j]) + 0.5*ai[i] * (ti[j+1]-ti[j]) * (ti[j+1]-ti[j]) + s0;
                v0 = v0 + ai[i] * (ti[j+1]-ti[j]);
                t0 = ti[j+1];
               // printf("00000 s0=%.8lf t0=%.8lf\n", s0, t0);
            }

        }
         if(f == 1)continue;
        if(s0 < td) {
          //  printf("************v0 %.9lf s0%.9lf t0=%.9lf\n",v0, s0, t0);
            //v0t+0.5a[i]t^2=td-s0;
            //a[i]t^2+2v0t-2(td-s0)=0;
            a0 = ai[i];
            b0=2*v0;
            c0 = 2*(s0 - td);
          //  printf("dsfsdfd%.8lf %.8lf %.8lf %.8lf\n", a0, b0, c0, sqrt(b0*b0-4*a0*c0));
            tmp = (-b0+sqrt(b0*b0-4*a0*c0))/(2*a0);
            printf("%.9lf\n", tmp+t0);
           // if(i == ta-1)printf("\n");
           // else printf(" ");
        } else{
            printf("%.9lf\n", t0);
            //if(i == ta-1)printf("\n");
            //else printf(" ");
        }
    }
}

int p[N][N];
int cp[N];
void solve1()
int main()
{
    int d;

    int a;
    int i;
    int j, k;
    int c;
 freopen("in", "r", stdin); freopen("out", "w", stdout);
    scanf("%d", &c);
    for(i = 1; i <= c; i++) {
        scanf("%d", &n);
        sum = 0;
        for(j = 1; j <= n; j++){
         scanf("d", &p[j][0]);
         for(k = 1; k <= p[j][0])scanf("%d", &p[j][k]);
        }
        for(j = 1; j <= n; j++)cp[j] = 0;
        for(j = 0; j < ta; j++) scanf("%lf", &ai[j]);
        printf("Case #%d:\n", i);
        solve2();
    }
    return 0;
}
