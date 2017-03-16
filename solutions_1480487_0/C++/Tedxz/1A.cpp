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

bool cho[500];
double s[500],sum;
int n;

bool check(double rem,double cur) {
     For(i,1,n) if (!cho[i]) {
         if (s[i] >= cur) continue;
         if (rem <=1e-11) return false;
         double tak = ((cur - s[i]) / sum);
         rem -= tak;
     }
     return rem >= -1e-11;
}

int t;
int main() { 
    freopen("A-small-attempt0.in","r",stdin);
    freopen("a.out","w",stdout);
    cin >> t;
    For(i,1,t){
               printf("Case #%d: ",i);
    scanf("%d",&n);sum = 0;
    For(i,1,n) {
        scanf("%lf",&s[i]);
        sum += s[i];
    }
    For(i,1,n) {
        double l = 0, r = 1;cho[i] = true;
        while (r - l >=1e-11) {
            double mid = (l + r) / 2;
            double Cur = s[i] + sum * mid;
            if (check(1 - mid,Cur)) l = mid; else r = mid;
        }
        printf("%.8lf%s",l * 100,(i==n)?("\n"):(" ")); cho[i] = false;
    }
    }
    return 0;
}
