#include<stdio.h>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;

#define sz size()
#define pb push_back
#define len length()
#define clr clear()

#define eps 0.0000001
#define PI  3.14159265359

int br[555];
double v[555],d[555],zavrsi[555];
char s[555],kb[555];

int main() {

    FILE *ff=fopen("B-small-attempt0.in", "r"), *gg=fopen("B-small-attempt0.out", "w");

    int n,m,w,i,j,l,tt,ttt,dodaje,najvise;
    double res;

    fscanf(ff,"%d", &ttt);
    for(tt=1;tt<=ttt;tt++) {
        fprintf(gg,"Case #%d: ", tt);

        fscanf(ff,"%d%d%d", &m, &n, &w);
        fscanf(ff,"%s%s", &kb, &s);

        for(i='A'; i<='Z'; i++) br[i] = 0;
        for(i=0; i<m; i++) {
            br[kb[i]]++;
        }

        dodaje = n;
        for(i=1; i<n; i++) {
            bool bb = true;
            for(j=i; j<n; j++) {
                if (s[j-i] == s[j]) {
                    bb = false;
                    break;
                }
            }
            if (bb) {
                dodaje = i;
                break;
            }
        }

        najvise = 1 + (w-n)/dodaje;

        for(i=1; i<=w; i++) {
            v[i] = 0;
            zavrsi[i] = 0;
        }

        v[0] = 1;
        for(i=1; i<=w; i++) {

            char ch;

            if (i <= n) ch = s[i-1];
            else {
                int t = (i-n-1)%dodaje;
                ch = s[t];
            }

            v[i] = v[i-1] * (double)br[ch]/(double)m;

            if (v[i] < eps) break; // eps mnogo malo da bude

            zavrsi[i] = v[i-1] * (double)(m-br[ch])/(double)m;
        }

        d[0] = 0;
        for(i=1; i<=w; i++) {

            int pon;

            if (i<n) pon = 0;
            else {
                pon = 1 + (i-n)/dodaje;
            }
            d[i] = v[i] * pon;

            for(l=n; l<=i; l++) {
                pon = 1 + (l-n)/dodaje;
                d[i] = d[i] + zavrsi[l] * pon + d[i-l];
            }
        }

        res = najvise - d[w];

        fprintf(gg, "%lf\n", res);
    }

    fclose(ff); fclose(gg);

    return 0;
}
