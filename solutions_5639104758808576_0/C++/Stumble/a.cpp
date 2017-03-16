
#include <iostream>
#include <cstdio>

using namespace std;
const int MAXN = 1111;
int smax;
int sdata[MAXN];

void init()
{
    string temp;
    cin >> smax >> temp;
    for (int i = 0; i <= smax; i++) {
        sdata[i] = temp[i] - '0';
    }
}

int solve()
{
    int sum = 0;
    int ans = 0;
    for (int i = 0; i <= smax; i++) {
        int adds = 0;
        if (sum < i) adds = (i - sum);

        sum += sdata[i];
        sum += adds;
        ans += adds;
    }
    return ans;
}


int main(int argc, char *argv[])
{
    int T ;
    cin >> T;

    for (int tt = 1; tt <= T; tt++) {
        init();
        printf("Case #%d: %d\n",tt ,solve());
    }

    return 0;
}



