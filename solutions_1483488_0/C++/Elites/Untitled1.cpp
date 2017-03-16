#include <fstream>
#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <math.h>

using namespace std;

int f(int i, int l)
{
int tmp1,tmp2,x;
tmp1=i%10;
i=i/10;
for(x=0,tmp2=1;x<l-1;x++) tmp2*=10;
i+=tmp2*tmp1;
return i;
}

int main ()
{
     int x,tem,cas=0,i,j,l,t,tmp,c=0;
     ifstream file("C:/Users/Rahul/Desktop/C-small-attempt0.in");
     ofstream ofile("C:/Users/Rahul/Desktop/output.txt");
     file>>tem;
     //file.get(ch);
     while(cas++!=tem)
     {
               file>>i>>j;
               t=i;
               c=0;
               for(l=0;t!=0;l++) t/=10;
               for(t=i;t<=j;t++)
               {
                                
                                {
                                          
                                           tmp=t;
                                           do                                          
                                           {
                                                    
                                                    t=f(t,l);
                                                    
                                                    if(t>=i&&t<=j&&t!=tmp) 
                                                    {
                                                                   
                                                                    
                                                                    c++;
                                                    }
                                           }while(t!=tmp);
                                }
                              
               }     
               
                ofile<<"Case #"<<cas<<": "<<c/2<<endl;               
     }
     file.close();
     ofile.close();
     //system("pause");
     return 0;
}
