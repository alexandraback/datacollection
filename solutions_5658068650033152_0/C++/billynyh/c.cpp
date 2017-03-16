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

int DEBUG = 0;

int cal_cap(int w, int h) {
    if (w < h) {
        int t = w;
        w = h;
        h = t;
    }

    int sum = 0;
    int x = w - h + 1;
    for (int i=0;i<(h+1)/2;i++) {
        sum += x;
        x += 2;
    } 
    x = w-h+1;
    for (int i=0;i<h/2;i++){
        sum += x;
        x += 2;
    }

    return sum;
}

int cal_use(int w, int h) {
    if (w < h) {
        int t = w;
        w = h;
        h = t;
    }
    int sum = (w-2)*2 + (2-h%2)*2;

    return sum;
}

int cal_rect_use(int w, int h) {
    int sum = w * 2 + (h-2)*2;
    return sum;
}

int main(){
    int tt; scanf("%d",&tt);

    /*
    for (int i=3;i<8;i++) {
        for (int j=3;j<8;j++) {
            printf("%d %d: %d %d: %d\n", i, j, cal_cap(i,j), cal_use(i,j), cal_rect_use(i,j));
        }
    }
    */

    for (int ti=1;ti<=tt;ti++){
        int N,M,K;
        scanf("%d%d%d", &N, &M, &K);

        int ans = K;
        if (K > 4) {
            for (int i=3;i<=N;i++) {
                for (int j=3;j<=M;j++) {
                    int rect_use = cal_rect_use(i,j);
                    if (i*j >= K) {
                        if (ans > rect_use) {
                            ans = rect_use;
                            if(DEBUG) printf("rect %d %d\n", i,j);
                        }
                    } else {
                        int t = rect_use + K - i*j;
                        if (ans > t) {
                            if (DEBUG) printf("rect %d %d + %d\n", i,j, K - i*j);
                            ans = t;

                        }
                    }

                    int cap = cal_cap(i, j);
                    int use = cal_use(i, j);
                    if (cap >= K){
                        if (ans > use) {
                            ans = use;
                            if (DEBUG) printf("dia %d %d\n", i, j);
                        }
                    } else {
                        int t = use + K - cap;
                        if (ans > t) {
                            ans = t;
                            if (DEBUG) printf("dia %d %d + %d\n", i, j, K - cap);
                        }
                    }
                    //printf("%d %d: %d %d\n", i, j, cap, use);
                    
                }
            }
        }

        printf("Case #%d: %d\n",ti,ans);
    }
    return 0;
}
