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

int t, T, n, sol;
map<string, int>M;
char s1[22], s2[22];
int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &T);

    for(t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        scanf("%d", &n);
        M.clear();
        sol = 0;

        for(; n; n--) {
            scanf("%s", &s1);
            scanf("%s", &s2);
            M[s1]++;

            if(M[s1] > 1)
                sol++;
        }

        printf("%d\n", sol);
    }

    return 0;
}

