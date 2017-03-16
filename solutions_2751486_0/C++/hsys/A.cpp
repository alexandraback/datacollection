#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 1000011;

char word[MAX_N];
int n, l;

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


        int total = 0;
        for (int i = 0; i < l; i++) {
            for (int j = i + 1; j <= l; j++) {
                int curr = 0;
                int cont = 0;
                for (int k = i; k < j; k++) {
                    if (word[k]) {
                        cont++;
                    } else {
                        curr = max(curr, cont);
                        cont = 0;
                    }
                }
                curr = max(curr, cont);

                if (curr >= n)
                    total++;
            }
        }
        printf("Case #%d: %d\n", t, total);
    }
}
