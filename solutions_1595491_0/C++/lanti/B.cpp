// B.cpp
// Problem B. Dancing With the Googlers
//
#include <algorithm>
#include <cstdio>
using namespace std;

void solve(int tcase)
{
    int N, S, p; scanf("%d%d%d", &N, &S, &p);
    int t[105];
    for(int i=0; i<N; ++i) scanf("%d", &t[i]);

    sort(t, t+N); reverse(t, t+N);
    int ans=0, cnt=0;
    for(int i=0; i<N; ++i) {
        int val = (t[i]+2)/3;
        if (val>=p) ans++;
        else {
            if (t[i]>=2) val = (t[i]-2)/3+2;
            if (val>=p && cnt<S) { ans++; cnt++; }
            else break;
        }
    }
    printf("Case #%d: %d\n", tcase, ans);
}

int main()
{
    int T; scanf("%d", &T);
    for(int t=1; t<=T; ++t) solve(t);
}
