#include <cstdio>
#include <algorithm>
#include <vector>

#define FO(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    FO(Z,0,T) {
        printf("Case #%d: ", Z+1);

        int n;
        scanf("%d", &n);
        vector<double> a(n), b(n);
        FO(i,0,n) scanf("%lf", &a[i]);
        FO(i,0,n) scanf("%lf", &b[i]);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<double > aa=a, bb=b;

        int dw = 0;
        int w = 0;
        FO(i,0,n) {
            FO(j,0,n) if (a[j] > b[i]) {
                dw++;
                a[j] = -1e9;
                break;
            }
        }
        a=aa; b=bb;

        reverse(a.begin(), a.end());
        FO(i,0,n) {
            sort(b.begin(), b.end());
            FO(j,0,b.size()) {
                if (b[j] > a[i]) {
                    swap(b[j], b.back());
                    b.pop_back();
                    goto bwon;
                }
            }
            swap(b[0], b.back());
            b.pop_back();
            w++;
bwon:;
        }

        printf("%d %d\n", dw, w);
    }

    return 0;
}

