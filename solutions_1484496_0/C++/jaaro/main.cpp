#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int A[520], k, N;
long long sums[520];

void run_forrest_run()
{
    while(true) {
        random_shuffle(A, A+N);

        sums[0] = 0;
        k = 0;
        for(int i=0; i<N; i++) {
            sums[i+1] = sums[i] + A[i];
            while(sums[k] * 2 < sums[i+1]) k++;
            if (sums[k] * 2 == sums[i+1]) {
                for(int x = 0; x < k; x++) printf("%d ",A[x]); puts("");
                for(int x = k; x <= i; x++) printf("%d ",A[x]); puts("");
                return ;
            }
        }
    }
}

int main()
{
    int numberOfCases;
    scanf("%d",&numberOfCases);
    for(int testNo=1; testNo<=numberOfCases; testNo++) {
        scanf("%d",&N);

        for(int i=0; i<N; i++) scanf("%d",&A[i]);

        printf("Case #%d:\n",testNo);
        run_forrest_run();
    }
}

