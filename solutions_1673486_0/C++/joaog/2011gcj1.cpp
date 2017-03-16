        #include <fstream>
        #include <iostream>
        #include <string>
        #include <stdio.h>
        
        
        using namespace std;
        
        int main()
        {
            ofstream fout ("2011gcj1.txt.txt");
            ifstream fin ("2011gcj1.in.txt");
            
            int t;
            int a, b;
            int aux;
            double d;
            
            fin >> t;
            
            double res;
            
            for(int i=0; i<t; i++)
            {
            
            d = 1;
            fin >> a;
            fin >> b;
            res = b+2;
            double p[a];
            
            for(int j=0; j<a; j++)
            {
            fin >> p[j];
            }
            
            for(int j=0; j<a; j++)
            {
            d = d*p[j];

            if(2*b + 2 + a - 2*(j+1) - (b+1)*d < res)
            res = 2*b + 2 + a - 2*(j+1) - (b+1)*d;
            
            }
            
            fout.precision( 15 );
            
            fout << "Case #" << i+1 << ": " << res << endl;
            }
            
                        
            
            
            
            
            
            return 0;
            
        }
        
        
