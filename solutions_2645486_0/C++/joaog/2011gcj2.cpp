        #include <fstream>
        #include <iostream>
        #include <string>
        #include <stdio.h>
        #include <math.h>
        
        
        using namespace std;
        
        int main()
        {
            ofstream fout ("2011gcj2out.txt");
            ifstream fin ("2011gcj2in.txt");
            
            int t;
            fin >> t;
            int e, r, n;
            int res;
            
                      
                      
            for(int i=0; i<t; i++)
            {
            
            res = 0;
                   
            fin >> e;
            fin >> r;
            fin >> n;
            
            int v[n];
            int f;
            f=e;
            
            /*fout << e << endl;
            fout << r << endl;
            fout << n << endl; */
            
            for(int j=0; j<n; j++)
            fin >> v[j];
            
            if(r > e)
            r=e;
            
            for(int j=0; j<n-1; j++)
            {
            
            for(int l=1; j+l<n; l++)
            {
                    
            if(v[j+l] > v[j])
            {
                      
                      
            if(l*r+f > e)
            {
                     
            
            if(l*r+f-e < f)
            {
            res = res+(l*r+f-e)*v[j];
            if(e-l*r+r > e)
            f = e;
            else
            f = e-l*r+r;
            }
            else
            {
            res = res+f*v[j];
            f = r;
            }
            }
            else
            f= f+r;                     
            
            break;
            
            }
            
            if(j+l == n-1)
            {
            res = res+f*v[j];
            f=r;
            break;      
            }
            
            if(l*r >= e)
            {
            res = res + f*v[j];
            f=r;
            break;
            }
            
           
            
            }
            
          /*   fout << res << endl;
            fout << f << endl;
            
            fout << f << endl;
            fout << res << endl; */
            }
            
            res = res+f*v[n-1];
            
            
            
            
            fout << "Case #" << i+1 << ": " << res << endl;
           
            }            
                                   
            
            return 0;
            
        }
        
        
