#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

bool check(const char * const *x, int N)
{
    int appeared[26] = {0};
    char prev = '\0';
    for(int i = 0; i < N; ++i)
    {
        for(const char* cur = x[i]; *cur != '\0'; ++cur)
        {
            if(*cur != prev && appeared[*cur-'a'])
                return false;
            ++appeared[*cur-'a'];
            prev = *cur;
        }
    }
    return true;
}

int main(void)
{
    int T;
    cin >> T;
    char *ary[128];
    for(int i = 1; i <= T; ++i)
    {
        printf("Case #%d: ", i);
        int N;
        cin >> N;
        string buf;
        for(int j = 0; j < N; ++j)
        {
            cin >> buf;
            ary[j] = strdup(buf.c_str());
        }
        std::sort(ary, ary+N);
        int ans = 0;
        do {
            if (check(ary, N))
                ++ans;
        } while(std::next_permutation(ary, ary+N));
        printf("%d\n", ans);

        for(int j = 0; j < N; ++j)
            free(ary[j]);
    }
    return 0;
}
