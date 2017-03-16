// N‚Ì’·‚³‚É‘Î‚µ‚ÄAN/2‚ÌŒJ‚è•Ô‚µ‚ğì‚é‚±‚Æ‚Å•K‚¸Š„‚ê‚éB

#include<cstdio>
#include<cstdlib>


using namespace std;


long long X;
int t = 0;
int N, J;



void init() {
    X = 1;
    int x = N / 2;
    for(int i = 0; i < x-1; ++i) {
        X *= 2;
    }
    ++X;
}

long long base(int b, long long x) {
    if(x < 2) return x;
    return base(b, x / 2) * b + (x % 2);
}


void print_bin(long long x) {
    if(x == 1) putchar('1');
    else {
        print_bin(x / 2);
        putchar('0'+(x%2));
    }
}

void print() {
    // ŒJ‚è•Ô‚µ•ª
    print_bin(X);
    print_bin(X);
    for(int i = 2; i <= 10; ++i) {
        printf(" %lld", base(i, X));
    }
    printf("\n");
}


void solve_and_print() {
    int i = 0;

    scanf("%d %d", &N, &J);
    init();
    while(i < J) {
        print();
        ++i;
        X += 2;
    }
}


int main() {
    int dataset_num, case_num;

    scanf("%d", &dataset_num);
    for(case_num = 1; case_num <= dataset_num; ++case_num) {
        printf("Case #%d:\n", case_num);

        solve_and_print();
    }

    return 0;
}
