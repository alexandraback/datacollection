#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

const int maxn = 105;
const int mod = 1000000007;
char str[maxn][maxn], sing[maxn][maxn];
int n, m, k, q[maxn], cnt, top, next[maxn], stack[maxn], oc[maxn], lett[maxn];
bool used[maxn];
vector<int> pos[30];
bool check(){
     int now = 0;
     for (int i = 0; i < 26; i ++) pos[i].clear();
     for (int i = 1; i <= m; i ++){
         int j = stack[i], l = strlen(str[j]);
         for (int z = 0; z < l; z ++)
             pos[str[j][z] - 'a'].push_back(++now);//, printf("%c",str[j][z]);
     }
    // printf("\n");
     for (int c = 0; c < 26; c ++){
         for (int i = 0; i + 1< pos[c].size(); i ++)
            if (pos[c][i] + 1 != pos[c][i + 1]) return false;
     }
     
     return true;
}
int solve(){
    scanf("%d",&n);
    m = 0, k = 0;
    static char st[maxn];
    for (int i = 1; i <= n; i ++){
        scanf("%s",st);
        char c = st[0];
        int len = strlen(st);
        bool single = true;
        for (int j = 0; j < len; j ++)
           if (st[j] != c) single = false;
        if (!single)
            ++ m, memcpy(str[m], st, sizeof(st));
        else ++ k, memcpy(sing[k], st, sizeof(st));
    }
    
    cnt = 0, top = 0;
    memset(next, 0, sizeof(next));
    for (int i = 1; i <= m; i ++){
       int l = strlen(str[i]);
       for (int j = 1; j <= m; j ++)
          if (i != j && str[i][l - 1] == str[j][0]) next[i] = j;
    }
    
    memset(used, true, sizeof(used));
    int tl = 0;
    for (int i = 1; i <= m; i ++)
        used[next[i]] = false;
    for (int i = 1; i <= m; i ++)
        if (used[i]) q[++ tl] = i;
    memset(used, false, sizeof(used));
    for (int i = 1; i <= tl; i ++){
        int j = q[i];
        while (j && !used[j])
            stack[++ top] = j, used[j] = true, j = next[j];
    }
    if (top < m || !check()) return 0;
    cnt = tl;  
    
    memset(lett, 0, sizeof(lett));
    for (int i = 1; i <= m; i ++){
        int len = strlen(str[i]), j, z;
        lett[str[i][0]-'a'] = 1;
        for (j = 0; j < len && str[i][j] == str[i][0]; j ++);
        lett[str[i][len-1]-'a'] = 1;
        for (z = len - 1; z >= 0 && str[i][z] == str[i][len-1]; z --);
        for (int t = j; t <= z; t ++)
            lett[str[i][t]-'a'] = 2;
    }
    
    memset(oc, 0, sizeof(oc));
    for (int i = 1; i <= k; i ++){
        char c = sing[i][0];
        oc[c-'a'] ++;
    }
   // for (int i = 0; i < 26; i ++) 
   //    if (lett[i] || oc[i]) printf("char c=%c, lett=%d, oc=%d\n",i+'a',lett[i],oc[i]);
    int  ans = 1;
    static int fac[105];
    fac[0]=1;
    for (int i = 1; i <= 100; i ++)
      fac[i] = (1ll * fac[i-1] * i) % mod;
    for (int i = 0; i < 26; i ++)
        if (oc[i] > 0){
           if (lett[i] == 2) return 0;
           if (lett[i] == 0) cnt ++;
           ans = (1ll * ans * fac[oc[i]]) % mod;
        }
    ans = (1ll * ans * fac[cnt]) % mod;
    return ans;
    
}
int main(){
    freopen("bb.in","r",stdin);
    freopen("b.out","w",stdout);
    int tst;
    scanf("%d",&tst);
    for (int i = 1; i <= tst;  i ++)
       printf("Case #%d: %d\n",i,solve());
    return 0;
}
