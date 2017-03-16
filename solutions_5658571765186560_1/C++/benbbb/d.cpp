#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
   freopen("D-large.in","r",stdin);
   freopen("D-large.out","w",stdout);
   int ca,T,X,R,C;
   cin>>T;
   for (ca=1;ca<=T;ca++)
   {
       cin>>X>>R>>C;
       if (X>=7) {printf("Case #%d: RICHARD\n",ca);continue;}
       if (X==1) {printf("Case #%d: GABRIEL\n",ca);continue;}
       if (X==2) {if (C*R%X!=0)   printf("Case #%d: RICHARD\n",ca);
                            else  printf("Case #%d: GABRIEL\n",ca);
                  continue;}
       if (X==3) {if (C*R%X!=0||(C<2||R<2))   printf("Case #%d: RICHARD\n",ca);
                            else  printf("Case #%d: GABRIEL\n",ca);
                  continue;}
       if (X==4) {if (C*R%X!=0||(C<2||R<2||(C*R<=8)))   printf("Case #%d: RICHARD\n",ca);
                            else  printf("Case #%d: GABRIEL\n",ca);
                  continue;}
       if (X==5) {if (C*R%X!=0||(C<3||R<3||(C*R<15)))   printf("Case #%d: RICHARD\n",ca);
                            else  printf("Case #%d: GABRIEL\n",ca);
                  continue;}
       if (X==6) {if (C*R%X!=0||(C<3||R<3||(C*R<24)))   printf("Case #%d: RICHARD\n",ca);
                            else  printf("Case #%d: GABRIEL\n",ca);
                  continue;}


   }

   fclose(stdin);
   fclose(stdout);

    return 0;
}
