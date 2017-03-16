// b.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <vector>
#include <algorithm>
using namespace std;

typedef std::pair<int, int> IndexV;
bool comparePair(const IndexV& left, const IndexV& right)
{
    if (left.second != right.second) {
        return left.second > right.second;
    }
    return left.first < right.first;
}

struct Energy {
    Energy()
        : bIsSet(false){}
    bool bIsSet;
    int iBefore;
    int iAfter;
};

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
    for (int iTest = 0; iTest < nTestCount; ++iTest) {
        int E, R, N;
        fscanf_s(fpIn, "%d %d %d\n", &E, &R, &N);

        std::vector<Energy> arrayEnergy;   //Energy量と設定されたか
        arrayEnergy.resize(N);

        std::vector<IndexV> arrayIndexV;
        arrayIndexV.resize(N);
        for (int i = 0; i < N; ++i) {
            arrayIndexV[i].first = i;
            fscanf_s(fpIn, "%d ", &(arrayIndexV[i].second));
            int a = 0;
        }
        fscanf_s(fpIn, "\n");

        std::sort(arrayIndexV.begin(), arrayIndexV.end(), comparePair);

        __int64 sum = 0;
        for (size_t j = 0; j < arrayIndexV.size(); ++j) {
            const IndexV& indexV = arrayIndexV[j];

            Energy thisEnergy;

            thisEnergy.iAfter = 0;
            for (int i = indexV.first +1; i < (int)arrayEnergy.size(); ++i) {
                if (arrayEnergy[i].bIsSet) {
                    thisEnergy.iAfter = arrayEnergy[i].iBefore - R * (i - indexV.first);
                    if (thisEnergy.iAfter < 0) {
                        thisEnergy.iAfter = 0;
                    }
                    break;
                }
            }

            thisEnergy.iBefore = E;
            for (int i = indexV.first - 1; i >= 0; --i) {
                if (arrayEnergy[i].bIsSet) {
                    thisEnergy.iBefore = arrayEnergy[i].iAfter + R * (indexV.first - i);
                    if (thisEnergy.iBefore > E) {
                        thisEnergy.iBefore = E;
                    }
                    break;
                }
            }

            if (thisEnergy.iBefore > thisEnergy.iAfter) {
                sum += (thisEnergy.iBefore - thisEnergy.iAfter) * indexV.second;
            }

            thisEnergy.bIsSet = true;
            arrayEnergy[indexV.first] = thisEnergy;
        }

        fprintf_s(fpOut, "Case #%d: %I64d\n", iTest+1, sum);
    }


    fclose(fpIn);
    fclose(fpOut);


#ifdef CHECK_TIME
    clock_t end = clock();
    printf("%.2f秒かかりました\n",(double)(end-start)/CLOCKS_PER_SEC);
#endif

    return 0;
}

