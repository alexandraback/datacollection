#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <list>
#include <cstring>
#include <map>

#define FOREACH(a,c) for(__typeof((c).begin()) a = (c).begin(); a != (c).end(); a++)
#define MP(i,j) make_pair(i,j)

using namespace std;

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;

const int MAXX = 1010;
int D[MAXX][MAXX];
VI Graph[MAXX];

int getD(int m, int n){
    if (D[m][n] != -1) return D[m][n];
    int s = 0;
    for (int i = 0; i < Graph[m].size(); i++)
        s += getD(Graph[m][i], n);
    return D[m][n] = s;
}

int main(){
    int T; scanf ("%d", &T);
    for (int w = 0; w < T; w++){
        int n; scanf ("%d", &n);
        for (int j = 0; j < n; j++){
            int m; scanf ("%d", &m);
            Graph[j].clear();
            while (m--){
                int t; scanf ("%d", &t);
                t--;
    //            printf ("%d -> %d\n", j, t);
                Graph[j].push_back(t);
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                D[i][j] = i == j ? 1 : -1;
        bool ans = false;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (getD(i,j) >= 2){
                    ans = true;    
                    goto out;
                }
            
out:
        printf ("Case #%d: %s\n", w+1, ans ? "Yes" : "No");
    }
    return 0;
}
