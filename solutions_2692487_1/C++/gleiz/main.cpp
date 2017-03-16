#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
long long sz[128] = {0};

int main()
{
    int T = 0;
    long long A = 0, N = 0;
    int res = 0, add = 0;

    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++){
        cin >> A >> N;
        for (int i = 0; i<N; i++){
            cin >> sz[i];
        }

        sort(sz, sz + N);

        add = 0;
        res = N;
        for (int i = 0; i<N; i++){
            if (A == 1){
                add++;
            }else{
                while (A <= sz[i]){
                    add++;
                    A += (A-1);
                }
                A += sz[i];
            }
            int trail = add + (N - i - 1);
            if (trail < res)
                res = trail;
        }
        printf("Case #%d: %d\n", cas, res);
    }
    return 0;
}
