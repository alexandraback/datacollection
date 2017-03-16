#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;
bool myfunc (char a, char b) {
    return a > b;
}

int main()
{
    int T,i,C,b,e;
    char S[1003];
    char Ans[2004];
    scanf("%d\n",&T);
    for(C=1; C<=T; C++) {
        gets(S);
        b = 1000;
        e = 1001;
        for (i=0;i<strlen(S);i++){
            if(i==0)
                Ans[b] = S[i];
            else if(S[i] >= Ans[b]){
                b--;
                Ans[b] = S[i];
            }
            else{
                Ans[e] = S[i];
                e++;
            }
        }
        printf("Case #%d: ",C);
        for(i=b;i<e;i++){
            printf("%c", Ans[i]);
        }
        printf("\n");
    }
    return 0;
}
