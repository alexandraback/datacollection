#include <stdio.h>

int main(void)
{
    // ‰ğÍŒ‹‰Ê
    int map[1000] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q',};
    int T;
    scanf("%d\n",&T);
    for(int r = 0;r < T;++r){
        char line[1024];
        fgets(line,1023,stdin);
        int i = 0;
        printf("Case #%d: ",r+1);
        while( line[i] ){
            char c = line[i];
            if( 'a' <= c && c <= 'z' ){
                c = map[c - 'a'];
            }
            printf("%c",c);
            ++i;
        }
        //printf("\n");
    }
    return 0;

}