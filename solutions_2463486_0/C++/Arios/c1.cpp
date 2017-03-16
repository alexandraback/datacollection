#include <cstdio>
#include <cstring>

#define N 1000000
#define LL long long

//int an;
//LL a[N];
//
//inline bool palindrom(LL x) {
//    char s[20];
//    sprintf(s, "%lld", x);
//    int len = strlen(s);
//    for (int i = len / 2 - 1; i >= 0; --i)
//        if (s[i] != s[len - 1 - i])
//            return false;
//    return true;
//}
//
//void init() {
//    int top = 10000000;
//    an = 0;
//    for (int i = 1; i <= top; ++i)
//        if (palindrom(i) && palindrom((LL)i * i)) {
//            printf(",%lldLL", (LL)i * i);
//        }
//}

LL a[39] = {1LL,4LL,9LL,121LL,484LL,10201LL,12321LL,14641LL,40804LL,44944LL,1002001LL,1234321LL,4008004LL,100020001LL,102030201LL,104060401LL,121242121LL,123454321LL,125686521LL,400080004LL,404090404LL,10000200001LL,10221412201LL,12102420121LL,12345654321LL,40000800004LL,1000002000001LL,1002003002001LL,1004006004001LL,1020304030201LL,1022325232201LL,1024348434201LL,1210024200121LL,1212225222121LL,1214428244121LL,1232346432321LL,1234567654321LL,4000008000004LL,4004009004004LL};

int gao(LL x) {
    int i;
    for (i = 0; i < 39 && a[i] <= x; ++i);
    return i;
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int t, cas = 0;
    scanf("%d", &t);
    while (t--) {
        LL l, r;
        scanf("%lld %lld", &l, &r);
        printf("Case #%d: %d\n", ++cas, gao(r) - gao(l - 1));
    }
    return 0;
}
