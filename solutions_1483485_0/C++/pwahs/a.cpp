#include<cstdio>
//////////////abcdefghijklmnopqrstuvwxyz
char encode[27]="yhesocvxduiglbkrztnwjpfmaq";

int main(){
    int N;
    scanf("%d\n",&N);
    for(int i=1;i<=N;i++){
        char c=0;
        printf("Case #%d: ",i);
        while (c!='\n'){
            c=getchar();
            if (c>='a' && c<='z') putchar(encode[c-'a']);
            else putchar(c);
        }
    }
    return 0;
}
