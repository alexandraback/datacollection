#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

vector <int> a[1001];
int ck[1001];
bool ans;

void DFS(int n) {
    int i, j;
    if(ans) return;
    for(i = 0;i < a[n].size();i++) {
        if(ck[a[n][i]]) {
            ans = 1;
            return;
        }
        ck[a[n][i]]++;
        DFS(a[n][i]);
        if(ans) return;
    }
}

int main() {
    FILE* f;
    f = fopen("PA.txt", "w");
    int T, Count = 1;
    int n, m;
    int i, j, tmp;
    cin >> T;
    while(T--) {
        cin >> n;
        ans = 0;
        for(i = 1;i <= n;i++) {
            a[i].clear();
            cin >> m;
            for(j = 1;j <= m;j++) {
                cin >> tmp;
                a[i].push_back(tmp);
            }
        }
        
        for(i = 1;i <= n;i++) {
            memset(ck, 0, sizeof(ck));
            DFS(i);
            if(ans) break;
        }
        
        if(ans) {
            fprintf(f, "Case #%d: Yes\n", Count++);
        }
        else {
            fprintf(f, "Case #%d: No\n", Count++);
        }
    }
}
