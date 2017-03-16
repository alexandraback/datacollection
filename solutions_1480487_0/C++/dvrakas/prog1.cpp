#include <stdio.h>
#include <stdlib.h>

main ()
{
     int c, p, N,i,j;
     int array[200], done[200];
     int cases,a,b;
     int X;
     int NN,XX;
     FILE *fp, *fp2;
     
     fp = fopen ("A-small-attempt4.in","r");
     fp2 = fopen ("A-small-attempt4.out","w");
     
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
             fprintf(fp2,"Case #%d:",i);

             fscanf (fp,"%d",&N);
             X=0;
             for (j=0;j<N;j++)
             {
                 fscanf (fp,"%d",&array[j]);
                 X+=array[j];
                 printf ("%d ",array[j]);
             }
             printf ("\n");
             double same2 = (double)2*X/N;
             double same =same2;
             NN=N;
             XX=X;
             for (int mal=0;mal<N;mal++)
                 done[mal]=0;
             int repeat=0;
             do
             {
               repeat=0;  
               same = (double) (X+XX)/NN;
               printf ("same = %lf\n",same);
               for (j=0;j<N;j++)
               {
                   if (array[j]>same && done[j]==0)
                   {
                       done[j]=1;
                       repeat=1;              
                       NN--;
                       XX-=array[j];
                   }
               }
             }
             while (repeat==1);
             //double same= (double)(X+XX)/NN;
             printf ("X = %d N=%d XX=%d NN=%d same = %lf  same2=  %lf\n",X,N,XX,NN,same,same2);
             for (j=0;j<N;j++)
             {   
                 double min;
                 min = (same-array[j])/(double) X;
                 if (array[j]>same)
                     fprintf(fp2," 0");
                 else
                     fprintf(fp2," %lf",min*100);
             }
             fprintf(fp2,"\n");             
         }
         fclose(fp);
         fclose (fp2);
     }     
     getchar();
}
