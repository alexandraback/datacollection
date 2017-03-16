#include <cstdio>
#include <cmath>

#define EPS 1e-9

double best[2010], rch[2010];
double X[2010], T[2010];

int main(){
    int t;
    scanf("%d" ,&t);
    for(int tt = 1; tt <= t; tt++){
        double d;
        int n, m;
        scanf("%lf %d %d" ,&d ,&n ,&m);
        for(int i = 1; i <= n; i++){
            scanf("%lf %lf" ,&T[i] ,&X[i]);
        }
        printf("Case #%d:\n" ,tt);
        while(m--){
            double a;
            scanf("%lf" ,&a);
            if(X[1] >= d){
                printf("%lf\n" ,sqrt(2*d / a));
                continue;
            }
            rch[1] = sqrt(2*X[1] / a) + EPS;
            best[1] = rch[1] * a;
            bool flag = true;
            for(int i = 2; flag; i++){
                double time = T[i] - rch[i - 1];
                double seg = T[i] - T[i - 1];
                double dis = X[i] - X[i - 1];
                double spd = dis / seg;
                double bes = best[i - 1];
                if(X[i] >= d){
                    flag = false;
                    double nt = (d - X[i - 1]) / spd + T[i - 1] + EPS;
                    T[i] = nt; X[i] = d;
                    time = nt - rch[i - 1];
                    seg = nt - T[i - 1];
                    dis = d - X[i - 1];
                }
                // a*t^2 + 2bt - 2d = 0
                // t = -2b + sqrt(4b^2+8ad) /2a
                double adt = (-2*bes + sqrt(4*bes*bes + 8*a*dis)) / (2*a) + EPS;
                if(rch[i - 1] + adt > T[i]){
                    rch[i] = rch[i - 1] + adt;
                    best[i] = bes + adt * a;
                }
                else{
                    rch[i] = T[i];
                    //(st + st + time*A) * time = 2 * dis
                    //st = (2dis - A*time^2) / 2time
                    //nv = st + time*A = (2dis + A*time^2) / 2time
                    if(a*time*time > 2*dis){
                        time = sqrt(2*dis/a) + EPS;
                    }
                    best[i] = (2*dis + a*time*time) / (2*time);
                }
                if(!flag){
                    printf("%.8lf\n" ,rch[i]);
                }
            }
        }
    }
}
