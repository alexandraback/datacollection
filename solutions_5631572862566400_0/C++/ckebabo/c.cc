#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int N;
int F[1005];
int v[1005];
vector<int> p;

int ans=0;

bool check(int n) {
    for(int i=1;i<n-1;i++) {
        if(F[p[i]] != p[i-1] && F[p[i]] != p[i+1]) {
            return false;
        }
    }

    return true;
}

void foo(int u, int depth) {
    p.push_back(u);
    v[u] = 1;

    bool b = check(depth);
    bool bb = false;
    bool cc = false;
    if(depth>1) {
        if(F[p[0]] == p[1]) bb=true;
        if(F[p[0]] == p[depth-1]) bb=true;
        if(F[p[depth-1]] == p[depth-2]) cc=true;
        if(F[p[depth-1]] == p[0]) cc=true;
    }
    if(b && bb && cc) {
        ans = max(ans, depth);
    }

    if(b) {
        for(int i=1;i<=N;i++) {
            if(v[i] == 0) {
                foo(i, depth+1);
            }
        }
    }

    v[u] = 0;
    p.pop_back();
}

int main() {
    int T;

    cin >> T;
    for(int cs=1;cs<=T;cs++) {
        cin >> N;
        for(int i=0;i<N;i++) cin >> F[i+1];
        
        for(int i=0;i<1005;i++) v[i]=0;
        ans = 0;

        for(int i=1;i<=N;i++) {
            foo(i, 1);
        }

        printf("Case #%d: %d\n", cs, ans);
    }

    return 0;
}
