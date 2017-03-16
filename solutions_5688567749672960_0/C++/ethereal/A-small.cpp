#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

typedef std::pair<int, int> II;

int answers[1000001];

int rev(int n) {
    char buffer[32];
    sprintf(buffer, "%i", n);
    std::reverse(buffer, buffer + std::strlen(buffer));
    return strtol(buffer, nullptr, 10);
}

int dp(int n) {
    if(n == 0) return 0;
    if(answers[n] != 0) return answers[n];

    int r = rev(n);
    int min = dp(n-1);//, dp(rev(n)))+1;
    if(r != n) min = std::min(min, dp(r));
    answers[n] = min+1;
    return min+1;
}

int main() {
    int T;
    std::cin >> T;

    std::queue<II> q;
    answers[1] = 1;
    q.push(II(1, 1));
    while(q.size()) {
        II n = q.front(); q.pop();
        if(n.second > answers[n.first]) continue;

        if(n.first >= 1000000) continue;

        if((n.first+1) <= 1000000 && (answers[n.first+1] > answers[n.first]+1 || answers[n.first+1] == 0)) {
            answers[n.first+1] = answers[n.first]+1;
            q.push(II(n.first+1, n.second+1));
        }
        int r = rev(n.first);
        if(r <= 1000000 && (answers[r] > answers[n.first]+1 || answers[r] == 0)) {
            answers[r] = answers[n.first]+1;
            q.push(II(r, n.second+1));
        }
    }
    /*std::cout << "Answers: " << std::endl;
    for(int i = 0; i < 100; i ++) {
        std::cout << "\t[" << i << "] = " << answers[i] << std::endl;
    }*/

    int C = 1;
    while(T--) {
        int N;
        std::cin >> N;
        std::cout << "Case #" << (C++) << ": ";
        std::cout << answers[N] << std::endl;
    }
    return 0;
}
