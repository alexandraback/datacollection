#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <string>
#include <cctype>
#include <cstring>

typedef long long llong;

using namespace std;

bool isvowel(char a)  {
    return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
}

int main() {

    int t;
    cin >> t;

    for(int tc = 1; tc <= t; tc++) {
        string s;
        int n;
        cin >> s >> n;

        long long ans = 0;

        long long lb = -1, count = 0;

        for(int i = 0; i < s.size(); i++) {
            if(!isvowel(s[i]))
                count++;
            else
                count = 0;

            if(count >= n)
                lb = i - n + 1;

            if(lb != -1)
                ans += lb + 1;
        }

        cout << "Case #" << tc << ": " << ans << endl;
    }

    return 0;
}
