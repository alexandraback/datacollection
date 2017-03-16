#include <cstdio>
#include <cstdlib>
#include <ctime>

int fail[1000];
char s1[1000];
char s2[1000];
double dp2[1000];
double dp[1000];

void build_failure(char s[], int M){
    //fail[k] = x; 會對應前x個字母
    fail[1] = 0; //第一個字母只能吃土 

    for(int i=2;i<=M;i++){ //建立[0 ~ i-1]的fail邊
        
        int j=fail[i-1];   //[0 ~ i-2]的fail邊
        
        while(j>0 && s[j]!=s[i-1]) //前j個字母(0~j-1) + (j == 第i個字母)
            j = fail[j];

        if(s[j]==s[i-1]) j++; // 第j+1個加入匹配
        fail[i] = j; //0~j-1 匹配成功
    }
}

int main(){
    int T;
    scanf("%d", &T);
    for(int case_t=1 ; case_t<=T ; case_t++){
        double res = 0;
        double bring = 0;
        int keys, len, L;
        scanf("%d %d %d", &keys, &len, &L);
        scanf("%s %s", s1, s2);
        
        bool FLAG = true;
        for(int i=0;i<len;i++){
            bool flag = false;
            for(int j=0;j<keys;j++){
                if(s2[i]==s1[j])
                    flag = true;
            }if(!flag) FLAG = false;
        }if(!FLAG){
            printf("Case #%d: %d\n", case_t, 0);
            continue;
        }

        build_failure(s2, L);
        bring = 0;
        if(len<=L){
            bring += 1;
            bring+=(L-len) / (len-fail[len]);
        }

        for(int i=0;i<=len;i++) dp[i] = 0;
        dp[0] = 1;
        
        while(L--){
            for(int i=0;i<=len;i++) dp2[i] = 0;
            for(int i=0;i<keys;i++){
                for(int pos=0;pos<len;pos++){
                    int j = pos;
                    while(j && s1[i] != s2[j]) j = fail[j];
                    if(s1[i] == s2[j]) j++;
                    if(j==len){
                        j = fail[j];
                        res+=dp[pos]/(double)keys;
                    }
                    dp2[j] += dp[pos]/(double)keys;
                }
            }
            for(int i=0;i<=len;i++) dp[i] = dp2[i];
        }
        printf("Case #%d: %.9lf\n", case_t, bring-res);
    }
    return 0;
}