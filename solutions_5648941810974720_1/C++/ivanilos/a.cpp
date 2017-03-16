#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <string.h>
#define MAXN 2005
#define pb push_back
using namespace std;

vector <string> v;
vector <int> num;
vector <int> res;
char s[MAXN];
int let[26];

void solve(int idx) {
    int ok = 1;
    while(ok) {
        for (int i = 0; i < (int)v[idx].size(); i++) {
            if (let[v[idx][i] - 'A'] == 0) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            for (int i = 0; i < (int)v[idx].size(); i++) {
                let[v[idx][i] - 'A']--;
            }
            res.pb(num[idx]);
        }
    }
    return;
}

int main(void) {
    int t;

    v.pb("SIX");
    v.pb("SEVEN");
    v.pb("FIVE");
    v.pb("ZERO");
    v.pb("TWO");
    v.pb("FOUR");
    v.pb("ONE");
    v.pb("NINE");
    v.pb("THREE");
    v.pb("EIGHT");
    num.pb(6);
    num.pb(7);
    num.pb(5);
    num.pb(0);
    num.pb(2);
    num.pb(4);
    num.pb(1);
    num.pb(9);
    num.pb(3);
    num.pb(8);

    scanf(" %d", &t);
    for (int caso = 1; caso <= t; caso++) {
        res.clear();
        scanf(" %s", s);
        int n = strlen(s);
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'A';
            let[idx]++;
        }

        for (int i = 0; i < (int)v.size(); i++) {
            solve(i);
        }

        sort(res.begin(), res.end());
        printf("Case #%d: ", caso);
        for (int i = 0; i < (int)res.size(); i++) {
            printf("%d", res[i]);
        }
        printf("\n");
    }
    return 0;
}




