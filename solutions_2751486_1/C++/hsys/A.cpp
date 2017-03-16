#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 1000011;

char word[MAX_N];
int start[MAX_N];
int cont[MAX_N];
int n, l, scnt;

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%s%d", word, &n);
        l = strlen(word);
        for (int i = 0; i < l; i++) {
            if (word[i] == 'a' || word[i] == 'e' ||
                word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
                word[i] = 0;
            } else {
                word[i] = 1;
            }
        }

        scnt = 0;
        
        cont[0] = word[0];
        if (cont[0] >= n)
            start[scnt++] = 0;
        for (int i = 1; i < l; i++) {
            if (word[i])
                cont[i] = cont[i - 1] + 1;
            else
                cont[i] = 0;

            if (cont[i] >= n) {
                //printf("%d ", i);
                start[scnt++] = i;
            }
        }


        long long total = 0;
        for (int i = 0; i < l; i++) {
            int* next = lower_bound(start, start + scnt, i + n - 1);
            if (next == start + scnt)
                continue;
            //printf("%d %d\n", i, *next);
            total += l - *next;
        }
        printf("Case #%d: %lld\n", t, total);
    }
}
