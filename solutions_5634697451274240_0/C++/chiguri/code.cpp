#include<cstdio>
using namespace std;


char buf[104];

int solve() {
    int i = 0;
    while(buf[i]) {
        if(buf[i] == '+') buf[i] = 0;
        else buf[i] = 1;
        ++i;
    }
    int t = 0;

    while(--i >= 0) {
        if((buf[i]+t)%2) {
            ++t;
        }
    }
    return t;
}

void solve_and_print() {
    int i;

    gets(buf);
    printf("%d\n", solve());
}


int main() {
    int dataset_num, case_num;

    scanf("%d", &dataset_num);
    gets(buf);
    for(case_num = 1; case_num <= dataset_num; ++case_num) {
        printf("Case #%d: ", case_num);

        solve_and_print();
    }

    return 0;
}
