#include <stdio.h>
#include <map>
#define lli long long int
#define NO 0
#define YES 1
using namespace std;

char s[10005];
int l;
lli x;

map <char, int> mapa;
char r1;
int r2;

char table[4][4] =  {   {'1', 'i', 'j', 'k'},
                        {'i', '1', 'k', 'j'},
                        {'j', 'k', '1', 'i'},
                        {'k', 'j', 'i', '1'}
                    };

int sign[4][4] =    {   {1, 1, 1, 1},
                        {1, -1, 1, -1},
                        {1, -1, -1, 1},
                        {1, 1, -1, -1}
                    };
char need[] = {'i', 'j', 'k', 'x'};

void fast_exp(lli n) {
    char last = '1';
    int signal = 1;
    char aux;
    r1 = '1';
    r2 = 1;

    for (int i = 0; i < l; i++) {
        aux = last;
        last = table[mapa[aux]][mapa[s[i]]];
        signal = signal * sign[mapa[aux]][mapa[s[i]]];
    }

    while(n > 0) {
        if (n & 1) {
            r1 = table[mapa[r1]][mapa[last]];
            r2 = r2 * signal;
        }
        aux = last;
        last = table[mapa[aux]][mapa[aux]];
        signal = signal * signal;
        n /= 2;
    }
    return;
}

int main(void) {
    int t;
    int start;
    char last;
    int signal;
    int idx;
    int ok;
    char aux;

    mapa['1'] = 0;
    mapa['i'] = 1;
    mapa['j'] = 2;
    mapa['k'] = 3;

    /*for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("i = %d, j = %d, sign = %d\n", i, j, sign[i][j]);
        }
    } */

    scanf(" %d", &t);

    for (int caso = 1; caso <= t; caso++) {
        scanf(" %d %lld", &l, &x);
        scanf(" %s", s);

        start = 0;
        signal = 1;
        last = '1';
        idx = 0;
        ok = NO;
        for (int i = 0; i < x; i++) {
            if (idx >= 3) {
                fast_exp(x - i);
                last = table[mapa[last]][mapa[r1]];
                signal *= r2;
                if (last == '1' && signal == 1) {
                    ;
                } else {
                    ok = NO;
                }
                break;
            }
            for (int j = 0; j < l; j++) {
                //printf("here idx = %d, last = %c, signal = %d\n", idx, last, signal);
                start++;
                aux = last;
                last = table[mapa[aux]][mapa[s[j]]];
                signal = signal * sign[mapa[aux]][mapa[s[j]]];
                //printf("after idx = %d, last = %c, signal = %d\n", idx, last, signal);
                if (last == need[idx] && signal == 1) {
                    idx++;
                    last = '1';
                    start = 0;
                }
                if (start > 20 * l && idx != 3) {
                    ok = NO;
                    i = 1;
                    x = 0;
                    break;
                }
            }
        }
        //printf("idx = %d\n", idx);
        if (idx >= 3 && last == '1' && signal == 1) {
            ok = YES;
        }
        printf("Case #%d: ", caso);
        if (ok) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
