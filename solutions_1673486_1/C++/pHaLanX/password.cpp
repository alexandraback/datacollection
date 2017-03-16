#include <fstream>
#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

int main()
{
      int B;
      long A,T;//B = no. of test case, T =total length
      double p[100000],ans[100000],min,gprod,prod,p_error;    
      ifstream fin("input.in");
      ofstream fout("output.out");
      fin>>B;
      for(int i=0;i<B;i++)
      {
           fin>>A>>T;
           gprod=1;
           for(int j=0;j<A;j++)
           {
             fin>>p[j];
             gprod *=p[j];
           }
           for(int k=1;k<A;k++)
           {
                prod=1;
                for(int h=0;h<A-k;h++)
                   prod *=p[h];        
                p_error=1-prod;
                ans[k]=prod*(k+k+T+1-A) + p_error*(k+k+T+1-A+T+1);
           }    
           ans[0]=gprod*(T+1-A) + (1-gprod)*(T+1-A+T+1);
           ans[A]=1+T+1;
           min=ans[0];
           for(int q=1;q<=A;q++)
                if(min>ans[q])
                   min=ans[q];

           fout<<"Case #"<<i+1<<": "<<fixed<<setprecision(6)<<min<<endl;                         
      }
      cout<<"completed";
      getch();    
}
