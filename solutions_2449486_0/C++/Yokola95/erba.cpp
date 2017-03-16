#include <cstdlib>
#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;
int T;
fstream in,out;
int N, M;

int g[101][101];

int hn[105];
int max_h;
bool fail;
bool propagav(int r, int c, int h)
{
     if( h >= g[r][c])
     {
          if( r == N-1)
          {
          //	  out << "Removing grass at r: " << r << " c: " << c << endl;
              if(g[r][c] == h)
              			 hn[h]--;
 			   g[r][c] = 0;			 
              return true;
          }else
               {
                     if(propagav(r+1,c,h))
                     {
          	 		  	//	  out << "Removing grass at r: " << r << " c: " << c << endl;
            		  		  if(g[r][c] == h)
              					  	 hn[h]--;
      					  	  g[r][c] = 0;
                              return true;
                     }
               }
          
     }
     return false;
}

bool propagao(int r, int c, int h)
{
     if( h >= g[r][c])
     {
          if( c == M-1)
          {
          	//  out << "Removing grass at r: " << r << " c: " << c << endl;
              if(g[r][c] == h)
              			 hn[h]--;
 			   g[r][c] = 0;			 
              return true;
          }else
               {
                     if(propagao(r,c+1,h))
                     {
       	          	        // out << "Removing grass at r: " << r << " c: " << c << endl;
            		  		  if(g[r][c] == h)
              					  	 hn[h]--;
      					  	  g[r][c] = 0;
                              return true;
                     }
               }
          
     }
     return false;
}

     
     
int main()
{
    in.open("input.in",ios::in);
    out.open("output.txt",ios::out);
    in >> T;
    set<int> num;
    for(int k = 0; k < T; ++k)
    {
            num.clear();
            for(int i = 0; i < 105; ++i)
                    hn[i] = 0;
            
            in >> N >> M;
            for(int i = 0; i < N; ++i)
                    for(int j = 0; j < M; ++j)
                    {
                            in >> g[i][j];
                            max_h = max(max_h,g[i][j]);
                            if( hn[g[i][j]] == 0 ) 
                                num.insert(g[i][j]);
                            hn[g[i][j]]++;
                    }
            num.insert(105);
            int index = 0;
            set<int>::iterator j = num.begin();
            fail = false;
            /*for(int i = 0; i < N; ++i)
      		{
            		for(int j = 0; j < M; ++j)
            		{
            			out << g[i][j] << " ";
            		}
   				 	out << endl;
 			}*/
            while( (*j) <= max_h)
            {
                   for(int i = 0; i < M; ++i) // Per ogni casella prima riga controllo
                           if( g[0][i] <= (*j) )
                               propagav(0,i,*j);
                   for(int i = 0; i < N; ++i)
                           if( g[i][0] <= (*j) )
                               propagao(i,0,*j);
                   if(hn[(*j)] != 0)
                   {
     			           //out << "h: " << (*j) << " = " <<  hn[(*j)] << endl;
                   		   fail = true;
                   		   break;
	               }
	               ++j;
                   		   
            }
			//out << "----" << endl;
			
            /*for(int i = 0; i < N; ++i)
      		{
            		for(int j = 0; j < M; ++j)
            		{
            			out << g[i][j] << " ";
            		}
   				 	out << endl;
 			}*/	
    		out << "Case #" << k+1 << ": ";
            if(fail)
            		out << "NO" << endl;
    		else out << "YES" << endl;
  	}
}
                   
                               
                            
                            
