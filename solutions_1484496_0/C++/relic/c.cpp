#include <cstdio>
#include <vector>
#include <map>
using namespace std;

const int N = 256;
int n;
int array[N];

map<int, int> hash;

vector<int> decode(int code) {
    vector<int> ret;
    for (int i = 0; code> 0; ++i) {
        if (code % 2 == 1) ret.push_back(array[i]);
        code /= 2;
    }
    return ret;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        scanf("%d", &n);
        int ans1 = 0;
        int ans2 = 0;
        hash.clear();
        for (int i = 0; i < n; ++i) {
            scanf("%d", &array[i]);
        }
        for (int code = 0; code < (1u << n); ++code) {
            int sm = 0;
            int cd = code;
            for (int i = 0; cd > 0; ++i) {
                if (cd % 2 == 1) sm += array[i];
                cd /= 2;
            }
            if (hash.find(sm) == hash.end())
                hash[sm] = code;
            else {
                ans1 = code;
                ans2 = hash[sm];
                break;
            }
        }
        printf("Case #%d:\n", kase);
        if (ans1 == 0 && ans2 == 0) {
            printf("Impossible\n");
        } else {
            vector<int> ret1 = decode(ans1);
            vector<int> ret2 = decode(ans2);
            for (int i = 0; i < ret1.size(); ++i) {
                printf("%s%d",  i == 0 ? "": " ", ret1[i]);
            }
            printf("\n");
            for (int i = 0; i < ret2.size(); ++i) {
                printf("%s%d",  i == 0 ? "": " ", ret2[i]);
            }
            printf("\n");
        }
    }
}

