#include <cstdio>
#include <algorithm>
#include <cassert>
#include <string>
using namespace std;

string names[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

int pc[10] = { 'Z', 'X', 'S', 'V', 'G', 'I', 'W', 'F', 'N', 'R' };
int pi[10] = {  0,   6,   7,   5,   8,   9,   2,   4,   1,   3  };

int cnt['Z'-'A'+1];
char s[2001];

int result[10];

void remove(char i, int c) {
    for (int j=0; j<int(names[i].size()); j++) {
        assert(cnt[names[i][j] - 'A'] >= c);
        cnt[names[i][j] - 'A'] -= c;
    }
}

void print() {
    for (int i=0; i<10; i++)
        for (int j=0; j<result[i]; j++)
            printf("%d", i);
}

int main() {
    int T; scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        scanf("%s", s);
        
        fill(cnt, cnt+sizeof(cnt)/sizeof(cnt[0]), 0);
        char* p = s;
        while (*p)
            cnt[*p++ - 'A']++;
        
//         for (int g='A'; g<='Z'; g++) if (cnt[g-'A']) printf("%c cnt=%d\n", g, cnt[g-'A']);
        
        fill(result, result+10, 0);
        for (int i=0; i<10; i++) {
            int occurences = cnt[ pc[i] -'A' ];
//             if (occurences) printf("occurences of %d = %d by %c\n", pi[i], occurences, pc[i]);
            result[ pi[i] ] += occurences;
            
            remove(pi[i], occurences);
//             if (occurences) for (int g='A'; g<='Z'; g++) if (cnt[g-'A']) printf("%c cnt=%d\n", g, cnt[g-'A']);
        }
        
        printf("Case #%d: ", t);
        print();
        printf("\n");
    }
    return 0;
}

