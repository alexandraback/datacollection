#include <bits/stdc++.h>
using namespace std;

int t,b,m;
vector<set<int>> adjList;

int solve(int node, int d){
    if(d > 7) return -1;
    int res = 0;
    if(node == b-1) return 1;
    for(int i : adjList[node]){
        int r = solve(i,d+1);
        if(r == -1) return -1;
        else res += r;
    }
    return res;
}

int main(){
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    scanf("%d",&t);
    for(int k = 1; k <= t; k++){
        scanf("%d%d",&b,&m);
        clog << k << " " << b << " " << m << endl;
        int x = b*(b-1)-(b-1)-(b-2);
        bool found = 0;
        for(int i = 0; i < (1 << x); i++){
            int c = 0;
            adjList.assign(b,set<int>());
            for(int j = 0; j < b-1; j++){
                for(int p = 0; p < b; p++){
                    if(j == p || p == 0) continue;
                    if(i & (1 << c)) adjList[j].insert(p);
                    c++;
                }
            }
            c = 0;
            if(solve(0,0) == m){
                cout << "Case #" << k << ": POSSIBLE" << endl;
                for(int j = 0; j < b; j++){
                    for(int p = 0; p < b; p++){
                        if(j == p || j == b-1 || p == 0) cout << "0";
                        else if(i & (1 << c++)) cout << "1";
                        else cout << "0";
                    }
                    cout << endl;
                }
                found = 1;
                break;
            }
        }
        if(!found){
            cout << "Case #" << k << ": IMPOSSIBLE" << endl;
        }
    }
}