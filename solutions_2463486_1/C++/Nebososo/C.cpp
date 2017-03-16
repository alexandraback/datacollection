#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define VERT 0
#define HOZ 1

using namespace std;

vector<long long> v;
int T, TS = 0;
long long A, B;

inline long long rev(long long a){
    long long r = 0ll;

    while(a){
        r *= 10ll;
        r += a % 10ll;
        a /= 10ll;
    }

    return r;
}

int main(){
    long long i, a, b, c;

    for(i = 1; i <= 10000000ll; i++){
        a = rev(i);
        if(i == a){
            b = i * i;
            c = rev(b);
            if(b == c)
                v.push_back(b);
        }
    }

    for(scanf("%d", &T); T--;){
        scanf("%lld %lld", &A, &B);
        printf("Case #%d: ", ++TS);
        printf("%lu\n", upper_bound(v.begin(), v.end(), B) - lower_bound(v.begin(), v.end(), A));
    }

    return 0;
}
