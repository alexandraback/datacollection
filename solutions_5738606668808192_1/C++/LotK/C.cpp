#include <cstdio>
#include <cstring>
//#define MAX 7
int MAX = 7;
#define DEMAND 5

// 16,50 -  MAX 7 DEMAND 5
// 32,500 - MAX 15 DEMAND 5

char one_permu[510][18];  // 7, 15
char temp[18];
int count;
void preprocess_one(int run, int n, int c) { // c is count for 1
    if (count == 500) return;
    if (run == n) {
        if (c==DEMAND) {
            temp[run] = '\0';
            strcpy(one_permu[count], temp);
            count++;
        }
        return;
    }

    temp[run] = '1';
    preprocess_one(run+1, n, c+1);
    temp[run] = '0';
    preprocess_one(run+1, n, c);
}

int main() {
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);

//    for(int i=0 ; i<count ; i++) {
//        for (int j=0 ; j<MAX ;j++) {
//            printf("%c", one_permu[i][j]);
//        }
//        printf("\n");
//    }

//    freopen("C-large.in", "r", stdin);
//    freopen("C-large.out", "w", stdout);

    int tt;
    scanf("%d", &tt);
    for (int t=0 ; t<tt ; t++) {
        int n, j;
        scanf("%d%d", &n, &j);
        MAX = n/2-1;
        count = 0;
        preprocess_one(0, MAX, 0);

        printf("Case #%d:\n", t+1);
        int one=0, zero=0;
        for (int i=0 ; i<j ; i++) {
            printf("1");
            for (int k=0 ; k<MAX ; k++) {
                printf("%c%c", one_permu[one][k], one_permu[zero][k]);
            }
            printf("1 3 2 3 2 7 2 3 2 3\n");

            zero++;
            if (zero == count) {
                one++;
                zero = 0;
            }
        }
    }
}
