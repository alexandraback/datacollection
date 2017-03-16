
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

bool is_consonant(char c)
{
    return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}

long long solve(int N, const char* s)
{
    int len = strlen(s);
    if (len < N) return 0;
    long long ret = 0;
    int cons_count = 0;
    long long skip = 0;
    for (int end = 0; end < len; ++end) {
        int start = end - N + 1;
        cons_count += is_consonant(s[end]) ? 1 : 0;
        if (start > 0) {
            cons_count -= is_consonant(s[start-1]) ? 1 : 0;
        }
        if (cons_count == N) {
            ret += (long long)(start+1LL-skip)*(len-end);
            skip = start+1LL;
        }
    }
    return ret;
}

long long solve_ref(int N, const char* s)
{
    int len = strlen(s);
    long long ret = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i+N-1; j < len; ++j) {
            long long cons_count = 0;
            long long max_cons_count = INT_MIN;
            for (int k = i; k <= j; ++k) {
                if (is_consonant(s[k])) {
                    cons_count++;
                    max_cons_count = max(max_cons_count, cons_count);
                } else {
                    cons_count = 0;
                }
            }
            if (max_cons_count >= N) {
                ret += 1;
            }
        }
    }
    return ret;
}

char s[1100000];

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i) {

        scanf("%s", &s);
        int N;
        scanf("%d", &N);

        //assert(solve(N,s) == solve_ref(N,s));
        printf("Case #%d: %lld\n", i+1, solve(N, s));
    }
}

