#include <cstdio>
#include <cstring>

using namespace std;

bool consonent(const char c){
    return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}

int main(){
    char str[1000002];
    bool hasN[1000002];
    int t;
    scanf("%d", &t);
    int n;
    int ca = 1;
    while(t--){
        scanf("%s %d", str, &n);
        int l = strlen(str);
        memset(hasN, 0, sizeof(bool) * l);
        int st = 0;
        while(1){
            while(st < l && !consonent(str[st])){
                st++;
            }
            if(st >= l)break;
            int ed = st;
            while(ed < l && consonent(str[ed])){
                ed++;
            }
            if(ed - st >= n){
                for(int i = st; i <= ed - n; i++){
                    hasN[i] = true;
                }
            }
            st = ed;
        }
        long long ans = 0, notst = 0;
        for(int i = 0; i < l; i++){
            if(hasN[i]){
                ans += (l - i - n + 1) * (notst + 1);
                notst = 0;
            }else{
                notst++;
            }
        }
        printf("Case #%d: %lld\n", ca++, ans);
    }
    return 0;
}