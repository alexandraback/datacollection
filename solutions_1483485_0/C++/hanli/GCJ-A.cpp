#include<iostream>
#include<stdio.h>
char strup[25][105],strdown[25][105];
char code[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
char str[105];
using namespace std;
int main()
{
 	int n;
 	int i,j,len,casenum;
 	freopen("A-small-attempt.in","r",stdin);
    freopen("out.out","w",stdout);
 	scanf("%d",&n);
 	getchar();
 	char ch;
 	for(casenum=1;casenum<=n;casenum++)
 	{
        printf("Case #%d: ",casenum);
        while(1)
        {
            scanf("%s",&str);
            ch=getchar();
            len=strlen(str);
            for(i=0;i<len;i++)
                printf("%c",code[str[i]-'a']);
            printf("%c",ch);
            if(ch=='\n') break;
	     }
    }
    return 0;
}
