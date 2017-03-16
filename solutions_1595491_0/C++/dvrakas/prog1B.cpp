#include <stdio.h>
#include <stdlib.h>

main ()
{
     int N,S,p;
     int i,j;
     int cases;
     int t1,t2;
     int scores[100];
     int sures,maybes;
     int total;
     FILE *fp, *fp2;
     
     fp = fopen ("B-small-attempt0.in","r");
     fp2 = fopen ("B-small-attempt0.out","w");
     
     if (fp==NULL || fp2==NULL)
     {
                  printf ("error reading file\n");
     }
     else
     {
         fscanf(fp,"%d",&cases);
         for (i=1;i<=cases;i++)
         {
             sures=maybes=0;
             printf ("case %d\n",i);
             fscanf (fp,"%d %d %d",&N, &S, &p);
             for (j=0;j<N;j++)
             {
                 fscanf (fp,"%d",&scores[j]);
                 
                 printf ("S=%d p=%d num=%d :",S,p,scores[j]);
                 if (p>=1)
                     t1=3*p-2;
                 else
                     t1=0;
                 if (p>=2)      
                     t2=3*p-4;
                 else
                     if (p==1)
                         t2=1;
                     if (p==0)
                         t2=0;        
                 if (scores[j]>=t1)
                 {
                     sures++;
                     printf("sure\n");
                 }
                 else
                     if (scores[j]>=t2)
                     {
                         maybes++;
                         printf("maybe\n");
                     }                      
             }   
             if (maybes>=S)
                 total=S+sures;
             else
                 total=maybes+sures;
             fprintf(fp2,"Case #%d: %d\n",i,total);
         }
         fclose(fp);
         fclose (fp2);
     }
     system("pause");     
}
