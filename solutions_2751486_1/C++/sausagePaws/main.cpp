#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;


int main(int argc, char *argv[])
{
    
    if(argc < 3)
    {
            cout << "Oops - not enough command line parameters\n\n";
            system("PAUSE");
            return EXIT_FAILURE;
    }   
    
    ifstream input;
    input.open(argv[1]);
    
    ofstream output;
    output.open(argv[2]);
    
    int m_cases;
    input >> m_cases;
    
    for(int cases = 0; cases < m_cases; cases++)
    {
        char buf[1000001];
        char * lbuf = buf;
        char * fbuf =buf;
        long long rank;
        long long consec = 0;

        input >> buf >> rank;
        
        char * rbuf = lbuf;
        while(* rbuf) rbuf++;

        
       long long cont_len = 0;
       for(; fbuf < rbuf; fbuf++)

       { 
           if( *fbuf != 'e' && *fbuf != 'a'  && *fbuf != 'i'  && *fbuf != 'o'   && *fbuf != 'u')
           {
               cont_len ++;
               if(cont_len == rank)
               {
                    long long left_lim = fbuf - lbuf - rank + 2;
                    long long  right_lim = rbuf - fbuf; 
                    long long  increment = left_lim * right_lim;
                   consec += increment; 
                   cont_len--;
                   lbuf = fbuf - (rank-2);
               }
           }
           else
           {
               cont_len = 0;
           }
       }
       output << "Case #" << cases+1 << ": " << consec << "\n";
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
