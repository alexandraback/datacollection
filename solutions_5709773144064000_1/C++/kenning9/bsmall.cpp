#include<cstdio>
#include<iostream>
using namespace std;
int tc;
double c, f, x;
int main(){
    scanf("%d", &tc);
    for(int TC = 1; TC <= tc; ++TC){
        scanf("%lf %lf %lf", &c, &f, &x);
        if(c >= x){
            printf("Case #%d: %lf\n", TC, x/2);
        }
        else{
            double cookie = 0, productionRate = 2, time = 0;
            double breakeven = c/f;
            while(true){
                if(cookie > x) printf("HOLY SHIT\n");
                if(c > cookie){
                    time += (c - cookie)/productionRate;
                    cookie = c;
                }
                if(productionRate*breakeven + cookie < x){
                    productionRate += f;
                    cookie -= c;
                }
                else{
                    printf("Case #%d: %lf\n", TC, time + (x-cookie)/productionRate);
                    break;
                }
            }
        }
    }
    //system("pause");
}
