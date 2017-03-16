#include <cstdio>
#include <cstring>
#include <string>
#include <deque>
using namespace std;

#define PREV 0
#define BACK 1

int T;
int where[10000];
char S[10000];

int main() {
    scanf("%d", &T);
    for (int Case=1; Case<=T; Case++) {
        scanf("%s", S);
        int n = strlen(S);

        string ans;
        deque<char> ansl;

        int idx = n-1;
        while (idx >= 0) {
            char cur_last = 0;
            int last_idx = -1;
            for (int i=idx; i>=0; i--) {
                if (S[i] > cur_last) {
                    cur_last = S[i];
                    last_idx = i;
                }
            }

            where[last_idx] = PREV;
            for (int i=last_idx+1; i<=idx; i++) {
                where[i] = BACK;
            }
            idx = last_idx-1;
        }

        for (int i=0; i<n; i++) {
            if (where[i] == PREV) {
                ansl.push_front(S[i]);
            } else {
                ansl.push_back(S[i]);
            }
        }

        for (int i=0; i<n; i++) {
            ans += ansl.front();
            ansl.pop_front();
        }

        printf("Case #%d: %s\n", Case, ans.c_str());
    }
}
