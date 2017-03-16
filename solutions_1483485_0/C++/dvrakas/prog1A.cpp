#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main ()
{
     int n,i,j;
     char map[26] ={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
     char s[1001];
     char o[1001];
     char temp[1001];
     int cases;
     char *w;
     
     FILE *fp, *fp2;
     
     fp = fopen ("A-small-attempt0.in","r");
     fp2 = fopen ("A-small-attempt0.out","w");
     
     if (fp==NULL || fp2==NULL)
     {
                  printf ("error reading file\n");
     }
     else
     {
         fscanf(fp,"%d ",&cases);
         
         for (i=1;i<=cases;i++)
         {
             fprintf(fp2,"Case #%d: ",i);             
             fgets(s,1001,fp);
             printf ("%s\n",s);
             for (j=0;j<strlen(s);j++)
             {
                 printf("%c[%d]->%c\n",s[j],s[j],map[s[j]-'a']);
                 if (s[j]==10)
                     continue;
                 if (s[j]==' ')
                     fprintf(fp2,"%c",' ');
                 else
                     fprintf(fp2,"%c",map[s[j]-'a']);                  
             }
             fprintf(fp2,"\n");
         }
         fclose(fp);
         fclose (fp2);
     }     
     system ("pause");
}
