#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

string s,s1;

int main() {
    int T;
    scanf("%d",&T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ",t);
        cin >> s;
        s1.clear();
        int n = s.length();
        for (int i = 0; i < n; i++)
            if (s1 + s[i] > s[i] + s1)
                s1 = s1 + s[i];
            else
                s1 = s[i] + s1;
        cout << s1 << '\n';
    }
    return 0;
}

