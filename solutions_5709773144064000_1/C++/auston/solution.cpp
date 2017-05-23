#include<cstdio>
using namespace std;

double c, f, x, cps, time;

int main(){

    int t, ca=1;
    scanf("%d", &t);

    for(; t>0; t--){
        printf("Case #%d: ", ca++);
        scanf("%lf%lf%lf", &c, &f, &x);
        cps = 2;
        time = 0;
        while(true){
            if(x/cps<c/cps+x/(cps+f)){
                time += x/cps;
                break;
            }else{
                time += c/cps;
                cps += f;
            }
        }
        printf("%.7f\n", time);
    }

    return 0;
}

