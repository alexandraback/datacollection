#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <assert.h>

using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)

const int N = 128;

long long a, b;

vector<long long> palin;

char tmp[N];
bool check(long long n) {
    sprintf(tmp, "%lld", n);
    int len = strlen(tmp);
    REP(i, len / 2) {
        if(tmp[i] != tmp[len-1-i]) return false;
    }
    return true;
}

int findstart(int value)
{
    REP(i, palin.size()) if(palin[i] >= value) return i;
    assert(false);
    return -1;
}

int main()
{
    freopen("D:/tc_algo/a.in", "r", stdin);
    freopen("D:/tc_algo/a.out", "w", stdout);

    REP(i, 10000000) {
        if(check(i)) palin.push_back(i);
    }

    int T;
    cin >> T;
    REP(t, T) {
        cin >> a >> b;

        int res = 0;
        int tmp = (int)sqrt(a) - 1;
        int i = findstart(tmp);
        while(true) {
            long long now = palin[i] * palin[i];
            i++;
            if(now < a) continue;
            if(now > b) break;
            if(check(now)) res++;
        }

        printf("Case #%d: %d\n", t + 1, res);
    }

    return 0;
}
