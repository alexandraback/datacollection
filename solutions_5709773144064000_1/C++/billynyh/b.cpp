#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

bool fless(double a,double b){ return b-a>1e-8; }
bool fequal(double a,double b){ return fabs(b-a)<=1e-8; }

int main(){
    int tt; scanf("%d",&tt);
    for (int ti=1;ti<=tt;ti++){
        double c, f, x;
        scanf("%lf%lf%lf", &c, &f, &x);
        
        double speed = 2;

        double t0 = x / speed;
        double t_farm = 0;
        int step = 1;
        while (true) {
            t_farm += c / speed;
            speed += f;
            double t1 = t_farm + x / speed;
            //printf("%d: %lf\n", step, t1);
            if (fless(t1, t0)) {
                t0 = t1;
            } else {
                break;
            }
            step++;
        }

        printf("Case #%d: %.7lf\n",ti,t0);
    }
    return 0;
}

