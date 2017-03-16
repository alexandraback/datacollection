#include <iostream>
#include <math.h>
#include<stdio.h>

int main()
{

   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   int tcase,r,c,w,ccount,steps;

   std::cin>>tcase;
   ccount=0;

   while(tcase--)
   {
       std::cin>>r>>c>>w;

       if(c==w)
       {
           ccount++;
           std::cout<<"Case #"<<ccount<<": "<<c<<"\n";
       }
       else
       {
           /*if(w==1)
           {
                steps=c;
           }
           else if(w===2)
           {
                steps=ceil((double)c/(double)w)+1;
           }
           else if(w==3)
           {
                steps=ceil((double)c/(double)w)+2;
           }
           else if(w==3)
           {
                steps=ceil((double)c/(double)w)+2;
           }
           else if(w==3)
           {
                steps=ceil((double)c/(double)w)+2;
           } */
           steps=ceil((double)c/(double)w)+(w-1);
           ccount++;
           std::cout<<"Case #"<<ccount<<": "<<steps<<"\n";
       }

   }
   return 0;
}
