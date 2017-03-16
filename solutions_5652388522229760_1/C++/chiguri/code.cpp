#include<cstdio>
using namespace std;


// for qsort
/*
int compare(int *t, int *s) {
    return *t - *s;
}
*/

long long N;

int check(int flag[10]) {
    for(int i = 0; i < 10; ++i) {
        if(flag[i] == 0) return 1;
    }
    return 0;
}

void update(char buf[24], int flag[10]) {
    int i = 0;
    while(buf[i]) {
        flag[buf[i]-'0'] = 1;
        ++i;
    }
    return;
}


int solve() {
    char buf[24];
    if(N == 0) return 0;

    int flag[10];
    for(int i = 0; i < 10; ++i) {
        flag[i] = 0;
    }

    int t = 0;
    while(check(flag)) {
        ++t;
        sprintf(buf, "%lld", N*t);
        update(buf, flag);
    }
    return t;
}

void solve_and_print() {
    int i;

    scanf("%lld", &N);
    int result = solve();
    if(result) {
        printf("%lld\n", N*result);
    }
    else {
        printf("INSOMNIA\n");
    }
}


int main() {
    int dataset_num, case_num;

    scanf("%d", &dataset_num);
    for(case_num = 1; case_num <= dataset_num; ++case_num) {
        printf("Case #%d: ", case_num);

        solve_and_print();
    }

    return 0;
}
