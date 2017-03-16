#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    FILE *fin, *fout;    
    fin = fopen("D:\\TopCoder\\gcj2012\\R1B\\A-large.in", "r");
    fout = fopen("D:\\TopCoder\\gcj2012\\R1B\\A.out", "w");
    int T;
    fscanf(fin, "%d\n", &T);
    for (int ca = 1; ca <= T; ca++) {
        int N;
        fscanf(fin, "%d", &N);
        int s[N], X = 0, p[N];
        double m[N];
        for (int i = 0; i < N; i++) {
            fscanf(fin, "%d", &s[i]);
            X += s[i];
            p[i] = s[i];
            m[i] = 0;
        }
        
        sort(p, p+N);
        int XX = X, ix = 0;
        double last = p[N-1];
        for (int i = 0; i < N; i++) {
            ix = i;
            if (i) XX -= (p[i]-p[i-1]) * i;
            if (XX <= 0) {
                XX += i * (p[i] - p[i-1]);
                last = p[i-1] + XX * 1.0 / i;
                XX = -1;
                break;
            }
        }
        
        if (XX >= 0) {
            last = p[N-1] + XX*1.0 / N;
        }
        
        //cout << ca <<  "===" << last << endl;///
        
        for (int i = 0; i < N; i++) {
            if (s[i] < last) {
                m[i] = (last-s[i])*1.0 / X;
                //cout << s[i] << " " << m[i] << endl;//
            } else {
                m[i] = 0;
            }
        }

        fprintf(fout, "Case #%d:", ca);
        for (int i = 0; i < N; i++) {
            fprintf(fout, " %.6lf", m[i]*100);
        }
        fprintf(fout, "\n");
    }
    
    fclose(fin);
    fclose(fout);
    return 0;
}

