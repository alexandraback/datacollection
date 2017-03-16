#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

long long X[] = {0LL,1LL,4LL,9LL,121LL,484LL,10201LL,12321LL,14641LL,40804LL,44944LL,1002001LL,1234321LL,4008004LL,100020001LL,102030201LL,104060401LL,121242121LL,123454321LL,125686521LL,400080004LL,404090404LL,10000200001LL,10221412201LL,12102420121LL,12345654321LL,40000800004LL,1000002000001LL,1002003002001LL,1004006004001LL,1020304030201LL,1022325232201LL,1024348434201LL,1210024200121LL,1212225222121LL,1214428244121LL,1232346432321LL,1234567654321LL,4000008000004LL,4004009004004LL,};
const size_t N = (sizeof X)/(sizeof X[0]);

int cnt(long long hi) {
    return upper_bound(X, X+N, hi) - X;
}
int main() {
    cin.sync_with_stdio(false);
    int ntests;
    scanf("%d", &ntests);
    for (int testcase=1; testcase<=ntests; ++testcase) {
        long long A, B;
        scanf("%I64d %I64d", &A, &B);
        printf("Case #%d: %d\n", testcase, cnt(B) - cnt(A-1));
    }
	return 0;
}
