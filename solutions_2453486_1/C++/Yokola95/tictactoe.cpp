#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string g[4];
int b[4][4];
string temp;
fstream in,out;
int T;
bool found;
bool check(int sum, int k)
{
                    // out << "Sum: " << sum << endl;
                     if(sum >= 7)
                     {
                            out << "Case #" << k+1 << ": X won" << endl;
                            found = true;
                            return true;
                     }
                     if(sum == -5 || sum ==-8)
                     {
                            out << "Case #" << k+1 << ": O won" << endl;
                            found = true;
                            return true;
                     }
                     return false;
}
     
int sum;
int main()
{
    in.open("input.in",ios::in);
    out.open("output.txt",ios::out);
    in >> T;
    int points;
    for(int k = 0; k < T; ++k)
    {
            found = false;
            points = 0;
             for(int i = 0; i < 4; ++i)
             {
                     in >> g[i];
             }
                      
             // Change in numbers
             for(int i = 0; i < 4; ++i)
                     for(int j = 0; j < 4; ++j)
                     {
                             if(g[i][j] == 'X') 
                                        b[i][j] = 2;
                             if(g[i][j] == 'O')
                                        b[i][j] = -2;
                             if(g[i][j] == '.')
                             {
                                        b[i][j] = 0;
                                        ++points;
                             }
                             if(g[i][j] == 'T')
                                        b[i][j] = 1;
                     }
             
             //Check Horizontal
             for(int i = 0; i < 4; ++i)
             {
                     sum = 0;
                     for(int j = 0; j < 4; ++j)
                             sum+= b[i][j];
                     found = check(sum,k);
                     if(found)
                              i = 5;
             }
             
             // Check Vertical
             if(!found)
                       for(int i = 0; i < 4; ++i)
                       {
                               sum = 0;
                               for(int j = 0; j < 4; ++j)
                                       sum+= b[j][i];
                               found = check(sum,k);
                               if(found)
                                        i = 5;
                       
                       }
             
             // Check Diagonals
             sum = 0;
             if(!found)
             {
                       for(int i = 0; i < 4; ++i)
                               sum += b[i][i];
                       found = check(sum,k);
             }
             sum = 0;
             if(!found)
             {
                       for(int i = 0; i < 4; ++i)

                               sum+= b[i][3-i];
                       found = check(sum,k);
                       
             }
             if(!found)
             {
                       if(points > 0)
                                 out << "Case #" << k+1 << ": Game has not completed" << endl;
                       else out << "Case #" << k+1 << ": Draw" << endl;
             }
                
    }
                  
}
             
                      
    
                      
            
    
