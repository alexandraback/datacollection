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
            int res;
            int d;
            int a,b;
            int aux;
            int aux2;
            int w[9];
            w[0]=1;
            w[1]=10;
            w[2]=100;
            w[3]=1000;
            w[4]=10000;
            w[5]=100000;
            w[6]=1000000;
            w[7]=10000000;
            w[8]=100000000;
            
            for(int i=0; i<t; i++)
            {
            fin >> a;
            fin >> b;
            aux = a;
            res=0;
            d=1;
            
            for(int j=0; j<10; j++)
            if(aux > 9)
            {
            d++;
            aux = aux/10;
            }
            
           
            
            for(int j=a; j<b+1; j++)
            {
            aux=j;
           // fout << res << "         " << j << endl;
            for(int l=0; l<d; l++)
            {
            aux = aux/10 + (aux%10)*w[d-1];
           
            if(aux > j && aux <= b)
            res++;
            
            if(aux == j)
            break;
            }        
            }
            
            
            fout << "Case #" << i+1 << ": " << res << endl;
            }
            
            
            
            
            return 0;
            
        }
        
        
