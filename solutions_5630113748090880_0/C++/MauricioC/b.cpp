#include <cstdio>
#include <set>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for (int z = 1; z <= t; z++) {
        int n;
        scanf("%d", &n);

        set<int> vals;
        for (int i = 0; i < 2*n-1; i++)
            for (int j = 0; j < n; j++) {
                int tmp;
                scanf("%d", &tmp);
                if (vals.find(tmp) == vals.end())
                    vals.insert(tmp);
                else
                    vals.erase(tmp);
            }

        printf("Case #%d:", z);
        for (set<int>::iterator it = vals.begin(); it != vals.end(); it++)
            printf(" %d", *it);
        printf("\n");
    }
}
