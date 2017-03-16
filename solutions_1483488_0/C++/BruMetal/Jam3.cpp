#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <fstream>


using namespace std;
ofstream myfile;
int agora;
int usado[2000001];

int reciclado(int a, int b, int len)
{
     int numero2;
     int vals=0;
     for(int vez=10; vez<len;vez*=10)
     {
             numero2=(a%vez)*(len/vez)+a/vez;
             if(numero2>a && numero2 <=b && usado[numero2]!=a*100+agora){
                           usado[numero2]=a*100+agora;
                           //printf("%d %d\n",a,numero2);
                           vals++;
             }
     }
     
     
     
     return vals;
}

int main(){
    int n,x,y,resp;
    myfile.open ("testeJam3.txt");
    
    scanf("%d",&n);
    
    for(int t=1;t<=n;t++)
    {
               agora=t;
               resp=0;
               scanf("%d%d",&x,&y);
               int tam=1;
               for(int nun=10;x>=nun;nun*=10,tam=nun) ;
               for(int k=x;k<y;k++)
                       resp+=reciclado(k,y,tam);
               myfile << "Case #" << t << ": " << resp << "\n";     
               
    }
    return 0;
}
