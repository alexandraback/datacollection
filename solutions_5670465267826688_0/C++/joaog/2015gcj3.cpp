        #include <fstream>
        #include <iostream>
        #include <string>
        #include <stdio.h>
        
        char mult(char a, char b)
        {
        int c[4];
        int d[4];
        int e[4];
        
        if( a == '1')
        {
        c[0]=1;
        c[1]=0;
        c[2]=0;
        c[3]=0;
        }
        
         if( a == '0')
        {
        c[0]=-1;
        c[1]=0;
        c[2]=0;
        c[3]=0;
        }
        
        if( a == 'i')
        {
        c[0]=0;
        c[1]=1;
        c[2]=0;
        c[3]=0;
        }
        
        if( a == 'l')
        {
        c[0]=0;
        c[1]=-1;
        c[2]=0;
        c[3]=0;
        }
        
           if( a == 'j')
        {
        c[0]=0;
        c[1]=0;
        c[2]=1;
        c[3]=0;
        }
        
        if( a == 'm')
        {
        c[0]=0;
        c[1]=0;
        c[2]=-1;
        c[3]=0;
        }
        
           if( a == 'k')
        {
        c[0]=0;
        c[1]=0;
        c[2]=0;
        c[3]=1;
        }
        
        if( a == 'n')
        {
        c[0]=0;
        c[1]=0;
        c[2]=0;
        c[3]=-1;
        }
        
        if( b == '1')
        {
        d[0]=1;
        d[1]=0;
        d[2]=0;
        d[3]=0;
        }
        
         if( b == '0')
        {
        d[0]=-1;
        d[1]=0;
        d[2]=0;
        d[3]=0;
        }
        
        if( b == 'i')
        {
        d[0]=0;
        d[1]=1;
        d[2]=0;
        d[3]=0;
        }
        
        if( b == 'l')
        {
        d[0]=0;
        d[1]=-1;
        d[2]=0;
        d[3]=0;
        }
        
           if( b == 'j')
        {
        d[0]=0;
        d[1]=0;
        d[2]=1;
        d[3]=0;
        }
        
        if( b == 'm')
        {
        d[0]=0;
        d[1]=0;
        d[2]=-1;
        d[3]=0;
        }
        
           if( b == 'k')
        {
        d[0]=0;
        d[1]=0;
        d[2]=0;
        d[3]=1;
        }
        
        if( b == 'n')
        {
        d[0]=0;
        d[1]=0;
        d[2]=0;
        d[3]=-1;
        }
        
        
        e[0] = c[0]*d[0]-c[1]*d[1]-c[2]*d[2]-c[3]*d[3];
        e[1] = c[0]*d[1]+c[1]*d[0]+c[2]*d[3]-c[3]*d[2];
        e[2] = c[0]*d[2]-c[1]*d[3]+c[2]*d[0]+c[3]*d[1];
        e[3] = c[0]*d[3]+c[1]*d[2]-c[2]*d[1]+c[3]*d[0];
        
        if(e[0]==1)
        return '1';
        
        if(e[0]==-1)
        return '0';
        
        if(e[1] == 1)
        return 'i';
        
        if(e[1] == -1)
        return 'l';
        
        if(e[2] == 1)
        return 'j';
        
        if(e[2] == -1)
        return 'm';
        
        if(e[3] == 1)
        return 'k';
        
        if(e[3] == -1)
        return 'n';
        }
        
        using namespace std;
        
        int main()
        {
            ofstream fout ("2015gcj3out.txt");
            ifstream fin ("2015gcj3in.txt");
            
            int t;
            long long l;
            long long x;
            char aux;
            int esq, dir;
            int aux2;
            
            fin >> t;
           
            for(int i=0; i<t; i++)
            {
            
            fin >> l;
            fin >> x;
            
        //    x = x%12;
            
       //   fout << x << endl;
            
            char w[l];
            
            for(int j=0; j<l; j++)
            {
            fin >> w[j];
        //    fout << w[j];
            }
            
     //       fout << endl;
            
            
            
            aux = '1';
            
            for(int j=0; j<l*x; j++)
            {
            aux = mult(aux, w[j%l]);
            }
     
            if(aux != '0')
            fout << "Case #" << i+1 << ": NO"<< endl;
            else
            {
            aux = '1';
            aux2 = 0;
            
            for(int j=0; j<l*x; j++)
            {
            aux = mult(aux, w[j%l]);
            if(aux == 'i')
            {
            esq = j;
            aux2++;
            break;
            }
            }
            
            aux = '1';
            
            for(int j=l*x-1; j>=0; j--)
            {
            aux = mult(w[j%l],aux);
            if(aux == 'k')
            {
            dir = j;
            aux2++;
            break;
            }
            }
            
            if(esq < dir+1 && aux2 == 2)
            {
            fout << "Case #" << i+1 << ": YES"<< endl;
      //      fout << esq << " " << dir << endl << endl;
            }
            else
            fout << "Case #" << i+1 << ": NO"<< endl;
            }
            
            
            } 
            return 0;
            
        }
        
        

