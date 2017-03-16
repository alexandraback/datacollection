#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>


std::vector<char> ans;

void swapxy(std::vector<char> &ans) {
    char match[256]; 
    for (int i = 0; i < 4; i ++)
        match["NSEW"[i]] = "EWNS"[i];
    for (int i = 0; i < ans.size(); i ++) 
        ans[i] = match[ans[i]];
}

void swapx(std::vector<char> &ans) {
    for (int i = 0; i < ans.size(); i ++)
        if (ans[i] == 'E') ans[i] = 'W';
        else if (ans[i] == 'W') ans[i] = 'E';
}

void swapy(std::vector<char> &ans) {
    for (int i = 0; i < ans.size(); i ++)
        if (ans[i] == 'N') ans[i] = 'S';
        else if (ans[i] == 'S') ans[i] = 'N';
}

int main() {
    int T;
    std::cin >> T;
    for (int ct = 1; ct <= T; ct ++) {
        int ox, oy;
        std::cin >> ox >> oy;
        int x = abs(ox), y = abs(oy);
        bool fswap = false;
        if (x < y) {fswap = true; std::swap(x, y);}
        ans.clear();

        for (int i = 0; i < x; i ++) {
            ans.push_back('W'); 
            ans.push_back('E');
        }
        for (int i = 0; i < y; i ++) {
            ans.push_back('S');
            ans.push_back('N');
        }
        
        if (fswap) {swapxy(ans); std::swap(x, y);}
        if (x == -ox) swapx(ans);
        if (y == -oy) swapy(ans);

        printf("Case #%d: ", ct);
        for (int i = 0; i < ans.size(); i ++)
            printf("%c", ans[i]);
        printf("\n");
    }
}
