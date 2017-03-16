// a.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <vector>
using namespace std;

__int64 SumPenki(__int64 n, __int64 r)
{
    return n * (2 * r + 2 * n - 1);
}

#define CHECK_TIME
int main(int argc, char* argv[])
{
#ifdef CHECK_TIME
    clock_t start = clock();
#endif

    if (argc != 3) {
        return 1;
    }

    FILE* fpIn = NULL;
    fopen_s(&fpIn, argv[1], "r");
    if (!fpIn) {
        return 2;
    }
    FILE* fpOut = NULL;
    fopen_s(&fpOut, argv[2], "w");
    if (!fpOut) {
        return 3;
    }

    char sz[1024];
    fgets(sz, 1024, fpIn);
    int nTestCount = atoi(sz);
    for (int i = 0; i < nTestCount; ++i) {
        fgets(sz, 1024, fpIn);
        __int64 r = _atoi64(sz);

        char* pc = sz;
        while('0' <= *pc && *pc <= '9'){++pc;}
        while(*pc < '0' || '9' < *pc){++pc;}

        __int64 t = _atoi64(pc);

        //最大で10E9
        //__int64 penki1 = SumPenki(1, 1);
        //__int64 penki2 = SumPenki(2, 1);
        //__int64 penki3 = SumPenki(1, 3);

        //挟み撃ち法で解を探す
        __int64 min = 0;
        __int64 max = 1000000000;
        if (r > 1000000000) {
            max = 1000000000000000000 / r;
        }

        __int64 result;
        while (true) {
            __int64 mid = (min + max) / 2;
            if (mid == min || mid == max) {
                result = min;
                break;
            }

            __int64 penki = SumPenki(mid, r);
            if (penki == t) {
                result = mid;
                break;
            } else if (t < penki) {
                max = mid;
            } else {
                min = mid;
            }
        }
        fprintf_s(fpOut, "Case #%d: %d\n", i+1, result);
    }


    fclose(fpIn);
    fclose(fpOut);


#ifdef CHECK_TIME
    clock_t end = clock();
    printf("%.2f秒かかりました\n",(double)(end-start)/CLOCKS_PER_SEC);
#endif

    return 0;
}

