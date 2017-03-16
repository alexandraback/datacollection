#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main ()
{
     int n,i,j;
     int A,B;
     float p[100000];
     int cases;
     char *w;
     float ks,min;
     double pall;
     
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
             fscanf (fp,"%d %d",&A,&B);
             for (j=0;j<A;j++)
                 fscanf (fp,"%f",&p[j]);

             min=2+B;
             
             for (int k=0;k<=A;k++)
             {
                 pall=1;
                 for (j=0;j<A-k;j++)
                     pall*=p[j];    
                 ks = (B-A+1+2*k)*pall + (1-pall)*(1+B+B-A+1+2*k);
                 if (ks<min)
                 {
                         //   printf ("min = %f from %d\n",ks,k);
                     min=ks;
                 }
             }
             fprintf (fp2,"%f\n",min);
          //   printf ("case %d: min = %f\n",i,min); 
         }
         fclose(fp);
         fclose (fp2);
     }     
     system ("pause");
}
