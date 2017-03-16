#include <stdio.h>
#include <string.h>

char s[1000];

int main(){
    int t;
    scanf("%d",&t);
    for(int tw = 1; tw <= t; tw++){
        scanf("%s",s);
        int l = strlen(s);
        int c = 0;
        while(1){
            if(s[0] == '+'){
                bool end = false;
                for(int i = 0; i < l; i++){
                    if(s[i] == '+'){
                        if(i == l - 1){
                            end = true;
                        }
                        else{
                            s[i] = '-';
                        }
                    }
                    else{
                        break;
                    }
                }
                if(end){
                    break;
                }
                c++;
            }
            int b;
            for(int i = l - 1; i >= 0; i--){
                if(s[i] == '-'){
                    b = i;
                    break;
                }
            }
            for(int i = 0; i <= b / 2; i++){
                char w1 = s[i] ^ '+' ^ '-';
                char w2 = s[b - i] ^ '+' ^ '-';
                s[i] = w2;
                s[b - i] = w1;
            }
            c++;
        }
        printf("Case #%d: %d\n", tw, c);
    }
}
