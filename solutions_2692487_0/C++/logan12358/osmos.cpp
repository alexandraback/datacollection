#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long _t; scanf("%lld", &_t);
    for(long long _i=1; _i<=_t; _i++) {
        printf("Case #%d: ", _i);
        long long a, n; scanf("%lld %lld", &a, &n);
        vector<long long> motes;
        for(long long i=0; i<n; i++) {
            long long x; scanf("%lld", &x);
            motes.push_back(x);
        }
        sort(motes.begin(), motes.end());
        long long best=1000000;
        long long count=0;
        for(long long i=0; i<motes.size(); i++) {
            while(motes[i]>=a) {
                if(count + motes.size() - i < best) {
                    best = count + motes.size() - i;
                }
                count++;
                if(a==1) {
                    count = best;
                    i = motes.size();
                    break;
                }
                a+=a-1;
            }
            a += motes[i];
        }
        if(count < best) {
            best = count;
        }
        printf("%lld\n", best);
    }
}
