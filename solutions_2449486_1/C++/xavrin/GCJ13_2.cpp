#include <cstdio>
#include <utility>
#include <queue>
#include <set>
#include <list>
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> VI;
typedef long long LL;
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define FORD(x, b, e) for(int x=b; x>=(e); ––x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define VAR(v,n) typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define SIZE(x) (int)x.size()
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define MP make_pair
#define PII pair<int, int>

int tab[100][100];
bool visited[100][100];

int findRow (int i, int n, int m){
    int max = -1;
    for (int j = 0; j < m; j++)
        if (tab[i][j] > max)
            max = tab[i][j];
    return max;
}

int findCol (int i, int n, int m){
    int max = -1;
    for (int j = 0; j < n; j++)
        if (tab[j][i] > max)
            max = tab[j][i];
    return max;
}

void movRow (int val, int i , int n, int m){
    for (int j = 0; j < m; j++)
        if (tab[i][j] == val)
            visited[i][j] = true;
}

void movCol (int val, int i , int n, int m){
    for (int j = 0; j < n; j++)
        if (tab[j][i] == val)
            visited[j][i] = true;
}
int main(){
    int T;
    scanf("%d", &T);
    for (int k = 1; k <= T; k++){
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d", &tab[i][j]), visited[i][j] = false;
        int max;
        for (int i = 0; i < n; i++){
            max = findRow(i, n, m);
            // printf("Wiersz %d max %d", i, max);
            movRow(max, i, n, m);
        }
        for (int i = 0; i < m; i++){
            max = findCol(i,n,m);
            // printf("Kolumna %d max %d", i, max);
            movCol(max, i, n, m);
        }
        bool wyn = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!visited[i][j])
                    wyn = false;
        printf("Case #%d: ", k);
        if (wyn) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
