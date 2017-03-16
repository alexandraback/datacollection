#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int BUF = 1000005;


long long N;

void read() {
    cin >> N;
}


long long reverse(long long n) {
    long long ret = 0;
    while (n) {
        ret = ret * 10 + n % 10;
        n /= 10;
    }
    return ret;
}


void work(int cases) {
    static int visited[BUF];
    static int pi[BUF];
    memset(visited, -1, sizeof(visited));
    memset(pi, -1, sizeof(pi));
    
    queue<int> Q;
    Q.push(1);
    visited[1] = 0;
    
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        
        if (cur == N) {
            break;
        }

        if (visited[cur + 1] == -1) {
            visited[cur + 1] = visited[cur] + 1;
            pi[cur + 1] = cur;
            Q.push(cur + 1);
        }

        long long rev = reverse(cur);
        if (visited[rev] == -1) {
            visited[rev] = visited[cur] + 1;
            pi[rev] = cur;
            Q.push(rev);
        }
    }

    cout << "Case #" << cases << ": " << visited[N] + 1 << endl;
}


int main() {
    int cases;
    cin >> cases;
    
    for (int i = 0; i < cases; ++i) {
        read();
        work(i + 1);
    }
    return 0;
}
