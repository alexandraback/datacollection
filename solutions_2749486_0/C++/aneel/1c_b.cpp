#include <iostream>
#include <cstring>
using namespace std;

char moves[2][10000];

int main()
{
    
    int x,y,
        x1,y1,
        n,m;
    
    int t;
    cin>>t;
    for(int ti = 1; ti <= t; ++ti)
    {
        n = x1 = y1 = 0;
        m = 1;
        cin>>x>>y;

        n = 0;    
        while(x1 != x)
        {
            if(x > 0)
            {
                if(x1 + m <= x) 
                {
                    x1 += m;
                    moves[0][n++] = 'E';
                }
                else 
                {
                    x1 -= m;
                    moves[0][n++] = 'W';
                }
            }
            else 
            {
                if(x1 - m >= x) 
                {
                    x1 -= m;
                    moves[0][n++] = 'W';
                }
                else 
                {
                    x1 += m;
                    moves[0][n++] = 'E';
                }    
            }
            ++m;
        }
        while(y1 != y)
        {
            if(y > 0)
            {
                if(y1 + m <= y) 
                {
                    y1 += m;
                    moves[0][n++] = 'N';
                }
                else 
                {
                    y1 -= m;
                    moves[0][n++] = 'S';
                }
            }
            else
            {
                if(y1 - m >= y) 
                {
                    y1 -= m;
                    moves[0][n++] = 'S';
                }
                else 
                {
                    y1 += m;
                    moves[0][n++] = 'N';
                }
            }
            
            ++m;
        }
        moves[0][n] = 0;

        n = x1 = y1 = 0;
        m = 1;
        while(y1 != y)
        {
            if(y > 0)
            {
                if(y1 + m <= y) 
                {
                    y1 += m;
                    moves[1][n++] = 'N';
                }
                else 
                {
                    y1 -= m;
                    moves[1][n++] = 'S';
                }
            }
            else 
            {
                if(y1 - m >= y) 
                {
                    y1 -= m;
                    moves[1][n++] = 'S';
                }
                else 
                {
                    y1 += m;
                    moves[1][n++] = 'N';
                }                
            }
            ++m;
        }
        while(x1 != x)
        {
            if(x > 0)
            {
                if(x1 + m <= x) 
                {
                    x1 += m;
                    moves[1][n++] = 'E';
                }
                else 
                {
                    x1 -= m;
                    moves[1][n++] = 'W';
                }
            }
            else
            {
                if(x1 - m >= x) 
                {
                    x1 -= m;
                    moves[1][n++] = 'W';
                }
                else 
                {
                    x1 += m;
                    moves[1][n++] = 'E';
                }                
            }
            ++m;
        }
        moves[1][n] = 0;
        
        int i = 0;
        if(strlen(moves[1]) <strlen(moves[0])) i = 1;

        cout<<"Case #"<<ti<<": "<<moves[0]<<endl;;
    }
    
    return 0;
}
