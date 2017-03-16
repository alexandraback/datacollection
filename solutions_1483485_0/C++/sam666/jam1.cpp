/*
 Qualification Round 2012 : Problem A. Speaking in Tongues
*/

#include <iostream>
#include <stdio.h>

using namespace std;

char tab[] = {
    'y','h','e','s','o','c','v','x','d','u','i','g',
    'l','b','k','r','z','t','n','w','j','p','f','m',
    'a','q'
    
};

int main()
{
    int T;
    char inp[101];
    scanf("%d\n",&T);
    for (int i=0; i<T; i++) {
        scanf("%[^\n]\n",inp);
        //cout << inp <<endl;
        printf("Case #%d: ",i+1);
        char *p=inp;
        while (*p) {
            if(*p != ' ')
                printf("%c",tab[*p-'a']);
            else
                printf("%c",*p);
            p++;
        }
        printf("\n");
    }
    return 0;
}