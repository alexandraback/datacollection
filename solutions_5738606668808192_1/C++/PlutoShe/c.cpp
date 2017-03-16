#include <iostream>
#include <cstdio>
using namespace std;

string ans[6000];
int n = 30;
int ansl = 0;

void dfs(int pos, int cur_remain1, int cur_remain2, int jo, int selected, string w) {
    if (ansl >= 500) {
        return;
    }
    if (pos >= n || selected < 0) {
        return;
    }
    // printf("%d %d %d %d %d %s\n", ansl, pos, cur_remain1, cur_remain2, selected, w.c_str());
    if (selected == 0 && cur_remain1 == 0 && cur_remain2 == 0 && jo == 0) {
        for (int j = pos; j < n; j++) {
            w += "0";
        }
        ans[ansl] = w;
        ansl++;
        return;
    }
    int newjo = jo;
    if (pos % 2 == 0)
        newjo+=1;
    else
        newjo-=1;
    dfs(pos + 1, (cur_remain1 + (pos + 1) % 2 + 1) % 3, (cur_remain2 + pos % 2 + 1) % 3, newjo, selected - 1, w + "1");
    dfs(pos + 1, cur_remain1, cur_remain2, jo, selected, w + "0");
}

// long long divededbysix(string s) {
//     long long j = 1;
//     long long sum = 0;
//     for (int i = s.size() - 1; i >= 0; i--) {
//         sum += j * (s[i] == '1');
//         j *= 6;
//     }
//     for (long long k = 5; k < sum / k; k++) {
//         if (sum % k == 0) return k;
//     }
//     return -1;
// }

string reverse(string s) {
    string rs = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            rs += "1";
        } else {
            rs += "0";
        }
    }
    return rs;
}

int main() {
    freopen("output.txt", "w", stdout);
    ansl = 0;
    // n / 2
    for (int j = 4; j <= n; j += 6) {
        dfs(0, 0, 0, 0, j, "");
    }

    printf("Case #1:\n");
    for (int i = 0; i < 500; i++) {
        // printf("%s\n", ("1"+ans[i]+"1").c_str());
        // long long g = divededbysix("1"+ans[i]+"1");
        // if (g != -1) {
        printf("%s 3 2 3 2 7 2 3 2 3\n", ("1"+ans[i]+"1").c_str());
        // }
        // g = divededbysix("1"+reverse(ans[i])+"1");
        // if (g != -1) {
        //     printf("%s 3 2 3 2 %lld 2 3 2 3\n", ("1"+reverse(ans[i])+"1").c_str(), g);
        // }
    }

    return 0;
}