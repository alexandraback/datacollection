#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int reverse(int n){
    int ret = 0;
    while(n != 0){
        ret *= 10;
        int r = n%10;
        ret += r;
        n /=10;

    }
    return ret;
}

int bfs(int from, int to){
    queue<ii> q;
    q.push(ii(from, 0));
    vector<int> v(2*to, 0);
    v[from] = true;
    while(!q.empty()){
        ii c = q.front();
        int d = c.second;
        q.pop();
        if(c.first == to) return d;
        int n1 = reverse(c.first);
        if(n1 < 2*to && !v[n1]){
            q.push(ii(n1, d+1));
            v[n1] = true;
        }
        if(c.first + 1 < 2*to && !v[c.first + 1]){
            v[c.first + 1] = true;
            q.push(ii(c.first+1, d+1));
        }
    }
    return -1;

}

int main() {
    int TC;
    cin >> TC;
    int casenum = 1;
    while(TC--){
        int N;
        cin >> N;
        cout << "Case #" << casenum++ << ": " << bfs(1,N)+1 << endl;
    }
    return 0;
}
