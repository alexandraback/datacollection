        #include <fstream>
        #include <iostream>
        #include <string>
        #include <stdio.h>
        #include <math.h>
        #include <limits>
        
        
        using namespace std;
        
        int main()
        {
            ofstream fout ("2011gcj1out.txt");
            ifstream fin ("2011gcj1in.txt");
            
            fout.precision(18);
            
            int t;
            fin >> t;
            for(int i=0; i<t; i++)
            {
                    
            long double r, l;
            
            fin >> r;
            fin >> l;
            
            
            long double res;
            
            long double aux;
            
            aux = r-1/2;
            
            res = sqrt(aux*aux+2*l)/2 - (2*r-1)/4;
            
            long long k;
            
            k = res;
            
            if(2*k*k + k*(2*r - 1) <= l)
            {
            for(;2*k*k + k*(2*r - 1) <= l; k++)
            k=k;
            
            k=k-1;            
            }
            else
            {
            for(;2*k*k + k*(2*r - 1) > l;k--)
            k=k;
            }
            
            fout << "Case #" << i+1 << ": " << k << endl;
            
            
            } 
            
            
            
            
            return 0;
            
        }
        
        
