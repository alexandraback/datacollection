#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

double ac[100];

int main(){
    freopen("2.out", "w", stdout);
    int t;
    cin >> t;
    for(int testCases = 1; testCases <= t; testCases++){
        double x0, x1, t1, t0;
        double d;
        int n, a;
        cin >> d >> n >> a;

        if(n == 2){
        cin >> t0 >> x0;
        cin >> t1 >> x1;
        for(int i = 0; i < a; i++)
            cin >> ac[i];

        printf("Case #%d:\n", testCases); 
        
        for(int i = 0; i < a; i++){
            double tmost = sqrt(d*2.0/ac[i]);
            
            double vcar = (x1 - x0) / (t1 - t0);
            double aa = 0.5*ac[i];
            double ab = -1.0 * vcar;
            double c = -1.0 * x0;

            double t2 = (-ab + sqrt(ab*ab - 4*aa*c)) / (2.0*aa);
            if(t2 >= tmost){
                printf("%.8lf\n", tmost);
                continue;
            }
            double snow = t2*vcar + x0;
            if(snow < d){
                t2 += (d-snow)/vcar;
                printf("%.8lf\n", t2);
            }
        }
        }
        else{
            cin >> t0 >> x0;
            for(int i = 0; i < a; i++)
                cin >> ac[i];
            printf("Case #%d:\n", testCases); 
            for(int i = 0; i < a; i++){
                double tmost = sqrt(d*2.0/ac[i]);
                printf("%.8lf\n", tmost);
            }
        }

    }
    return 0;
}
