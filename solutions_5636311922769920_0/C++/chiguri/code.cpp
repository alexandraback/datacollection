#include<cstdio>

using namespace std;


// for qsort
/*
int compare(int *t, int *s) {
    return *t - *s;
}
*/

int K, C, S;


void solve() {
    int cur = 0;

    while(cur < K) {
        long long pos = 0;
        for(int t = 0; t < C; ++t) {
            if(cur < K) {
                pos = pos * K + cur;
                ++cur;
            }
            else {
                pos = pos * K + (K - 1);
            }
        }
        printf(" %lld", pos+1);
    }
}

void solve_and_print() {
    int i;

    scanf("%d %d %d",&K, &C, &S);
    if(S * C < K) printf(" IMPOSSIBLE\n");
    else {
        solve();
        printf("\n");
    }
}


int main() {
    int dataset_num, case_num;

    scanf("%d", &dataset_num);
    for(case_num = 1; case_num <= dataset_num; ++case_num) {
        printf("Case #%d:", case_num);

        solve_and_print();
    }

    return 0;
}
