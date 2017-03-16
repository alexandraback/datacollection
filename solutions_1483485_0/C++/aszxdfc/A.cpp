#include<iostream>
#include<string>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
    freopen("A-small-attempt2.in","r",stdin);
    freopen("A.txt","w",stdout);
    int T,i,j;
    char s[10000],ch;
    int hash[30]={24,7,4,18,14,2,21,23,3,20,8,6,11,1,10,17,25,19,13,22,9,15,5,12,0,16};
    scanf("%d",&T);
    scanf("%c",&ch);
    for(i=1;i<=T;i++) {
        gets(s);
        printf("Case #%d: ",i);
        for(j=0;s[j]!='\0';j++) {
            if(s[j]>='a'&&s[j]<='z') printf("%c",hash[s[j]-'a']+'a');
            else printf("%c",s[j]);
        }
        putchar('\n');
    }
    return 0;
}
