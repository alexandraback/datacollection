#include <cstdio>
#include <iostream>
    using namespace std;


int main(int argc, char *argv[]){
    int T, cases;
    scanf("%d", &T);
    int nDigit;
    long long int list[1000];
    int nList = 0;
    list[nList++] = 1;
    list[nList++] = 4;
    list[nList++] = 9;
    list[nList++] = 121;
    list[nList++] = 484;
    for (nDigit = 3; nDigit <= 9; nDigit++) {
        int start = 1, end;
        int tmp = (nDigit+1)/2;
        int root;
        while (tmp > 1) {
            start *= 10;
            tmp--;
        }
        end = start * 10;
        int half, invHalf;
        for (half = start; half < end; ++half) {
            int tmpHalf = half;
            invHalf = 0;
            while (tmpHalf > 0) {
                invHalf = invHalf * 10 + tmpHalf % 10;
                tmpHalf /= 10;
            }
            long long int pal;
            if (nDigit % 2 == 0)
                pal = half * end + invHalf;
            else
                pal = (half/10) * end + invHalf; 
            long long int n = pal * pal;
            //fprintf(stderr, "%lld = %lld^2\n", n, pal);
            int digi[100];
            long long int tmp = n;
            int len = 0;
            while (tmp > 0) {
                digi[len++] = tmp % 10;
                tmp = tmp/10;
            }
            int isPal = 1;
            for (int i = 0; i < len; ++i) {
                if (digi[i] != digi[len-1-i]) {
                    isPal = 0;
                    break;
                }
            }
            if (isPal == 1) {
                list[nList++] = n;
                fprintf(stderr, "%lld = %lld^2\n", n, pal);
            }
        }
    }
    fprintf(stderr, "nList = %d\n", nList);
    for (cases = 1; cases <= T; cases++) {
        long long int a, b;
        cin >> a >> b;
        int count = 0;
        for (int i = 0; i < nList; ++i) {
            if (list[i] >= a && list[i] <= b)
                count++;
            else if (list[i] > b)
                break;
        }
        printf("Case #%d: %d\n", cases, count);
    }
    return 0;
}
