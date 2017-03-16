#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <fstream>


using namespace std;
ofstream myfile;



int main(){
    int n,g,s,p,total,resp;
    myfile.open ("testeJam2.txt");
    
    scanf("%d",&n);
    
    for(int t=1;t<=n;t++)
    {

               resp=0;
               scanf("%d%d%d",&g,&s,&p);
               
               for(int i=0;i<g;i++)
               {
                     scanf("%d",&total);
                     int temp=total;
                     total=total-(total/3);
                     bool test= total%2==0;
                     total=(total+1)/2;
                     if(total>=p) resp++;
                     else if(s>0 && test && temp>=2 && total+1>=p)
                     {
                          s--;
                          resp++;
                      }  
               }
               myfile << "Case #" << t << ": " << resp << "\n";     
               
    }
    return 0;
}
