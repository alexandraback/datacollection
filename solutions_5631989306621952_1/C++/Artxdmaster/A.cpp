#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    string s;
    for (int tc = 0; tc < t; tc++) {
        printf("Case #%d: ", tc+1);
        cin >> s;
        deque < char > sol;
        sol.push_back(s[0]);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] < sol.front())
                sol.push_back(s[i]);
            else
                sol.push_front(s[i]);
        }
        while (!sol.empty()) {
            printf("%c", sol.front());
            sol.pop_front();
        }
        printf("\n");
    }
    return 0;
}
