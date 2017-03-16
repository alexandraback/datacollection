#include <cstdio>

char map[]="yhesocvxduiglbkrztnwjpfmaq";

int main(){
    int n;
    scanf("%d\n" ,&n);
    for(int i = 1; i <= n; i++){
        char c;
        printf("Case #%d: " ,i);
        while((c = getchar()) != '\n'){
            if(c >= 'a' && c <= 'z') putchar(map[c - 'a']);
            else putchar(c);
        }
        putchar('\n');
    }
}
