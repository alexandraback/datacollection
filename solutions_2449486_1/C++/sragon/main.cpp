#include<stdio.h>

using namespace std;

int mp[102][102];
int n, m;
bool check(int i, int j){
    int k;
    for(k=0; k<n; k++) if (mp[k][j] > mp[i][j]) break;
    if (k==n) return true;
    for(k=0; k<m; k++) if (mp[i][k] > mp[i][j]) break;
    if (k==m) return true;
    return false;
}

int cas, T;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);
    scanf("%d", &T);

    int i, j;
    bool ans;
    for(cas=1; cas <=T; cas++){
        scanf("%d%d", &n, &m);
        for(i=0; i<n; i++) for(j=0; j<m; j++) scanf("%d", &mp[i][j]);
        ans = true;
        for(i=0; (i<n) && ans; i++) for(j=0; j<m; j++) if (!check(i,j)){
            ans = false;
            break;
        }
        if (ans){
            printf("Case #%d: YES\n", cas);
        } else {
            printf("Case #%d: NO\n", cas);
        }
    }




    return 0;
}
