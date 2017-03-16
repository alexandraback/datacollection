#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


int main() {
    int t;
    int j, p, s, k;
    int ca = 1;
    int jp[200], js[200], ps[200];
    int i, ii, iii;
    scanf("%d", &t);
    while (ca <= t) {
        cin >> j >> p >> s >> k;
        cout<<"Case #"<<ca<<": ";
        for(i=0;i<200;i++) {
            jp[i] = js[i] = ps[i] = 0;
        }
        int ret = 0;
        string seq = "";
        for (i=1; i<=j; i++) {
            for (ii=1; ii<=p; ii++) {
                for (iii=1; iii<=s; iii++) {
                    if (jp[i*(p+1)+ii]>=k || js[i*(s+1)+iii]>=k || ps[ii*(s+1)+iii]>=k)
                        continue;
                    jp[i*(p+1)+ii]++;
                    js[i*(s+1)+iii]++;
                    ps[ii*(s+1)+iii]++;
                    seq += char(i+'0');
                    seq += " ";
                    seq += char(ii+'0');
                    seq += " ";
                    seq += char(iii+'0');
                    seq += "\n";
                    ret++;
                }
            }
        }
        cout<<ret<<endl;
        if (ret != 0) {
            cout<<seq;
        }
        ca++;
    }
    return 0;
}

