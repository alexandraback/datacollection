#include <cstdio>
#include<cstring>

#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define fr(a,b) for(int a = 0; a < b; a++)
#define frr(a,b,c) for(int a = b; a < c; a++)
#define pri(x) printf("%d\n", x)
#define prl(x) printf("%lld\n", x)
#define prs(x) printf(x)
#define vi vector<int>
#define vii vector< vi >
#define vb vector<bool>
#define mms(array) memset(array, 0, sizeof(array))
#define rfin freopen("in.txt", "r", stdin)
#define wtout freopen("out.txt", "w", stdout)
#define all(vec) vec.begin(), vec.end()
#define pm(i,b,e) i<<1, b, (b+e)/2
#define sm(i,b,e) i<<1+1, (b+e)/2, e

using namespace std;

bool cons[26] = {0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1};
int n, acc[1000005], len;
char str[1000005];

int main() {
    rfin;
    wtout;
    int t, casen = 0;
    long long total;
    sc(t);
    while (casen++ < t) {
        scanf("%s%d", str, &n);
        len = strlen(str);
        acc[0] = cons[str[0]-'a'];
        frr(x, 1, len) {
            if (cons[str[x]-'a']) acc[x] = acc[x-1]+1;
            else acc[x] = 0;
            //printf("%d ", acc[x]);
        }
        //prs("\n");
        total = 0;
        fr(x, len-n+1) {
            frr(y, x+n-1, len) if (acc[y] >= n) {
                total += len-y;
                y = len;
            }
        }
        printf("Case #%d: %lld\n", casen, total);
    }
    return 0;
}
