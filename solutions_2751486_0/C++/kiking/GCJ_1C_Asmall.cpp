#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T, n, len, ans =0;
char s[10];
bool con(char c){
     if((c == 'a')||(c == 'o')||
        (c == 'e')||(c == 'u')||
        (c == 'i')) return false;
     return true;
}
int main(){
    freopen("GCJ_1C_Asmall.in","r",stdin);
    freopen("GCJ_1C_Asmall.out","w",stdout);
    scanf("%d",&T);
    for (int i = 0; i < T; i++){
        scanf("%s%d",s,&n);
        len = strlen(s);
        ans = 0;
        for (int j = 0; j < len; j++){
            for (int k = j+n-1; k < len; k++){
                bool ck = 1; int ct = 0, m = 0;
                for (int l = j; l <= k; l++){
                    if (!con(s[l])) ct = 0;
                    else ct++;
                    m = max(m, ct);
                }
                if (m >= n) ans++;
            }
        }
        printf("Case #%d: %d\n",i+1,ans);
    }
    

    return 0;
}
