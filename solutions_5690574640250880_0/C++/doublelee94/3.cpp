#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include <stdio.h>
using namespace std;
#define N 2000005
#define INF 1000000009
typedef long long LL;
int n;
int r, c, m;
int a[105][105];
int main(){
    int t;
    freopen("C-small-attempt3.in","r",stdin);
    freopen("opD.out","w",stdout);
    scanf("%d", &t);
    int num = 1;
    while(t--){
        scanf("%d%d%d", &r, &c, &m);
        m = r * c - m;
        int f = 0;
        memset(a, '*', sizeof(a));
        if(r >= 3 && c >= 3){
            if(m >= 8){
                a[1][0] = '.';
                a[0][1] = '.';
                a[1][1] = '.';
                a[0][2] = '.';
                a[1][2] = '.';
                a[2][0] = '.';
                a[2][1] = '.';
                int ns = 8;
                if(m <= r * 2){
                    if(m & 1){a[2][2] = '.'; ns ++;}
                    if(ns < m)
                    for(int i = 3; i < r; i++){
                        a[i][0] = '.';
                        a[i][1] = '.';
                        ns += 2;
                        if(ns == m)break;
                    }
                }
                else if(m <= r * 2 + c * 2 - 4){
                    if(m & 1){a[2][2] = '.'; ns ++;}
                    if(ns < m)
                    for(int i = 3; i < r; i++){
                        a[i][0] = '.';
                        a[i][1] = '.';
                        ns += 2;
                        if(ns == m)break;
                    }
                    if(ns < m)
                    for(int i = 3; i < c; i++){
                        a[0][i] = '.';
                        a[1][i] = '.';
                        ns += 2;
                        if(ns == m)break;
                    }
                }
                else {
                    if(ns < m)
                    for(int i = 3; i < r; i++){
                        a[i][0] = '.';
                        a[i][1] = '.';
                        ns += 2;
                        if(ns == m)break;
                    }
                    if(ns < m)
                    for(int i = 3; i < c; i++){
                        a[0][i] = '.';
                        a[1][i] = '.';
                        ns += 2;
                        if(ns == m)break;
                    }
                    if(ns < m)
                    for(int i = 2; i < r; i++){
                        for(int j = 2; j < c; j++){
                            a[i][j] = '.';
                            ns ++;
                            if(ns == m)break;
                        }
                        if(ns == m)break;
                    }
                }
            }
            else {
                if(m == 1);
                else if(m == 4){
                    a[1][0] = '.';
                    a[0][1] = '.';
                    a[1][1] = '.';
                }
                else if(m == 6){
                    a[1][0] = '.';
                    a[0][1] = '.';
                    a[1][1] = '.';
                    a[0][2] = '.';
                    a[1][2] = '.';
                }
                else f = -1;
            }
        }
        else {
            if(m == 1);
            else {
                if(r == 1){
                    for(int i = 0; i < m; i++)
                        a[0][i] = '.';
                }
                else if(c == 1){
                    for(int i = 0; i < m; i++)
                        a[i][0] = '.';
                }
                else if(m & 1 || m == 2)f = -1;
                int ns = 0;
                if(r == 2){
                    if(ns < m)
                    for(int i = 0; i < c; i++){
                        a[0][i] = '.';
                        a[1][i] = '.';
                        ns += 2;
                        if(ns == m)break;
                    }
                }
                if(c == 2){
                    if(ns < m)
                    for(int i = 0; i < r; i++){
                        a[i][0] = '.';
                        a[i][1] = '.';
                        ns += 2;
                        if(ns == m)break;
                    }
                }
            }

        }
        a[0][0] = 'c';
        printf("Case #%d:\n", num++);
        if(f == -1)printf("Impossible\n");
        else {
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    printf("%c", a[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
