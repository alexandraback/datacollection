#include <cstdio>
#include <algorithm>

#define fr(a,b,c) for(int a = b; a < c; a++)
#define vi vector<int>
#define vvi vector< vi >
#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define rfin freopen("in.txt", "r", stdin)
#define wtout freopen("out.txt", "w", stdout)

using namespace std;

int motes[100000], n;

int solve(int a, int x) {
            while(x < n) {
                //printf("%d %d\n", a, motes[x]);
                if (a > motes[x]) a += motes[x];
                else {
                    int dif = 0;
                    while (a <= motes[x]) {
                        a += a-1;
                        dif++;
                    }
                    int op1 = n-x, op2 = dif + solve(a, x);
                    //printf("%d %d %d\n", x, op1, op2);
                    return min(op1, op2);
                }
                x++;
            }
            return 0;
}

int main() {
    rfin;
    wtout;
    int t, casen = 0, a, ans;
    sc(t);
    while (++casen <= t) {
        sc2(a, n);
        fr(x, 0, n) sc(motes[x]);
        ans = 0;
        sort(motes, motes+n);
        //printf("\n");
        if (a == 1) {
            ans = n;
        } else ans = solve(a, 0);
        printf("Case #%d: %d\n", casen, ans);
    }
    return 0;
}
