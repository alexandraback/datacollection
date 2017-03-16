#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;

int N, M;
pair<long long, int> boxes[111]; // velicina N
pair<long long, int> toys[111]; // velicina M

long long memo[111][111];

long long rec(int a, int b) {
    if (a == N || b == M) return 0;

    long long& ret = memo[a][b];
    if (ret >= 0) return ret;

    ret = rec(a+1, b);
    ret = max(ret, rec(a, b+1));

    for (int t = 0; t < 2; ++t) {
        int type = t==0?boxes[a].second : toys[b].second;
        long long sumBoxes = 0;

        for (int i = a; i < N; ++i) {
            if (boxes[i].second == type) sumBoxes += boxes[i].first;
            long long sumToys = 0;
            for (int j = b; j < M; ++j) {
                if (toys[j].second == type) sumToys += toys[j].first;
                ret = max(ret, rec(i+1, j+1)+min(sumBoxes, sumToys));
            }
        }
    }

    return ret;
}

void mergaj(pair<long long, int>* arr, int& sz) {
    for (int i = 1; i < sz; ) {
        if (arr[i].second == arr[i-1].second) {
            arr[i-1].first += arr[i].first;
            for (int j = i+1; j < sz; ++j) swap(arr[j-1], arr[j]);
            --sz;
        } else {
            ++i;
        }
    }
}

int main(void) {
    int test; scanf("%d", &test);

    for (int cs = 0; cs < test; ++cs) {
        scanf("%d%d", &N, &M);

        for (int i = 0; i < N; ++i) scanf("%lld%d", &boxes[i].first, &boxes[i].second);
        for (int i = 0; i < M; ++i) scanf("%lld%d", &toys[i].first, &toys[i].second);

        //mergaj(boxes, N);
        //mergaj(toys, M);

        memset(memo, -1, sizeof memo);
        long long sol = rec(0, 0);

//        printf("Case #%d: %lld\n", cs+1, sol);
        cout << "Case #" << cs + 1 << ": " << sol << endl;
    }
return 0;
}
