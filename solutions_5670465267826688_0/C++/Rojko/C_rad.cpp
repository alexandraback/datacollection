#include<cstdio>
#include<vector>
#include<algorithm>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void print(vector<int> &v) {
    for (int i = 0; i<v.size(); ++i) printf("%d ", v[i]);
    printf("\n");
}

int fun(int x, int y) {
    if (x == 1) return y;
    if (y == 1) return x;
    if (x == y) return -1;
    if (x == 2 && y == 3) return 4;
    if (x == 2 && y == 4) return -3;
    if (x == 3 && y == 2) return -4;
    if (x == 3 && y == 4) return 2;
    if (x == 4 && y == 2) return 3;
    if (x == 4 && y == 3) return -2;
    return 0;
}

bool vyhodnot(vector<int> &v) {
    int ret = 1;
    int znam = 1;
    int co = 2;
    int i;
    for (i = 0; i<v.size(); ++i) {
        int x = fun(ret, v[i]);
        if (x < 0) znam *= -1;
        ret = abs(x);
        if (co > 1 && znam*ret == co) {
            znam = 1;
            ret = 1;
            co++;
            if (co == 5) co = 1;
        }
    }
    if (co == 1 && ret*znam == 1) return true;
    return false; 
}

int main(){
    int T;
    scanf("%d", &T);
    for (int t = 0; t<T; ++t) {
        int l,x;
        scanf("%d %d ", &l, &x);
        vector<int> v;
        vector<int> p(3,0);
        for (int i = 0; i<l; ++i) {
            char c;
            scanf("%c", &c);
            v.push_back(c-'i'+2);
            p[c-'i']++;
        }
        sort(p.begin(), p.end());
        if (p[0] == 0 && p[1] == 0) {
            printf("Case #%d: NO\n", t+1);
            continue;
        }
        if (p[0] == 0 && p[1] == 1 && x == 1) {
            printf("Case #%d: NO\n", t+1);
            continue;
        }
        vector<int> a(x*l);
        for (int i = 0; i<x; ++i) copy(v.begin(), v.end(), a.begin()+i*l);
        if (vyhodnot(a)) {
            printf("Case #%d: YES\n", t+1);
            continue;
        } else {
            printf("Case #%d: NO\n", t+1);
            continue;
        }
    }
	return 0;
}
