#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100

int T;
bool S[MAX_N];

int flip(int n, bool b) {
    if(n == 0)
        return 0;
    else if(S[n-1] == b)
        return flip(n-1, b);
    else
        return 1 + flip(n-1, !b);
}

int main() {
    scanf("%d", &T);
    for(int t = 0; t < T; ++t) {
        string s; cin >> s;
        for(int i = 0; i < s.size(); ++i)
            S[i] = ((s[i] == '+') ? true : false);
        printf("Case #%d: %d\n", t+1, flip(s.size(), true));
    }
}

