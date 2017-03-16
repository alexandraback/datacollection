/*
TASK: A
TASKNAME: Speaking in Tongues
LANG: C++
NOTE: Google Code jam 2012
*/
#include <cstdio>
char str[150];
char conv(char in){
    if(in == 'a')   return 'y';
    if(in == 'b')   return 'h';
    if(in == 'c')   return 'e';
    if(in == 'd')   return 's';
    if(in == 'e')   return 'o';
    if(in == 'f')   return 'c';
    if(in == 'g')   return 'v';
    if(in == 'h')   return 'x';
    if(in == 'i')   return 'd';
    if(in == 'j')   return 'u';
    if(in == 'k')   return 'i';
    if(in == 'l')   return 'g';
    if(in == 'm')   return 'l';
    if(in == 'n')   return 'b';
    if(in == 'o')   return 'k';
    if(in == 'p')   return 'r';
    if(in == 'q')   return 'z';
    if(in == 'r')   return 't';
    if(in == 's')   return 'n';
    if(in == 't')   return 'w';
    if(in == 'u')   return 'j';
    if(in == 'v')   return 'p';
    if(in == 'w')   return 'f';
    if(in == 'x')   return 'm';
    if(in == 'y')   return 'a';
    if(in == 'z')   return 'q';

    if(in == ' ')   return ' ';
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;  scanf("%d\n",&n);
    for(int i=1;i<=n;i++){
        gets(str);
        printf("Case #%d: ",i);
        for(int j=0;str[j]!=0;j++)  printf("%c",conv(str[j]));
        printf("\n");
    }
    return 0;
}

