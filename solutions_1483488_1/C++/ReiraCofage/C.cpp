#include <cstdio>
#include <cstring>

using namespace std;

int T, A, B, C=1;
int dezna[12];

int digs(int n) {
    return (n==0 ? 0 : 1 + digs(n/10) );
}

int main() {

    dezna[0] = 1;
    for (int i=1;i<12;i++)
        dezna[i] = 10*dezna[i-1];

    for(scanf("%d",&T);T--;) {
        scanf("%d %d",&A,&B);
        int tot = 0;
        for (int n=A;n<=B;n++) {
            int d = digs(n);
            int m = (n/10) + (n%10)*dezna[d-1];
            while (m != n) {
                if (A <= n and n < m and m <= B) tot++;
                m = (m/10) + (m%10)*dezna[d-1];
            }
        }
        printf("Case #%d: %d\n",C++,tot);
    }

    return 0;
}
