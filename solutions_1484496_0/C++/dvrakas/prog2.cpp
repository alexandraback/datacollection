#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void f(int N, int array[],FILE *fp2)
{
             for (int aa=0;aa<pow(2,N);aa++)
                 for (int bb=0;bb<pow(2,N);bb++)
                 {
                     if (aa!=bb)
                     {
                         int mala = aa;
                         int suma=0;
                         int p=0;
                         while (mala!=0)
                         {
                               if (mala%2==1)
                                   suma+=array[p];
                               mala=mala/2;
                               p++;
                         }
                         int sumb=0;
                         int malb=bb;
                         p=0;
                         while (malb!=0)
                         {
                               if (malb%2==1)
                                   sumb+=array[p];
                               malb=malb/2;
                               p++;
                         }
                         if (suma==sumb)
                         {
                             
                         mala = aa;
                         p=0;
                         while (mala!=0)
                         {
                               if (mala%2==1)
                               {
                                   fprintf(fp2,"%d ",array[p]);
                                             
                                   printf("%d ",array[p]);
                               }
                               mala=mala/2;
                               p++;
                         }
                         fprintf(fp2,"\n");
                         printf ("\n");
                         
                         mala = bb;
                         p=0;
                         while (mala!=0)
                         {
                               if (mala%2==1)
                               {
                                                 fprintf(fp2,"%d ",array[p]);
                               
                                   printf("%d ",array[p]);
                               }
                               mala=mala/2;
                               p++;
                         }
                         fprintf(fp2,"\n");
                         printf ("\n");
                                        
                             printf ("win %d %d\n",aa,bb);
                             return;
                         }
                         
                     }
                 }
     
 }


main ()
{
     int c, p, N,i,j;
     int array[500];
     int a[500],b[500];
     int suma,sumb;
     int cases;
     int X;
     int NN,XX;
     FILE *fp, *fp2;
     
     fp = fopen ("C-small-attempt0.in","r");
     fp2 = fopen ("C-small-attempt0.out","w");
     
     if (fp==NULL || fp2==NULL)
     {
                  printf ("error reading file\n");
     }
     else
     {
         fscanf(fp,"%d",&cases);
         for (i=1;i<=cases;i++)
         {
             printf ("case %d\n",i);
             fprintf(fp2,"Case #%d:\n",i);

             fscanf (fp,"%d",&N);
             X=0;
             for (j=0;j<N;j++)
             {
                 fscanf (fp,"%d",&array[j]);
             }
             int win =0;
             f(N,array,fp2);               

             fprintf(fp2,"\n");             
         }
         fclose(fp);
         fclose (fp2);
     }     

}
