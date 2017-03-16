#include <iostream>
#include <cstring>
#include <cstdio>
#include <deque>
using namespace std;

char str[1010];
deque<char> q;
int main() {
    int t, id = 1;
    scanf("%d", &t);
    while (t--) {
        printf("Case #%d: ", id++);
        scanf("%s", str);
        q.clear();
        q.push_back(str[0]);
        int len = strlen(str);
        for (int i = 1; i < len; i++) {
            if (str[i] >= q.front()) {
                q.push_front(str[i]);
            } else q.push_back(str[i]);
        }
        for (int i = 0; i < len; i++) {
            printf("%c", q.front());
            q.pop_front();
        }
        printf("\n");
    }
}
