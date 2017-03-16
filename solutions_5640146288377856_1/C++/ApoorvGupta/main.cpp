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


           steps=(ceil((double)c/(double)w)+(w-1))+((r-1)*((int)c/(int)w));
           ccount++;
           std::cout<<"Case #"<<ccount<<": "<<steps<<"\n";


   }
   return 0;
}
