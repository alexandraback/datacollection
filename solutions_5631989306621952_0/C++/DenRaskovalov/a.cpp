#include <cstdio>

#include <string>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for (int iTest = 1; iTest <= t; ++iTest) {
        char buffer[10000];
        scanf("%s", buffer);
        int len = strlen(buffer);
        string s;
        s += buffer[0];
        for (int i = 1; i < len; ++i) {
            char ch = buffer[i];
            if (ch >= s[0]) {
                string temp;
                temp += ch;
                s = temp + s;
            } else {
                s += ch;
            }
        }
        printf("Case #%d: %s\n", iTest, s.c_str());
    }

    return 0;
}

