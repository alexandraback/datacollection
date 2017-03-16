        #include <fstream>
        #include <iostream>
        #include <string>
        #include <stdio.h>
        
        
        using namespace std;
        
        int main()
        {
            ofstream fout ("2011gcj3out.txt");
            ifstream fin ("2011gcj3in.txt");
            
            int t;
            fin >> t;
            string g;
            getline(fin, g);
            
            for(int i=0; i<t; i++)
            {
            getline(fin, g);
            
            fout << "Case #" << i+1 << ": ";
            
            for(int j=0; j< g.length(); j++)
            {
            if(g[j] == ' ')
            fout << " ";
            
            if(g[j]=='a')
            fout << "y";
            if(g[j]=='b')
            fout << "h";
            if(g[j]=='c')
            fout << "e";
            if(g[j]=='d')
            fout << "s";
            if(g[j]=='e')
            fout << "o";
            if(g[j]=='f')
            fout << "c";
            if(g[j]=='g')
            fout << "v";
            if(g[j]=='h')
            fout << "x";
            if(g[j]=='i')
            fout << "d";
            if(g[j]=='j')
            fout << "u";
            if(g[j]=='k')
            fout << "i";
            if(g[j]=='l')
            fout << "g";
            if(g[j]=='m')
            fout << "l";
            if(g[j]=='n')
            fout << "b";
            if(g[j]=='o')
            fout << "k";
            if(g[j]=='p')
            fout << "r";
            if(g[j]=='q')
            fout << "z";
            if(g[j]=='r')
            fout << "t";
            if(g[j]=='s')
            fout << "n";
            if(g[j]=='t')
            fout << "w";
            if(g[j]=='u')
            fout << "j";
            if(g[j]=='v')
            fout << "p";
            if(g[j]=='w')
            fout << "f";
            if(g[j]=='x')
            fout << "m";
            if(g[j]=='y')
            fout << "a";
            if(g[j]=='z')
            fout << "q";
            
            }
            
            fout << endl;
            }
             
            return 0;
            
        }
        
        

