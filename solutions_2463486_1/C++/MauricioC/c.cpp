#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

bool ispal(long long n) {
    int c[20]; int i;
    for(i = 0; n; n /= 10, i++)
        c[i] = n % 10;

    for(int j = 0; j < i; j++)
        if(c[j] != c[i-1-j])
            return false;

    return true;
}

int main() {
    vector<long long> v;
    for(int i = 1; i < 10000000; i++)
        if(ispal(i))
            v.push_back(i);

    vector<long long> ans;
    for(unsigned int i = 0; i < v.size(); i++)
        if(ispal(v[i]*v[i])) {
            ans.push_back(v[i]*v[i]);
            printf("%lld\n", ans.back());
        }

    int t;
    scanf("%d", &t);

    for(int z = 1; z <= t; z++) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        printf("Case #%d: %ld\n", z,
               upper_bound(ans.begin(), ans.end(), b) -
               lower_bound(ans.begin(), ans.end(), a));
    }
}
