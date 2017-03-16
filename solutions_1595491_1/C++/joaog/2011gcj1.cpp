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
            int n;
            
            fin >> t;
            
            for(int i=0; i<t; i++)
            {
            fin >> n;
            char robot[n];
            int push[n];
            int pusho[n];
            int pushb[n];
            int o, b;
            o=0;
            b=0;
            
            for(int j=0; j<n; j++)
            {
            fin >> robot[j];
            fin >> push[j];
            if(robot[j]=='O')
            {
            pusho[o]=push[j];
            o++;
            push[j]=0;
            }
            else
            {
            pushb[b]=push[j];
            b++;
            push[j]=1;
            }
            
            }
            
           
            
            int doneo=0;
            int doneb=0;
            int poso=1;
            int posb=1;
            
            int seg=0;
            
            for(seg=0; seg < 100*100*2; seg++)
            {
            if(doneo+doneb==n)
            break;
            
            //fout << poso << "       " << posb << endl;
            
            if(push[doneo+doneb]==0)
            {
                                    
            if(poso==pusho[doneo])
            doneo++;
            else
            {
            if(poso > pusho[doneo])
            poso--;
            else
            poso++;
            }
            
            if(doneb < b)
            {
            if(posb > pushb[doneb])
            posb--;
                        
            if(posb < pushb[doneb])            
            posb++;
            }
            
            }
            else
            {
                                    
            if(posb==pushb[doneb])
            doneb++;
            else
            {
            if(posb > pushb[doneb])
            posb--;
            else
            posb++;
            }
            
            if(doneo < o)
            {
            if(poso > pusho[doneo])
            poso--;
            
            if(poso < pusho[doneo])
            poso++;
            }
            
            }
            
            
            
            }
            
            fout << "Case #" << i+1 << ": " << seg << endl;
            
            } 
            
            
            
            
            return 0;
            
        }
        
        
