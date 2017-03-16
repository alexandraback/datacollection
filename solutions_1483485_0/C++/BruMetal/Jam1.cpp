#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <fstream>


using namespace std;
char in[1001];
char trans[123];
ofstream myfile;



int main(){
    int n;
    char c;
    myfile.open ("testeJam1.txt");
    trans['a']='y';
    trans['b']='h';
    trans['c']='e';
    trans['d']='s';
    trans['e']='o';
    trans['f']='c';
    trans['g']='v';
    trans['h']='x';
    trans['i']='d';
    trans['j']='u';
    trans['k']='i';
    trans['l']='g';
    trans['m']='l';
    trans['n']='b';
    trans['o']='k';
    trans['p']='r';
    trans['q']='z';
    trans['r']='t';
    trans['s']='n';
    trans['t']='w';
    trans['u']='j';
    trans['v']='p';
    trans['w']='f';
    trans['x']='m';
    trans['y']='a';
    trans['z']='q';
    
    
    
    scanf("%d%c",&n,&c);
    
    for(int t=1;t<=n;t++)
    {

               int fim=0;
               scanf("%c",&c);
               while(c!='\n')
               {
                       in[fim++]=c;      
                       scanf("%c",&c); 
    
               }
               fim;
               myfile << "Case #" << t << ": ";     
               for(int i=0;i<fim;i++)
               {
                       if(in[i]>=97 && in[i]<=122)
                       {
                                   myfile << trans[in[i]];

                       }
                       else myfile <<  in[i];
               }

                myfile << "\n"; 
               
    }
    return 0;
}
