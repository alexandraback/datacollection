        #include <fstream>
        #include <iostream>
        #include <string>
        #include <stdio.h>
        #include <math.h>
        
        
        
        using namespace std;
        
        int main()
        {
            ofstream fout ("2015gcj2out.txt");
            ifstream fin ("2015gcj2in.txt");
            
            
            int t;
            fin >> t;
            int d;
            int n;
            int aux;
            int res;
            int k;
           
            
           
                      
                      
            for(int i=0; i<t; i++)
            {
            fin >> d;
            
            res = 1000;

          
                   
            int p[d];
            
            for(int j=0; j<d; j++)
            fin >> p[j];
            
        //    fout << endl;
         
            for(int j=1; j<=1000; j++)
            {
            aux=0;
            
            for(int l=0; l<d; l++)
            {
            if(p[l] > j)
            if(p[l]%j != 0)
            aux = aux + (p[l]-p[l]%j)/j;
            else
            aux = aux + p[l]/j-1;
            }
            
          //  fout << aux << endl;
            
            if(j+aux < res)
            res = j+aux;
            }
            
            
            fout << "Case #" << i+1 << ": " << res << endl;
            }            
                                   
            
            return 0;
            
        }
        
        
