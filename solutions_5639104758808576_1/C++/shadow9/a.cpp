#include<cstdio>

int main(){
    int T, S, cnt = 0;
    char str[1010];
    scanf("%d", &T);
    while(T--){
        scanf("%d%s", &S, str);
        int aud = 0;
        int ans = 0;
        for(int i = 0; i <= S; i++){
            int need = i;
            int invite = 0;
            if(aud < need) invite = need - aud;
            aud += invite + (str[i]-'0');
            ans += invite;
        }
        printf("Case #%d: %d\n", ++cnt, ans);
    }
    return 0;
}
