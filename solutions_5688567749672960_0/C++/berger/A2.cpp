#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int steps[1000001];

queue<int> q;
long long n;

void reverse(char* a, char* b) {
    int len = strlen(a);
    int i;
    for (i = 0; i < len; i++)
        b[i] = a[len-i-1];
    b[len] = 0;
}

long long reverseNum(long long num) {
    char strRep[20], rev[20];
    sprintf(strRep, "%lld", num);
    reverse(strRep, rev);
    long long ans;
    sscanf(rev, "%lld", &ans);
    return ans;
}

void bfs(long long where) {
    if (where > 1000000)
        return;
    if (!steps[where+1]) {
        q.push(where+1);
        steps[where+1] = steps[where]+1;
    }
    if (!steps[reverseNum(where)]) {
        q.push(reverseNum(where));
        steps[reverseNum(where)] = steps[where]+1;
    }
}

long long generate(long long num) {
    return steps[num];
}

int main() {
    int TT, T;
    scanf("%d", &TT);
    steps[1] = 1;
    q.push(1);
    while (!q.empty()) {
        bfs(q.front());
        q.pop();
    }
    
    for (T = 1; T <= TT; T++) {
        printf("Case #%d: ", T); 
        scanf("%lld", &n);
        printf("%lld\n", generate(n));
        
    }
}
        