#include <cstdio>

#include <vector>
#include <map>

using namespace std;

typedef __int64 i64;

typedef vector<i64> TInt64Vector;
typedef vector<bool> TBoolVector;
typedef map<i64, TBoolVector> TMap;

bool Gen(const TInt64Vector& num, TMap& map, TBoolVector& a, TBoolVector& b) {
    i64 sum = 0;
    TBoolVector is(num.size());
    for (size_t i = 0; i < num.size(); ++i) {
        bool incl = 1 == (rand() & 1);
        is[i] = incl;
        if (incl)
            sum += num[i];
    }
    if (map.find(sum) == map.end()) {
        map.insert( TMap::value_type(sum, is) );
        return false;
    } else {
        a = is;
        b = map[sum];
        return true;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt","w", stdout);
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out","w", stdout);

    int nTests;
    scanf("%d", &nTests);
    for (int iTest = 0; iTest < nTests; ++iTest) {

        int n;
        scanf("%d", &n);
        TInt64Vector vct(n);
        for (size_t i = 0; i < n; ++i)
            scanf("%I64d", &vct[i]);

        TMap map;
        TBoolVector a;
        TBoolVector b;
        while (!Gen(vct, map, a, b));

        printf("Case #%d:\n", iTest + 1);
        for (size_t i = 0; i < n; ++i)
            if (a[i] && a[i] != b[i])
                printf("%I64d ", vct[i]);
        printf("\n");
        for (size_t i = 0; i < n; ++i)
            if (b[i] && a[i] != b[i])
                printf("%I64d ", vct[i]);
        printf("\n");
    }

    return 0;
}