#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream in ("B-large.in");
    ofstream out ("output.txt");
    int t,n_g,n_s,p,score,ris;
    in>>t;
    for(int j=0;j<t;j++)
    {
         in>>n_g;
         in>>n_s;
         in>>p;
         ris=0;
         for(int i=0;i<n_g;i++)
         {
              in>>score;
              if(score>3*(p-1))
              {
                   ris++;
              }
              else
              {
                   if(p!=1)
                   {
                        if((score>=(3*p-4)) && (n_s!=0))
                        {
                             ris++;
                             n_s--;
                        }
                   }
              }
         }
         out<<"Case #"<<j+1<<": "<<ris<<endl;
    }
    //system("pause");
}
