#include <stdio.h>
#include <vector>
#include <assert.h>

using namespace std;


long long int lld_pow(int n, int r) {
    long long ret = 1;
    while(r--) {
        ret *= n;
    }
    return ret;
}

int main(void) {
    freopen("output.txt", "w", stdout);
    const int N= 16; const int J= 50;
    printf("Case #%d:\n", 1);

    vector<int> candidates;
    for (int i=1; i<=N/2 - 1; i++) {
        candidates.push_back( (1 << i) + (1 << ( (N-1) - i)));
    }

    int cnt_j = 0;
    for (int i=0; i< ( 1 << (N/2 -1)) && cnt_j < J; i++, cnt_j++) {
        int sum_now = 0;
        for (int j=0; j< (N/2-1); j++) {
            sum_now += bool(i & (1 << j)) * candidates[j];
        }

        sum_now += (1 << (N-1)) + 1;
        //print string
        for (int j=N-1; j>=0; j--) {
            if (sum_now & (1 << j)) {
                printf("1");
            }
            else {
                printf("0");
            }
        }
        //print divider
        printf(" ");

        for (int base =2 ;base <=10; base ++ ) {
            //assert
            long long int sum = 0;
            for (int j=N-1; j>=0; j--) {
                sum += bool( sum_now & (1 << j)) * lld_pow(base, j);
            }
            //assert( sum % (base+1) == 0);

            printf("%d ", base+1);
        }
        printf("\n");

    }
    return 0;
}
