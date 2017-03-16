#include<cstdio>
#include<cstring>

char s[110];

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        printf("Case #%d: ", i+1);
        scanf("%s", s);
        int ans = 0;
        while(1){
        if(s[0] == '-'){
            bool tt = false;
            ans++;
            for(int j=0;j<strlen(s);j++){
                if(s[j] == '-'){
                    s[j] = '+';
                }
                else{
                    break;
                }
            }
        }
        else if(s[0] == '+'){
            bool tt = false;
            ans++;
            for(int j=0;j<strlen(s);j++){
                if(s[j] == '+'){
                    s[j] = '-';
                    tt = true;
                }
                else{
                    tt = false;
                    break;
                }
            }
            if(tt){
                printf("%d\n", ans-1);
                break;
            }
        }
        }
    }
}
