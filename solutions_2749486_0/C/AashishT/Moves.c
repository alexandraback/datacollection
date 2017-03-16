#include<stdio.h>



int main(int argc, char **argv)
{
   int T, Tcp, X, Y, count ,x, y;
   FILE *fp = fopen(argv[1],"r"); 
   fscanf(fp,"%d\n",&T);
   Tcp = T;

   while(T--)
   {
     count = 1;
     fscanf(fp,"%d %d",&X,&Y);
     x = 0; y = 0;
     printf("Case #%d: ", Tcp -T);
     if ( X < 0 )
     {
       while(x != X )
       {
         count++;
         printf("EW");
         x--;
       }
     }
     else
     {
       while(x != X )
       {
         count++;
         printf("WE");
         x++;
       }
     }
     if ( Y < 0 )
     {
       while(y != Y )
       {
         count++;
         printf("NS");
         y--;
       }
     }
     else
     {
       while(y != Y )
       {
         count++;
         printf("SN");
         y++;
       }
     }
     printf("\n");
   }
}
