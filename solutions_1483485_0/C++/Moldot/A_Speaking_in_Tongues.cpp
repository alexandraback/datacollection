/*  Grader: Codejam - Qualification Round 2012
    A Speaking in Tongues
    Varot Premtoon 14 Apr 2555 */

#include <cstdio>

char map[] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

int sol(int cse)
{
    int i;
    char text[1000];
    gets(text);
    if(cse==0) return 0;
    printf("Case #%d: ",cse);
    for(i=0;text[i]!='\0';i++) {
        if(text[i]==' ') printf(" ");
        else printf("%c",map[text[i]-97]);
    }
    printf("\n");
    return 0;
}


int main()
{
    int t,i;
    scanf("%d",&t);
    //fflush(stdin);
    for(i=0;i<=t;i++) sol(i);
    return 0;
}
