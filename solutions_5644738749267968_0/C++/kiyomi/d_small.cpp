#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int T, n;
vector <int> nao;
vector <int> ken;

int read() {
    char b[100];
    scanf("%s", b);
    int n = (int) strlen(b);
    int r = 0;
    int p = 1;
    for (int i = n; i <= 6; i++)
        b[i] = '0';
    for (int i = 6; i >= 2; i--) {
        r += (b[i] - '0') * p;
        p *= 10;
    }
    return r;
}

int g1(vector <int> a, vector <int> b) {
    int r1 = 0, r2 = 0;
    sort(a.begin(), a.end());
    multiset <int> ms;
    for (int i = 0; i < (int) b.size(); i++)
        ms.insert(b[i]);
    for (int i = 0; i < (int) a.size(); i++) {
        if (ms.lower_bound(a[i]) != ms.end()) {
            ms.erase(ms.lower_bound(a[i]));
        } else {
            r1++;
            ms.erase(ms.begin());
        }
    }
    reverse(a.begin(), a.end());
    for (int i = 0; i < (int) b.size(); i++)
        ms.insert(b[i]);
    for (int i = 0; i < (int) a.size(); i++) {
        if (ms.lower_bound(a[i]) != ms.end()) {
            ms.erase(ms.lower_bound(a[i]));
        } else {
            r2++;
            ms.erase(ms.begin());
        }
    }
    return max(r1, r2);
}

int lie(vector <int> a, vector <int> b) {
    int r = 0;
    multiset <int> ms;
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++)
        ms.insert(a[i]);
    for (int i = 0; i < (int) b.size(); i++) {
        if (ms.lower_bound(b[i]) == ms.end())
            return r;
        r++;
        ms.erase(ms.lower_bound(b[i]));
    }
    return r;
}

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%d", &n);
        nao.clear();
        ken.clear();
        for (int i = 0; i < n; i++)
            nao.push_back(read());
        for (int i = 0; i < n; i++)
            ken.push_back(read());
        printf("Case #%d: %d %d\n", t, lie(nao, ken), g1(nao, ken));
    }

    return 0;

}
