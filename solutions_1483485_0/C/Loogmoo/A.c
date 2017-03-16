#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
    char ins[101],map[]="yhesocvxduiglbkrztnwjpfmaq";
    int n,i,j,l;

    scanf("%d\n",&n);
    //fflush(stdin);

    for(i=1;i<=n;i++)
    {
        //scanf("%[^\n]\n",ins);
        //scanf("%[\n]",ins);
        gets(ins);
        l=strlen(ins);
        printf("Case #%d: ",i);
        for(j=0;j<l;j++)
        {
            if(ins[j]==' ')
                printf(" ");
            else
                printf("%c",map[ins[j]-'a']);
        }
        printf("\n");
    }

    return 0;
}
