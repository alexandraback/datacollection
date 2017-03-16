#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <tr1/unordered_set>
#include <tr1/unordered_map>

using namespace std;

const int N = 201;
int A[N];
uint32_t pw[N];
int n;

int main() {
    int cas;
    scanf("%d", &cas);
    pw[0] = 1;
    for (int i = 1;i < N;i++) pw[i] = pw[i-1]*3;
    for (int ic = 1;ic <= cas;ic++) {
        scanf("%d", &n);
        for (int i = 0;i < n;i++) scanf("%d", &A[i]);
        printf("Case #%d:\n", ic);
        uint32_t i = 0;
        for (;i < pw[n-1];i++) {
            uint32_t t = i;
            uint32_t sa = 0;
            uint32_t sb = 0;
            vector<int> va;
            vector<int> vb;
            for (int j = 0;j < n;j++) {
                if (t%3 == 2) {
                    sa += A[j];
                    va.push_back(A[j]);
                }else if (t%3 == 1) {
                    sb += A[j];
                    vb.push_back(A[j]);
                }
                t /= 3;
            }
            if (sa > 0 && sa == sb) {
                for (int i = 0;i < va.size();i++) printf("%d ", va[i]);
                printf("\n");
                for (int i = 0;i < vb.size();i++) printf("%d ", vb[i]);
                printf("\n");
                break;
            }
        }
        if (i >= pw[n-1]) {
            printf("Impossible\n");
        }
    }
    return 0;
}
