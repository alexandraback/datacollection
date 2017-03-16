#include<stdio.h>
char to[128];
bool used[128];
char s1[3][200]={
"ejp mysljylc kd kxveddknmc re jsicpdrysi",
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
"de kr kd eoya kw aej tysr re ujdr lkgc jv"};
char s2[3][200]={"our language is impossible to understand",
"there are twenty six factorial possibilities",
"so it is okay if you want to just give up"};
    
int main(){
    int i,j,T,cs=0;
    char s[128];
    for(i=0;i<3;i++){
        for(j=0;s1[i][j];j++)to[s1[i][j]]=s2[i][j];
    }
    to['z']='q';
    to['q']='z';
    scanf("%d",&T);
    gets(s);
    while(T--){
        gets(s);
        printf("Case #%d: ",++cs);
        for(i=0;s[i];i++)printf("%c",to[s[i]]);
        puts("");
    }
    return 0;
}
