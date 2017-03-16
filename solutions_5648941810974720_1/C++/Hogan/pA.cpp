#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

char table[10][100] = {"ZERO", "SIX", "EIGHT", "TWO", "FOUR", "FIVE", "NINE", "ONE", "THREE", "SEVEN"};
int val[10] = {0, 6, 8, 2, 4, 5, 9, 1, 3, 7};

int main() {
    int t;
    scanf("%d", &t);

    char in[2010];
    for (int times = 0; times < t; times++) {
        scanf("%s", in);

        int cnt[26] = {0};
        for (int i = 0; in[i]; i++) {
            cnt[in[i]-'A'] += 1;
        }
        
        vector<int> vct;
                
        int sum = strlen(in);
        for (int k = 0; k < 10 and sum; k++) {
            while (true) {
                int tmp[26] = {0};
                for (int i = 0; table[k][i]; i++) {
                    tmp[table[k][i]-'A'] += 1;
                }

                bool suc = true;
                for (int i = 0; i < 26; i++) {
                    if (cnt[i] < tmp[i]) {
                        suc = false;
                    }
                }
                
                if (suc == true) {
                    for (int i = 0; table[k][i]; i++) {
                        cnt[table[k][i]-'A'] -= 1;
                    }
                    sum -= strlen(table[k]);
                    vct.push_back(val[k]);
                } else {
                    break;
                }
            }
        }
        sort(vct.begin(), vct.end());

        printf("Case #%d: ", times+1);
        for (auto &v : vct) {
            printf("%d", v);
        }
        puts("");

        assert(sum == 0);
    }
}
