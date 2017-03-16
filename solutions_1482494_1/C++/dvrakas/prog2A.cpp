#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main ()
{
     int N,i,j;
     int A,B;
     int star [1000][2];
     int comp[1000][2];
 //    int compl[1000][2]; 
     int cases;
     int out;
     char *w;
     float ks,min;
     double pall;
     int stars;
     FILE *fp, *fp2;
     
     fp = fopen ("B-large.in","r");
     fp2 = fopen ("B-large.out","w");
     
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
  
             printf("Case %d\n",i);   

             fscanf (fp,"%d",&N);
             for (j=0;j<N;j++)
             {
                 fscanf (fp,"%d %d",&star[j][0],&star[j][1]);
                 comp[j][0]=comp[j][1]=0;
             }             
             
             stars=0;
             
             int splus;
             out=0;
             int tries=0;
             while (out<N)
             {
                   splus=0;
                   for (int k=0;k<N;k++)
                   {
                       if ((star[k][1] <= stars) && (comp[k][1]==0))
                       {
                           stars+=comp[k][0]==0?2:1;
                           comp[k][1]=1;
                           out++;
                           splus=1;
                           tries++;
                         //  printf ("2\n");
                           break;
                       }
                   }
                   if (splus==0)
                   {
                       int max=-1;         
                       for (int k=0;k<N;k++)
                       {
                           if ((star[k][0] <= stars) && (comp[k][0]==0) && (comp[k][1]==0))
                           {
                               if (max==-1) 
                                   max =k;
                               else 
                                   if (star[k][1]>star[max][1])
                                       max =k;
                           }
                       }
                     //  printf ("%d\n",max);
                       if (max!=-1)
                       {   
                               stars+=1;             
                               splus=1;
                           //    printf ("1\n");
                               tries++;
                               comp[max][0]=1;
                               //break;
                       }   
                                                       
                   }
                   
                   
                   
                   if (splus==0)
                   {
                       break;         
                   }
             }
             
             if (out==N)
             {
                 fprintf(fp2,"%d\n",tries);
                 printf("%d\n",tries);
             
             }
             else
             {
                 fprintf(fp2,"Too Bad\n");
                 printf("Too Bad\n");
             }
         }
         fclose(fp);
         fclose (fp2);
     }     
     system ("pause");
}
