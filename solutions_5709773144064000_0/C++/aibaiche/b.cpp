#include <cstdio>
#include <fstream>
#include <iostream>
#define debug
#define _max 4
using namespace std;
FILE *fin,*fout = NULL;
double times,rate,cookie,nt;

                                          
             
int main(){

    
    fout= fopen("out.txt","w");
    fin = fopen("A-small.in","r");
    int t;
    double c,f,x;
    fscanf(fin,"%d",&t);

    for(int k=1;k<=t;k++){
      fscanf(fin,"%lf%lf%lf",&c,&f,&x);
      times = 0.0;
      rate=2.0;
      cookie=0.0;
      
       while(true){
           if( x*(rate+f) > c*(rate+f) + x* rate ){// buy 
               times += c/rate;
               rate += f;
           }else{// not by
               times += x/rate;
               break;
           }
       }
       fprintf(fout,"Case #%d: %.7lf\n",k,times);
    }
    fclose(fin);
    fclose(fout);
    system("pause");
    return 0;
}
