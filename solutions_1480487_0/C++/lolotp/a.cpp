#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 210
#define eps 1e-9

int T;
int N;
int s[MAX];
double X;

bool canEliminate(int idx, double point);
double binarySearch(int idx);

int main(){
    scanf("%d",&T);
    for (int tt = 1; tt <= T; tt++){
        scanf("%d",&N);
        X = 0;
        for (int i = 0; i < N; i++) scanf("%d", &s[i]), X += (double)s[i];
        //X/=100.0;
        
        printf("Case #%d:",tt);
        for (int i = 0; i < N; i++){
            printf(" %.8f",binarySearch(i));
        }printf("\n");
    }
    return 0;
}

double binarySearch(int idx){
    double l = 0.0, r = 100.0;
    for (int i = 0 ; i < 100; i++){
        double mid = (l+r)/2.0;
        if (canEliminate(idx, mid/100.0)){
            l = mid;
        }else{
            r = mid;
        }
    }
    return l;
}

//contestant idx has pct vote
bool canEliminate(int idx, double pct){
    //printf("%.6f\n",pct);
    double point = s[idx] + pct * (double)X;
    double sum = 0;
    for (int i = 0; i < N; i++) if (i != idx){
        double need = point - (double)s[i];        
        double pct = need/(double)X;
        if (need < 0) pct = 0;
        sum += pct;
    }
    if (sum + pct < 1-eps) return true;
    return false;
}
