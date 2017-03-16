#include <cstdio>
#include <cstring>
#include <cassert>

#include <algorithm>

using namespace std;

const int MAX_SIZE = 1000000;
const int MAX_K = 2 * MAX_SIZE + 2;

int InitSize, Sum[MAX_K], SumSizes[MAX_K], Solution;

inline int GetSum(const int size) {
    if (size < 0)
        return 0;
    if (size > MAX_SIZE)
        return Sum[MAX_SIZE];
    return Sum[size];
}

inline int GetSumSizes(const int size) {
    if (size < 0)
        return 0;
    if (size > MAX_SIZE)
        return SumSizes[MAX_SIZE];
    return SumSizes[size];
}

inline int GetNewSize(const int size, int prevSize) {
    int newSize = size;
    while (GetSumSizes(newSize - 1) - GetSumSizes(prevSize - 1) > 0) {
        int grow = GetSumSizes(newSize - 1) - GetSumSizes(prevSize - 1);
        prevSize = newSize;
        newSize += grow;
    }
    return newSize;
}

int GetMinCost(int size, int prevSize) {
    size = GetNewSize(size, prevSize);
    if (size == 1)
        return GetSum(MAX_SIZE) - GetSum(size - 1);
    if (GetSum(MAX_SIZE) - GetSum(size - 1) == 0)
        return 0;
    return min(GetSum(MAX_SIZE) - GetSum(size - 1), 1 + GetMinCost(2 * size - 1, size));
}

void Solve() {
    for (int i = 1; i < MAX_K; ++i) {
        Sum[i] += Sum[i - 1];
        SumSizes[i] = SumSizes[i - 1] + i * (Sum[i] - Sum[i - 1]);
    }
    Solution = GetMinCost(InitSize, 0);
}

void Read() {
    int N;
    assert(scanf("%d %d", &InitSize, &N) == 2);
    for (int i = 1; i <= N; ++i) {
        int size; assert(scanf("%d", &size) == 1);
        ++Sum[size];
    }
}

void Print(const int test) {
    printf("Case #%d: %d\n", test, Solution);
}

void Clear() {
    memset(Sum, 0, sizeof(Sum));
    memset(SumSizes, 0, sizeof(SumSizes));
}

int main() {
    assert(freopen("input.in", "r", stdin));
    assert(freopen("output.out", "w", stdout));
    int tests; assert(scanf("%d", &tests) == 1);
    for (int t = 1; t <= tests; ++t) {
        Read();
        Solve();
        Print(t);
        Clear();
    }
    return 0;
}
