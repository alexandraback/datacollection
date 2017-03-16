#include <stdio.h>
#include <string.h>
int main()
{
    char a[] ="yhesocvxduiglbkrztnwjpfmaq";
    char str[200];
    int t, i, j, len;
    scanf("%d", &t);
    gets(str);
    for(i = 1; i <= t; i++)
    {
              gets(str);
              len = strlen(str);
              printf("Case #%d: ", i);
              for(j = 0; j < len; j++)
              {
                    if(str[j] != ' ')
                          printf("%c", a[str[j] - 'a']);
                    else 
                         printf(" "); 
              }
              printf("\n");
    }
    return 0;   
}
