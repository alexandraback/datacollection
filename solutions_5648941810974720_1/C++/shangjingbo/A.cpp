#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

char s[100000];
int cnt[256];

string order[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int main()
{
    int tests, test = 1;
    for (scanf("%d", &tests); test <= tests; ++ test) {
        scanf("%s", s);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; s[i]; ++ i) {
            ++ cnt[s[i]];
        }
        int ans[10];
        memset(ans, -1, sizeof(ans));
        for (int i = 0; i < 10; ++ i) {
            int u = -1;
            for (int j = 0; j < 10; ++ j) {
                if (ans[j] == -1) {
                    char target = -1;
                    for (int ptr = 0; ptr < order[j].size(); ++ ptr) {
                        bool valid = true;
                        char ch = order[j][ptr];
                        for (int k = 0; k < 10; ++ k) {
                            if (ans[k] == -1 && j != k) {
                                valid &= order[k].find(ch) == -1;
                            }
                        }
                        if (valid) {
                            target = ch;
                            break;
                        }
                    }
                    if (target != -1) {
                        int total = 0;
                        for (int ptr = 0; ptr < order[j].size(); ++ ptr) {
                            total += order[j][ptr] == target;
                        }
                        ans[j] = cnt[target] / total;
                        for (int ptr = 0; ptr < order[j].size(); ++ ptr) {
                            cnt[order[j][ptr]] -= ans[j];
                        }

                        break;
                    }
                }
            }
        }

        printf("Case #%d: ", test);
        for (int i = 0; i < 10; ++ i) {
            for (int j = 0; j < ans[i]; ++ j) {
                printf("%d", i);
            }
        }
        puts("");
    }
    return 0;
}
