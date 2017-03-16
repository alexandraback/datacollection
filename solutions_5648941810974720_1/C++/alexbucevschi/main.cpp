#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ll long long
#define pii pair<int,int>
#define tii tuple <int,int,int>
#define N 200005
#define mod 1000000005
#define X first
#define Y second
#define eps 0.0000000001
#define all(x) x.begin(),x.end()
#define tot(x) x+1,x+n+1
using namespace std;

int t, T;
char s[2010];
int f[30], a[15], i, n;
int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &T);

    for(t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        scanf("%s", &s);
        memset(f, 0, sizeof(f));
        n = strlen(s);

        for(i = 0; i < n; i++)
            f[s[i] - 'A']++;

        a[0] = f['Z' - 'A'];
        f['Z' - 'A'] -= a[0];
        f['E' - 'A'] -= a[0];
        f['R' - 'A'] -= a[0];
        f['O' - 'A'] -= a[0];
        a[2] = f['W' - 'A'];
        f['T' - 'A'] -= a[2];
        f['W' - 'A'] -= a[2];
        f['O' - 'A'] -= a[2];
        a[6] = f['X' - 'A'];
        f['S' - 'A'] -= a[6];
        f['I' - 'A'] -= a[6];
        f['X' - 'A'] -= a[6];
        a[8] = f['G' - 'A'];
        f['E' - 'A'] -= a[8];
        f['I' - 'A'] -= a[8];
        f['G' - 'A'] -= a[8];
        f['H' - 'A'] -= a[8];
        f['T' - 'A'] -= a[8];
        a[7] = f['S' - 'A'];
        f['S' - 'A'] -= a[7];
        f['E' - 'A'] -= a[7];
        f['V' - 'A'] -= a[7];
        f['E' - 'A'] -= a[7];
        f['N' - 'A'] -= a[7];
        a[5] = f['V' - 'A'];
        f['F' - 'A'] -= a[5];
        f['I' - 'A'] -= a[5];
        f['V' - 'A'] -= a[5];
        f['E' - 'A'] -= a[5];
        a[4] = f['F' - 'A'];
        f['F' - 'A'] -= a[4];
        f['O' - 'A'] -= a[4];
        f['U' - 'A'] -= a[4];
        f['R' - 'A'] -= a[4];
        a[9] = f['I' - 'A'];
        f['N' - 'A'] -= a[9];
        f['I' - 'A'] -= a[9];
        f['N' - 'A'] -= a[9];
        f['E' - 'A'] -= a[9];
        a[1] = f['N' - 'A']  ;
        f['O' - 'A'] -= a[1];
        f['N' - 'A'] -= a[1];
        f['E' - 'A'] -= a[1];
        a[3] = f['H' - 'A'];
//        a[0] = min(min(min(f['Z' - 'A'], f['E' - 'A']), f['R' - 'A']), f['O' - 'A']);
//        a[1] = min(min(min(f['O' - 'A'], f['E' - 'A']), f['N' - 'A']), f['N' - 'A']);
//        a[2] = min(min(min(f['O' - 'A'], f['T' - 'A']), f['W' - 'A']), f['W' - 'A']);
//        a[3] = min(min(min(f['T' - 'A'], f['H' - 'A']), f['R' - 'A']), f['E' - 'A']);
//        a[4] = min(min(min(f['F' - 'A'], f['O' - 'A']), f['U' - 'A']), f['R' - 'A']);
//        a[5] = min(min(min(f['F' - 'A'], f['I' - 'A']), f['V' - 'A']), f['E' - 'A']);
//        a[6] = min(min(min(f['S' - 'A'], f['I' - 'A']), f['X' - 'A']), f['X' - 'A']);
//        a[7] = min(min(min(f['S' - 'A'], f['E' - 'A']), f['V' - 'A']), f['N' - 'A']);
//        a[8] = min(min(min(min(f['E' - 'A'], f['I' - 'A']), f['G' - 'A']), f['H' - 'A']), f['T' - 'A']);
//        a[7] = min(min(min(f['N' - 'A'], f['I' - 'A']), f['E' - 'A']), f['N' - 'A']);

        for(i = 0; i <= 9; i++)
            while(a[i]) {
                a[i]--;
                printf("%d", i);
            }

        printf("\n");
    }

    return 0;
}

