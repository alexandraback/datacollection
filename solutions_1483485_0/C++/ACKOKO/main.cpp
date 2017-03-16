#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;


char table[27] = "yhesocvxduiglbkrztnwjpfmaq";
char s[110];
int N, len;


int main()
{
    scanf("%d", &N);
    getchar();
    for(int T = 1;T <= N;T++){
        printf("Case #%d: ", T);
        gets(s);
        len = strlen(s);
        for(int i = 0;i < len;i++){
            if(s[i] == ' '){
                printf(" ");
            }else{
                printf("%c", table[s[i]-'a']);
            }
        }
        printf("\n");
    }
    return 0;
}
