
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

//#define LOCAL

#ifndef LOCAL
#define OPEN(prefix)\
        {\
                char in[256], out[256];\
                snprintf(in, 256, "%s.in", prefix);\
                snprintf(out, 256, "%s.out", prefix);\
                freopen(in, "r", stdin);\
                freopen(out, "w", stdout);\
        }
#define CLOSE() \
        {\
                fclose(stdin);\
                fclose(stdout);\
        }
#else 
#define OPEN(prefix)
#define CLOSE()
#endif

typedef long long ULL;

ULL f(ULL r, ULL n)
{
    return 2 * n * (n - 1) + (2 * r + 1) * n;
}

int main()
{
    OPEN("A-small-attempt0");
    int T;
    cin>>T;
    for (int cas = 1; cas <= T; cas++){
        ULL r0, t;
        cin>>r0>>t;
        int l = 1, r = 1000000010;
        while (l + 1 < r){
            ULL mid = (l + r) / 2;
            if (f(r0, mid) <= t){
                l = mid;
            }
            else r = mid;
        }
        printf("Case #%d: %d\n", cas, l);
    }
    
    CLOSE();
    return 0;
}