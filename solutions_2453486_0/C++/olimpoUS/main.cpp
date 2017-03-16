#include <cstdlib>
#include <iostream>

using namespace std;

char C[5][5];
bool Is(int x, int y, int sx , int sy , char c){
     for(int i = 0 ; i < 4 ; i++)
     {
             if(C[x+(i*sx)][y+(i*sy)] == c || C[ x+(i*sx) ][ y+(i*sy) ] == 'T' ) continue;
             return false;    
     }
     return true;
}
bool Win(char c){
     if(Is(0,0,0,1,c))return true; 
     if(Is(1,0,0,1,c))return true;
     if(Is(2,0,0,1,c))return true;
     if(Is(3,0,0,1,c))return true; 
     if(Is(0,0,1,0,c))return true; 
     if(Is(0,1,1,0,c))return true;
     if(Is(0,2,1,0,c))return true;
     if(Is(0,3,1,0,c))return true;   

     if(Is(0,0,1,1,c))return true;
     if(Is(0,3,1,-1,c))return true;               
     return false;
}
bool End(){
     for(int i = 0 ; i < 4 ; i++)
             for(int j = 0 ; j < 4 ; j++)
                     if(C[i][j]=='.')
                        return false;
     return true;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin >> t;
    int tt = 1;
    while(t--){
               cout << "Case #"<<tt++<<": ";
               for(int  i = 0 ; i < 4 ; i++)
                             cin >> C[i];           
               if(Win('O')){
                            cout << "O won" << endl;             
               }
               else {
                    if(Win('X'))     
                            cout << "X won" << endl;             
                    else{
                         if(End())cout << "Draw" << endl;
                         else cout << "Game has not completed" << endl;
                              
                    }
               }
    }
    //while(1);
    return 0;
}
