#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

int T;
int A, N, motes[1000000 + 1];

int main()
{
//    freopen("A.in", "r", stdin);
    
    scanf("%d", &T);
    
    for (int test = 0; test < T; test++){
        scanf("%d %d", &A, &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &motes[i]);
        }
        
//        printf("-> %d %d\n", A, N);
        
        int ans = N;
        
        sort(motes, motes + N);
        
        if (A > 1){
            long long sum = A;
            int extra = 0;
            
            for (int i = 0; i < N; ) {
                if (sum > motes[i]) {
                    sum += motes[i];
                    ans = min(ans, extra + N - i - 1);
                    i++;
                } else {
                    extra++;
                    sum += sum - 1;
                }
            }
        }
        printf("Case #%d: %d\n", test + 1, ans);
    }
    
    return 0;
}
