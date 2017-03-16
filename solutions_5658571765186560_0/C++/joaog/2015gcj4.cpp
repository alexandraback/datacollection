        #include <fstream>
        #include <iostream>
        #include <string>
        #include <stdio.h>
        
        
        using namespace std;
        
        int main()
        {
            ofstream fout ("2015gcj4out.txt");
            ifstream fin ("2015gcj4in.txt");
            
            int t;
            fin >> t;
            int x, r, c;
            
            
            for(int i=0; i<t; i++)
            {
            
            fin >> x;
            fin >> r;
            fin >> c;
            
           
            if(r*c % x == 0)
            {
            if( x > 6)
            fout << "Case #" << i+1 << ": RICHARD" << endl;
            
            if(x <= 2)
            fout << "Case #" << i+1 << ": GABRIEL" << endl;
            
            if(x == 3)
            {
            if(r >= 2 && c >= 2)
            fout << "Case #" << i+1 << ": GABRIEL" << endl;
            else
            fout << "Case #" << i+1 << ": RICHARD" << endl;
            }
            
            if(x==4)
            {
            if(r >= 3 && c>=3)
            fout << "Case #" << i+1 << ": GABRIEL" << endl;
            else
            fout << "Case #" << i+1 << ": RICHARD" << endl;
            }
            }
            else
            fout << "Case #" << i+1 << ": RICHARD" << endl;         
            
           
           
            
            }
                    
          
            
            
          
            
            return 0;
            
        }
        
        

