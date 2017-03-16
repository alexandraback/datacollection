#include <vector>
#include <algorithm>
using namespace std;

int d[1010][1010];
int n;

int main() {
    int t;

    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    fscanf(in, "%d", &t);
    for (int l=1; l<=t; l++) {
        fscanf(in, "%d", &n);
        vector<double> d1, d2;
        d1.resize(n);
        d2.resize(n);
        for (int i=0; i<n; i++) {
            fscanf(in, "%lf", &d1[i]);
        }
        for (int i=0; i<n; i++) {
            fscanf(in, "%lf", &d2[i]);
        }
        sort(d1.begin(), d1.end());
        sort(d2.begin(), d2.end());

        int res1, res2;
        res1 = res2 = 0;

        int pt = n-1;
        for (int i=n-1; i>=0; i--) {
            while(pt>=0) {
                if (d1[i] > d2[pt]) {
                    res1++;
                    pt--;
                    break;
                }
                pt--;
            }
        }

        pt = 0;
        for (int i=0; i<n; i++) {
            int did = 0;
            while(pt<n) {
                if (d1[i] < d2[pt]) {
                    did = 1;
                    pt++;
                    break;
                }
                pt++;
            }
            if (did==0)
                res2++;
        }

        fill(d[0], d[0]+1010*1010, 0);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                d[i+1][j+1] = max(d[i][j+1], d[i+1][j]);
                if (d1[i] < d2[j]) {
                    d[i+1][j+1] = d[i][j] + 1;
                }
            }
        }

        fprintf(out, "Case #%d: %d %d\n", l, res1, res2);
    }
    return 0;
}
