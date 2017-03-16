#include <cstdio>

int T;
long long a, b;
long long allP[50];

void precomp() {
    allP[0] = 1ll;
    allP[1] = 4ll;
    allP[2] = 9ll;
    allP[3] = 121ll;
    allP[4] = 484ll;
    allP[5] = 10201ll;
    allP[6] = 12321ll;
    allP[7] = 14641ll;
    allP[8] = 40804ll;
    allP[9] = 44944ll;
    allP[10] = 1002001ll;
    allP[11] = 1234321ll;
    allP[12] = 4008004ll;
    allP[13] = 100020001ll;
    allP[14] = 102030201ll;
    allP[15] = 104060401ll;
    allP[16] = 121242121ll;
    allP[17] = 123454321ll;
    allP[18] = 125686521ll;
    allP[19] = 400080004ll;
    allP[20] = 404090404ll;
    allP[21] = 10000200001ll;
    allP[22] = 10221412201ll;
    allP[23] = 12102420121ll;
    allP[24] = 12345654321ll;
    allP[25] = 40000800004ll;
    allP[26] = 1000002000001ll;
    allP[27] = 1002003002001ll;
    allP[28] = 1004006004001ll;
    allP[29] = 1020304030201ll;
    allP[30] = 1022325232201ll;
    allP[31] = 1024348434201ll;
    allP[32] = 1210024200121ll;
    allP[33] = 1212225222121ll;
    allP[34] = 1214428244121ll;
    allP[35] = 1232346432321ll;
    allP[36] = 1234567654321ll;
    allP[37] = 4000008000004ll;
    allP[38] = 4004009004004ll;
}

int bS (int c) {
    if (c > allP[38]) return 39;
    int lo = 0;
    int hi = 38;
    int mid;
    int bSoFar = 0;
    while (lo <= hi) {
        mid = (lo+hi)/2;
        if (c <= allP[mid]) {
            bSoFar = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return bSoFar;
}


int main() {
    freopen ("q3.in", "r", stdin);
    freopen ("q3.out", "w", stdout);
    scanf ("%d", &T);
    precomp();
    for (int tc = 1; tc <= T; tc++) {
        printf ("Case #%d: ", tc);
        scanf ("%lld %lld", &a, &b);
        b++;
        printf ("%d\n", bS(b)-bS(a));
    }
    return 0;
}
        
        
