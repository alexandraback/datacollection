#include <bits/stdc++.h>

using namespace std;

#define Long long long
#define ld long double
#define pii pair<int, int>
#define pli pair<Long, int>

const int me = 2025;
const int mod = 1.e9 + 7;
const int MAX_LOG = 20;

int t, n;
char s[me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d\n", &t);
    for(int c = 0; c < t; c ++){
        gets(s);
        n = strlen(s);
        int steps = 0;
        for(int i = n - 1; i >= 0; i --){
            if(s[i] == '+')
                continue;
            steps ++;
            /// naive
            for(int j = 0; j <= i; j ++)
                s[j] = '+' + '-' - s[j];
        }
        printf("Case #%d: ", c + 1);
        printf("%d\n", steps);
    }

    return 0;
}
