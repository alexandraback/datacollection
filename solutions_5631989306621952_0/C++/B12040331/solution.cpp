
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 1e3+10;

void solve(char ch[], deque<char> &dq);
void print(int i, deque<char> dq);

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int icase;
    scanf("%d", &icase);
    char ch[MAXN];
    for(int i=1; i<=icase; ++i) {
        scanf("%s", ch);
        deque<char> dq;
        solve(ch, dq);
        print(i, dq);
    }
    return 0;
}

void solve(char ch[], deque<char> &dq) {
    int len = strlen(ch);
    dq.push_back(ch[0]);
    for(int i=1; i<len; ++i) {
        if(ch[i] >= dq.front()) {
            dq.push_front(ch[i]);
        }
        else {
            dq.push_back(ch[i]);
        }
    }
}

void print(int i, deque<char> dq) {
    printf("Case #%d: ", i);
    while(!dq.empty()) {
        putchar(dq.front());
        dq.pop_front();
    }
    printf("\n");
}

/*
OCDE
CCCBAABAB
*/
