#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{
    int T;
    cin >> T;
    for (int ct = 1; ct <= T; ct++) {
        string str[1000];
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> str[i];
        }
        sort(str, str+n);
        int counter = 0;
        int ind[1000];
        for (int i = 0; i < n; i++) {
            ind[i] = i;
        }
        do {
            int isUsed[30] = {0};
            int fg = 0;
            string tmp = "";
            for (int i = 0; i < n; i++) {
                tmp += str[ind[i]];
            }
            for (int i = 0; i < tmp.size(); i++) {
                char tt = tmp[i];
                if (isUsed[tt-'a'] == 0) {
                    while (tmp[i+1] == tt) {
                        i++;
                    }
                    isUsed[tt-'a'] = 1;
                } else {
                    fg = -1;
                }
            }
            if (fg != -1) {
                counter++;
            }
        } while (next_permutation(ind, ind+n));
        printf("Case #%d: %d\n", ct, counter);
    }
    return 0;
}
