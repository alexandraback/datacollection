#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int N, suprising, limit;

int main()
{
    int numberOfCases;
    scanf("%d",&numberOfCases);
    for(int testNo=1; testNo<=numberOfCases; testNo++) {
        scanf("%d %d %d",&N, &suprising, &limit);

        int res = 0;
        for(int i=0; i<N; i++) {
            int a;
            scanf("%d", &a);
            if (a / 3 >= limit) res++;
            else {
                a -= limit;
                if (a >= (limit-1) * 2 && (limit - 1) >= 0) res++;
                else if (suprising > 0 && a >=(limit - 2) * 2 && (limit - 2) >= 0) {
                    res++;
                    suprising--;
                }
            }
        }

        printf("Case #%d: %d\n", testNo, res);
    }
}
