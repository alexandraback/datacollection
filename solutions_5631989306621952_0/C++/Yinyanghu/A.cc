#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

char s[2000];

string F(int left, int right) {
    if (left > right) return "";
    if (left == right) {
        string temp = "";
        temp = temp + s[left];
        return temp;
    }
    char maxC = 'A';
    int first = left;
    for (int i = left; i <= right; ++ i)
        if (s[i] > maxC) {
            maxC = s[i];
            first = i;
        }

    string ret = "";
    for (int i = first; i <= right; ++ i)
        if (s[i] == maxC)
            ret = ret + s[i];

    string A = F(left, first - 1);
    ret = ret + A;
    for (int i = first; i <= right; ++ i)
        if (s[i] != maxC)
            ret = ret + s[i];

    return ret;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test = 1; test <= T; ++ test) {
        scanf("%s", s);
        //printf("%s\n", s);
        printf("Case #%d: ", test);
        cout << F(0, strlen(s) - 1) << endl;
    }
    return 0;
}
