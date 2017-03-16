#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int v[300];
int soma;
double p[300];
double r[300];
int n;
bool func (int k, double per) {
    double ponto = (double)v[k]+per*soma;
    double ver =  0;
    for (int c = 1; c <= n; c++) {
        if (c == k) continue;
        r[c] = (soma*per+double(v[k]-v[c]))/soma;
        ver += max(double(0),r[c]);
    }
    if (ver+per > 1) return false;
    return true;
}
int main () {
    int t;
    scanf("%d", &t);
    for (int lo = 1; lo <= t; lo++) {
        scanf("%d", &n);
        printf("Case #%d:", lo);
        soma = 0;
        int caso = -1;
        for (int c = 1; c <= n; c++) {
            scanf("%d", &v[c]);
            soma += v[c];
        }
        for (int c = 1; c <= n; c++) {
            p[c] = double(v[c])/soma;
        }
        for (int c = 1; c <= n; c++) {
            double ini = 0;
            double fim = 1;
            double meio;
            for (int k = 1; k <= 160; k++) {
                meio = (ini+fim)/2;
                if (!func(c,meio)) {
                    fim = meio;
                }
                else ini = meio;
            }
            printf(" %.5lf", ini*100);
        }
        printf("\n");
    }
    return 0;
}
