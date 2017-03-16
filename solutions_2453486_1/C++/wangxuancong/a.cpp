#include <iostream>
#include <string>

using namespace std; 
char s[10][10];
char ret[4][30] = {"X won", "O won", "Draw", "Game has not completed"};
 
bool isC(char x, char y)
{
    bool bb;
    for(int i = 0; i < 4; i++)
    {
        bb = true;
        for (int j = 0 ; j  < 4; j++)
        {
            if (s[i][j] == y || s[i][j] == '.')
            {
                bb = false;
                break;
            }
        }    
        
        if (bb == true)
        {
            return true;
        }
        
        
        bb = true;
        for (int j = 0 ; j  < 4; j++)
        {
            if (s[j][i] == y || s[j][i] == '.')
            {
                bb = false;
                break;
            }
        }    
        
        if (bb == true)
        {
            return true;
        }
    }
    
    if ((s[0][0] == x || s[0][0] == 'T') 
    && (s[1][1] == x || s[1][1] == 'T')
    && (s[2][2] == x || s[2][2] == 'T')
    && (s[3][3] == x || s[3][3] == 'T'))
    {
        return true;
    }
    
    if ((s[0][3] == x || s[0][3] == 'T') 
    && (s[1][2] == x || s[1][2] == 'T')
    && (s[2][1] == x || s[2][1] == 'T')
    && (s[3][0] == x || s[3][0] == 'T'))
    {
        return true;
    }
    
    return false;
}
char* slove()
{
    
    
    if (isC('X', 'O')) return ret[0];
    if (isC('O', 'X')) return ret[1];
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (s[i][j] == '.') return ret[3];
        }
    }   
    
    return ret[2];
}

int main()
{
  //  freopen("A-large.in", "r", stdin);
   // freopen("A-large.out", "w", stdout);
    int T = 0; 
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        
        for(int i = 0; i < 4; i++)
        {
            cin>>s[i];
        }
       
        cout << "Case #"<<t<<": "<<slove()<<endl;
 
    }
    
   // while(1);
}
