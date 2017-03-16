#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define REP_1(i, n) for (int i = 1; i <= (n); i++)
typedef long long LL;

//const int N = 11111111;
//char tmp[30];
//
//void convert(LL x) {
//    char *p = tmp;
//    while (x) {
//        *(p++) = (char) (x % 10) + '0';
//        x /= 10;
//    }
//    *p = 0;
//}
//
//bool palindrome(char *str) {
//    int i = 0, j = strlen(str) - 1;
//    while (i < j) {
//        if (str[i] != str[j]) return false;
//        i++, j--;
//    }
//    return true;
//}
//
//int main() {
//    freopen("out", "w", stdout);
//    REP_1(i, N) {
//        convert(i);
//        if (!palindrome(tmp)) continue;
//        convert((LL) i * i);
//        if (!palindrome(tmp)) continue;
//        cout << (LL) i * i << "ll," << endl;
//    }
//    return 0;
//}

const LL pre[47] = {
    1ll,
    4ll,
    9ll,
    121ll,
    484ll,
    10201ll,
    12321ll,
    14641ll,
    40804ll,
    44944ll,
    1002001ll,
    1234321ll,
    4008004ll,
    100020001ll,
    102030201ll,
    104060401ll,
    121242121ll,
    123454321ll,
    125686521ll,
    400080004ll,
    404090404ll,
    10000200001ll,
    10221412201ll,
    12102420121ll,
    12345654321ll,
    40000800004ll,
    1000002000001ll,
    1002003002001ll,
    1004006004001ll,
    1020304030201ll,
    1022325232201ll,
    1024348434201ll,
    1210024200121ll,
    1212225222121ll,
    1214428244121ll,
    1232346432321ll,
    1234567654321ll,
    4000008000004ll,
    4004009004004ll,
    100000020000001ll,
    100220141022001ll,
    102012040210201ll,
    102234363432201ll,
    121000242000121ll,
    121242363242121ll,
    123212464212321ll,
    123456787654321ll
};

int main() {
//    freopen("C-large-1.in", "r", stdin);
//    freopen("C-large-1.out", "w", stdout);
    int T;
    LL x, y;
    cin >> T;
    REP_1(cas, T) {
        cin >> x >> y;
        cout << "Case #" << cas << ": " << (upper_bound(pre, pre + 47, y) - lower_bound(pre, pre + 47, x)) << endl;
    }
    return 0;
}



