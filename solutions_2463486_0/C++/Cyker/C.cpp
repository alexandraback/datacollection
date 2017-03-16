#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RANGE(i,b,e) for(int (i)=(b);(i)<(int)(e);(i)++)
#define CRANGE(i,b,e) for(int (i)=(b);(i)<=(int)(e);(i)++)
#define RRANGE(i,b,e) for(int (i)=(b);(i)>=(int)(e);(i)--)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define PI 3.1415926535897932384626433832795
#define INF 0x7FFFFFFF

int T;
long long A, B;

bool is_fair(long long I)
{
    long long II = I;
    long long K = 0;
    while (I != 0) {
        int r = I % 10;
        I /= 10;
        K = K * 10 + r;
    }
    return (II == K);
}

int main(int argc, char **argv)
{
    scanf("%d\n", &T);
    for (int t = 0;t < T;t++) {
        long long cnt = 0;
        scanf("%lld %lld\n", &A, &B);
        long long a = ceil(sqrt(A));
        long long b = floor(sqrt(B));

        for (long long i = a;i <= b;i++) {
            if (is_fair(i)) {
                long long I = i * i;
                if (is_fair(I)) {
                    cnt++;
                }
            }
        }

        printf("Case #%d: %lld\n", t + 1, cnt);
    }
    return 0;
}

