#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int nd(int A)
{
    int n=0;
    while (A>0)
    {
        A=A/10;
        n++;
    }
    return n;
}
int dig(int n,int i)
{
     n=n/pow(10,i);
     return n%10;
}
int rot(int A, int n)
{
    int i;
    int ND;
    char s[10],s2[10];
    ND = nd(A);
    sprintf (s,"%d",A);
    for (i=0;i<ND-n;i++)
        s2[i]=s[i+n];
    for (i=ND-n;i<ND;i++)
        s2[i]=s[i-(ND-n)];
    s2[i]='\0';
    return atoi(s2);
}
int recycled (int A, int B)
{
    int start;
    int C;
    for (int i=1;i<nd(B);i++)
    {
        if (dig(A,0)==dig(B,i))
        {
             C = rot(A,i);
             if (C==B)
                 return 1;                         
        }
    }
    return 0;
}
int check(int n, int closed[], int num)
{
    int i;
    for (i=0;i<num;i++)
        if (closed[i]==n)
            return 0;
    return 1;
}
main ()
{
     int cases,A,B,i,j,n,m;
     int closed[10];
     int pos;
     int D;
     FILE *fp, *fp2;
     int  recycled; 
     fp = fopen ("C-small-attempt0.in","r");
     fp2 = fopen ("C-small-attempt0.out","w");
     
     
     printf ("%d %d\n",rot(12,0),rot(12,1));
     
     if (fp==NULL || fp2==NULL)
     {
                  printf ("error reading file\n");
     }
     else
     {
         fscanf(fp,"%d",&cases);
         for (i=1;i<=cases;i++)
         {
             recycled=0;
             printf ("case %d\n",i);
             fscanf (fp,"%d %d",&A, &B);
             for (n=A;n<B;n++)
             {
                 for (int k=0;k<10;k++)
                      closed[k]=-1;
                 pos=0;
                 //printf("testing %d: ",n);
                  D=nd(n);
                  for (j=1;j<D;j++)
                  {
                      m = rot(n,j);
                //      printf ("%d..",m);
                      if (m>n && m<=B)
                      {
                              printf("%d %d\n",n,m);
                          if (check(m,closed,pos)==1)
                          {
                              recycled++;
                              closed[pos]=m;
                              pos++;
                          }
                      }
//                      else
             //         printf("fail");
                  } 
               //   printf("\n");     
             }
             //printf("\n");
    //         system("pause");
             fprintf(fp2,"Case #%d: %d\n",i,recycled);
         }
         fclose(fp);
         fclose (fp2);
     }
     system("pause");     
}
