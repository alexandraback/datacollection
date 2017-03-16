#include<stdio.h>

int main()
{
    int soal,i,j,temp,gen,menang;
    double a,b,hasil;
    int kondisi;
    
    scanf("%i\n",&soal);
    for(i=1;i<=soal;i++)
    {
          gen=kondisi=menang=0;
          printf("Case #%i: ",i);
          scanf("%lf/",&a);
          scanf("%lf\n",&b);
          hasil=a/b;
          for(j=1;j<=40;j++)
          {
              hasil*=2;
              if(hasil-1>=0) {hasil-=1; if(hasil==0)menang=1; temp=j; kondisi+=1;}
              if(kondisi==1) {gen=temp; kondisi+=1;}
          }
          if(menang)
          {
              printf("%i\n",gen);
          }
          else printf("impossible\n");
    }
}
