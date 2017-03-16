#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

bool fless(double a,double b){ return b-a>1e-6; }
bool fequal(double a,double b){ return fabs(b-a)<=1e-6; }


int main(){
    int tt; scanf("%d",&tt);
    for (int ti=1;ti<=tt;ti++){
        int x, y;
        scanf("%d%d", &x, &y);


        printf("Case #%d: ",ti);
        if (x < 0){
            for (int i=x;i<0;i++){
                printf("EW");
            }   
        } else if (x > 0){
            for (int i=0;i<x;i++){
                printf("WE");
            }   
        }
        if (y < 0){
            for (int i=y;i<0;i++){
                printf("NS");
            }   
        } else if (y > 0){
            for (int i=0;i<y;i++){
                printf("SN");
            }   
        }
        puts("");
    }
    return 0;
}

