#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<queue>

using namespace std;
#define For(i,l,r) for(int i=l;i<=r;++i)
#define Cor(i,l,r) for(int i=l;i>=r;--i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define MaxN 1550
#define MaxM 12030
#define MD 20120427
#define PII pair<int,int>
#define FI first
#define SE second
#define MP make_pair
#define INF (0x3f3f3f3f)
#define update(a,b) a = (a + b) % MD

const int px[4] = {0,1,0,-1};
const int py[4] = {1,0,-1,0};

int H,n,m,Tot;
double Min[12000],Max[12000];
void init(){
     scanf("%d%d%d",&H,&n,&m);
     Tot = 0; For(i,1,n) For(j,1,m) scanf("%lf",&Max[++Tot]);
     Tot = 0; For(i,1,n) For(j,1,m) scanf("%lf",&Min[++Tot]);
}

int num(PII a) { return (a.FI - 1) * m + a.SE; }
bool check(PII a) { return a.FI > 0 && a.FI <=n && a.SE >0 && a.SE <=m; }
PII zb(int a){ return MP((a - 1) / m + 1,(a - 1) % m + 1); }

bool vis[12000],Cal[12000];
PII q[12000];
void pred(){
     Fill(vis,0); vis[1] = 1;
     int hd(0) ,tl (1); q[1] = MP(1,1);
     while(hd < tl) {
         PII vex = q[++hd]; int nv = num(vex);
         For(i,0,3) {
             PII np = MP(vex.FI + px[i],vex.SE + py[i]); int nu = num(np);
             if (!vis[nu] && (min(Max[nv],Max[nu]) - 50 >= max((double)H,max(Min[nu],Min[nv])))) {
                 q[++tl] = np; vis[nu] = true;
             }
         }
     }
}

double d[12000];
struct node{
       PII FI;double SE;
};
node MP1(PII a,double b) { node ret;ret.FI = a;ret.SE = b;return ret;}
bool operator <(node a,node b){return a.SE > b.SE; }
priority_queue<node,vector<node> > PQ;
double Calc(){
       Fill(Cal,0);
       if (vis[n * m]) return 0; while (!PQ.empty()) PQ.pop();
       For(i,1,n * m) if (vis[i]) PQ.push(MP1(zb(i),0));
       while (!PQ.empty()) {
           node v = PQ.top(); PQ.pop();
           if (Cal[num(v.FI)]) continue; d[num(v.FI)] = v.SE; Cal[num(v.FI)] = true; if(num(v.FI) == n * m) break;
           PII cor = v.FI; int nv = num(v.FI);
           For(i,0,3) {
               PII np = MP(cor.FI + px[i],cor.SE + py[i]); int nu = num(np);
               if(!check(np)) continue;
               double cst = 0;
               if (min(Max[nv],Max[nu]) - 50 < max(H - v.SE * 10,max(Min[nu],Min[nv]))) {
                   if (min(Max[nv],Max[nu]) - 50 < max(Min[nu],Min[nv])) continue;
                   cst = max(H - v.SE * 10,max(Min[nu],Min[nv])) - (min(Max[nv],Max[nu]) - 50);
               }
               cst /= 10; //cst += nt;
               if (H - (v.SE + cst) * 10 - 20 >= Min[nv]) cst += 1; else cst += 10;
               PQ.push(MP1(np,v.SE + cst));
           }
       }
       if (Cal[n * m])return d[n * m]; else return -1;
}

int t;
int main() { freopen("B-small-attempt2.in","r",stdin); freopen("b.out","w",stdout);
    cin >> t;
    For(i,1,t) {
        printf("Case #%d: ",i);

        init();
        pred();
        double ans = Calc();
        printf("%.9lf\n",ans);
    }  
    return 0;
}
