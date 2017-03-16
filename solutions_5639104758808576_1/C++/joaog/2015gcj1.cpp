        #include <fstream>
        #include <iostream>
        #include <string>
        #include <stdio.h>
        #include <math.h>
        #include <limits>
        
        
        using namespace std;
        
        
        int main()
        {
            ofstream fout ("2015gcj1out.txt");
            ifstream fin ("2015gcj1in.txt");
            
            int t, s;
            
            int res;     
          
            fin >> t;
            
            char aux2;
            int sum;
            int aux;
      
            
            for(int i=0; i<t; i++)
            {
            
            fin >> s;
            
            res = 0;
            sum = 0;
            
            for(int j=0; j<s+1; j++)
            {
            fin >> aux2;
            aux = aux2-'0';
            
            sum = sum + aux;
            
            
            if(sum < j+1)
            if(res < j+1-sum)
            res = j+1-sum;
            }
            
            
            
            
            
            fout << "Case #" << i+1 << ": " << res << endl;
            }
            
       
            
            return 0;
              
        }
        
        
