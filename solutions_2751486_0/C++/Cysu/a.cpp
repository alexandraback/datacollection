#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void solve(int caseNum)
{
    // SOLVE TASK HERE!
    string name;
    int n;

    cin >> name >> n;

    int len = name.length();

    int prev_i = -1;
    int ans = 0;
    for (int i = 0; i < len-n+1; ++i) {
        bool isValid = true;
        for (int j = i; j < i+n; ++j) {
            if (name[j] == 'a' || name[j] == 'e' || name[j] == 'i' || name[j] == 'o' || name[j] == 'u') {
                isValid = false;
                break;
            }
        }

        if (!isValid) continue;

        ans += (i-prev_i) * (len - (i+n-1));
        prev_i = i;
    }

    // output module
    printf("Case #%d: %d\n", caseNum, ans);
}


int main()
{
    int T;
    scanf("%d\n", &T);

    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        solve(caseNum);
    }

    return 0;
}

