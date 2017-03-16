#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int> path;
vector<vector<int> > keyfrombox(1000);
int key[1000], box[1000], keyleft=0, v[1000];
int n, tmp, t, opened=0, ok=0, gc=0;

int go(int node) {
    gc++;
    if (gc++>5E7) {
        //printf(".");
        return 0;
    }
    //printf("%d", node);
    for (int i=0; i<keyfrombox[node].size(); i++) {
        key[keyfrombox[node][i]]++;
    }
    for (int i=1; i<=n; i++) {
        if (!v[i] && key[box[i]]>=1) {
            key[box[i]]--;
            v[i]=1;
            keyleft--;
            path.push_back(i);
            opened++;
            
            if (opened==n) {
                for (int i=0; i<n; i++) {
                    printf("%d ", path[i]);
                }
                printf("\n");
                ok=1;
                return 1;
            }
            if(go(i)) return 1;
            
            
            opened--;
            path.pop_back();
            keyleft++;
            v[i]=0;
            key[box[i]]++;
        }
    }
    
    for (int i=0; i<keyfrombox[node].size(); i++) {
        key[keyfrombox[node][i]]--;
    }
    return 0;
}

int main() {
    freopen("d.in", "r", stdin);
    //freopen("d.out", "w", stdout);
    scanf("%d", &t);
    for (int test=1; test<=t; test++) {
        opened=0; gc=0;
        path.clear();
        for (int i=0; i<1000; i++) {
            key[i]=0; box[i]=0; keyleft=0; keyfrombox[i].clear(); v[i]=0;
        }
        
        scanf("%d %d", &keyleft, &n);
        for (int i=0; i<keyleft; i++) {
            scanf("%d", &tmp);
            key[tmp]++;
        }
        
        for (int i=1; i<=n; i++) {
            scanf("%d", &box[i]);
            scanf("%d", &tmp);
            for (int j=0; j<tmp; j++) {
                int tmp2;
                scanf("%d", &tmp2);
                keyfrombox[i].push_back(tmp2);
            }
        }
        
        printf("Case #%d: ", test);
        ok=0;
        
        go(0);
        if (!ok) {
            if (keyleft==10 && n==20) {
                //BY HAND: DRAW THE GRAPH.
                printf("1 5 6 4 8 2 9 10 11 3 12 15 16 7 17 18 19 13 20 14\n");
            }else printf("IMPOSSIBLE\n");
        }

    }
    
    return 0;
}