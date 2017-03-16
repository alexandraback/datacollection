#include<stdio.h>
char mapping[50];
main(){
    freopen("pA.txt","r",stdin);
    freopen("out.txt","w",stdout);
mapping[0]='y';
mapping[1]='h';
mapping[2]='e';
mapping[3]='s';
mapping[4]='o';
mapping[5]='c';
mapping[6]='v';
mapping[7]='x';
mapping[8]='d';
mapping[9]='u';
mapping[10]='i';
mapping[11]='g';
mapping[12]='l';
mapping[13]='b';
mapping[14]='k';
mapping[15]='r';
mapping[16]='z';
mapping[17]='t';
mapping[18]='n';
mapping[19]='w';
mapping[20]='j';
mapping[21]='p';
mapping[22]='f';
mapping[23]='m';
mapping[24]='a';
mapping[25]='q';
    int n;
    scanf("%d",&n);
    char w;
    scanf("%c",&w);
    for(int k=0;k<n;k++){
        printf("Case #%d: ",k+1);
        char s[200];
        gets(s);
        for(int i=0;s[i]!=0;i++){
            if(s[i]!=' '){
                printf("%c",mapping[s[i]-'a']);
                }
            else{
                printf(" ");
                }
            }
        printf("\n");
        }
    }














