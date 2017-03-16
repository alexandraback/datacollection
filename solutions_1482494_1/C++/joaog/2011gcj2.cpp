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
            int n;
            int d;
            
            for(int i=0; i<t; i++)
            {
                    
            fin >> n;
            int a[n];
            int b[n];
            int c[n];
            
            for(int j=0; j<n; j++)
            {
            fin >> a[j];
            fin >> b[j];
            c[j]=0;
            }
            
            int d, res, aux, pos, size, auy;
            
            d=0;
            res = 0;
            auy = 0;
                   
           
            
            
            for(int j=0; (d < 2*n)&&(auy==0); j++)
            {
                    
            aux =0;
            pos = -1;
            size = -1;    
            for(int l=0; l<n; l++)
            {
            
            if( (b[l] <= d)&&(c[l] < 2))
            {
            d = d+2-c[l];
            res = res +1;
            c[l]=2;
            aux = 2;
            }
            else
            {
            if((a[l] <= d)&&(c[l]==0))
            {
            if(aux ==0)
            aux = 1;
            
            if(b[l] > size)
            {
            size=b[l];
            pos = l;
            }
            
            }
            }         
            
            
            
            }
            
            
            if(aux==1)
            {
            c[pos]=1;
            d = d+1;
            res = res+1;
            }
            
            if(aux == 0)
            auy = 1;
            
            }
            
            if(auy == 1)
            fout << "Case #" << i+1 << ": Too Bad" << endl;
            else
            fout << "Case #" << i+1 << ": " << res << endl;
            }
            
            
            
            
            return 0;
            
        }
        
        
