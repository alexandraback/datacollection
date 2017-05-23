#include <stdio.h>
int main(){
   int casos, i=0, j;
   double C, F, X, t, t2, cf, suma;
   scanf("%d\n",&casos);
   while (i++ != casos)
   {
      scanf("%lf %lf %lf",&C,&F,&X);
      // ejemplo de impresion con 10 decimales: printf("%.10f %.10f %.10f\n",C,F,X);
      t = X/2;
      suma = 0;
      cf = 1;
      suma = suma + (C/(F*(cf-1) + 2));
      t2 = (X/((cf*F)+2))+suma;
      while(t2 < t){
         t = t2;
         cf++;
         suma = suma + (C/(F*(cf-1) + 2));
         t2 = (X/((cf*F)+2))+suma;
      }
      printf("Case #%d: %.10f\n",i,t); 
   }
}