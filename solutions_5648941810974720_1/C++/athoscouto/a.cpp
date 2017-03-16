#include <bits/stdc++.h>
using namespace std;

const int N = 2e3+1;
int n, T, t, l[300], d[11];
char s[N];
int main() {
    scanf("%d", &T);
    while(t++ < T) {
        scanf("%s", s);
        memset(l, 0, sizeof l);
        memset(d, 0, sizeof d);
        for(int i=0; s[i]; ++i) l[s[i]]++;
        while(l['Z']) l['Z']--, l['E']--, l['R']--, l['O']--, d[0]++;
        while(l['W']) l['T']--, l['W']--, l['O']--, d[2]++;
        while(l['X']) l['S']--, l['I']--, l['X']--, d[6]++;
        while(l['U']) l['F']--, l['O']--, l['U']--, l['R']--, d[4]++;
        while(l['F']) l['F']--, l['I']--, l['V']--, l['E']--, d[5]++;
        while(l['S']) l['S']--, l['E']--, l['V']--, l['E']--, l['N']--, d[7]++;
        while(l['O']) l['O']--, l['N']--, l['E']--, d[1]++;
        while(l['N']) l['N']--, l['I']--, l['N']--, l['E']--, d[9]++;
        while(l['G']) l['E']--, l['I']--, l['G']--, l['H']--, l['T']--, d[8]++;
        while(l['T']) l['T']--, l['H']--, l['R']--, l['E']--, l['E']--, d[3]++;
        printf("Case #%d: ", t);
        for(int i=0; i<10; ++i) while(d[i]--) printf("%d", i);
        printf("\n");
    }
    return 0;
}
