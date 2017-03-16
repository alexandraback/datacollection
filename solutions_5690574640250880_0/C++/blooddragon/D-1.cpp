#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

bool isOpen[51][51];
bool hasMine[51][51];
bool hasMineRs[51][51];
bool tempIsOpen[51][51];
bool tempHasMine[51][51];
int z;
int m,r,c;
bool impossible;
int rsX,rsY;

bool hasMineAround (int x, int y)
{
    if (x > 0)
    {
       if (y > 0)
          if (hasMine[x-1][y-1])
             return true;
       if (y < c-1)
          if (hasMine[x-1][y+1])
             return true;
       if (hasMine[x-1][y])
             return true;      
    }   
    if (x < r - 1)
    {
       if (y > 0)
          if (hasMine[x+1][y-1])
             return true;
       if (y < c-1)
          if (hasMine[x+1][y+1])
             return true;
       if (hasMine[x+1][y])
             return true;   
    }
    if (y  > 0)
       if (hasMine[x][y-1])
          return true;
    if (y < c - 1)
       if (hasMine[x][y+1])
          return true;
    return false;
}

void solve ()
{
        bool solved=false;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
            {
                tempIsOpen[i][j] = isOpen[i][j];
                tempHasMine[i][j] = hasMine[i][j];
            }
        for (int tX = 0; tX < r; tX++)
            for (int tY = 0; tY < c; tY++)
            if (hasMine[tX][tY] == false && impossible)
        {
        solved = true;
        isOpen[tX][tY] = true;
        int nbOpen = 1;
        while (nbOpen != 0)
        {
                    
              nbOpen = 0;
              for (int i = 0; i < r; i++)
                  for (int j = 0; j < c; j++)
                      if (hasMine[i][j] == false && isOpen[i][j])
                      {
                         int x = i;
                         int y = j;
                         if(hasMineAround(i,j) == false)
                         {
                             if (y > 0)
                                if (isOpen[x-1][y-1] == false)
                                {
                                   nbOpen++;
                                   isOpen[x-1][y-1] = true;
                                }
                             if (y < c-1)
                                if (isOpen[x-1][y+1] == false)
                                {
                                   nbOpen++;
                                   isOpen[x-1][y+1] = true;
                                }
                             if (isOpen[x-1][y] == false)
                             {
                                   nbOpen++;
                                   isOpen[x-1][y] = true;
                             }
                          
                         if (x < r - 1)
                         {
                            if (y > 0)
                               if (isOpen[x+1][y-1] == false)
                               {
                                  isOpen[x+1][y-1] = true;
                                  nbOpen++;
                               }
                               if (y < c-1)
                                  if (isOpen[x+1][y+1] == false)
                                  {
                                     isOpen[x+1][y+1] = true;
                                     nbOpen++;
                                  }
                               if (isOpen[x+1][y] == false)
                               {
                                     isOpen[x+1][y] = true;
                                     nbOpen++;
                               }   
                            }                          
                            if (y  > 0)
                               if (isOpen[x][y-1] == false)
                               {
                                     isOpen[x][y-1] = true;
                                     nbOpen++;
                               }
                                  
                            if (y < c - 1)
                               if (isOpen[x][y+1] == false)
                               {
                                  isOpen[x][y+1] = true;
                                  nbOpen++;
                               }
                               }            
                      }
        }
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (isOpen[i][j] == false)
                {
                   solved = false;
                   break;
                }
        if (solved)
        {
                        for (int i = 0; i < r; i++)
                       for (int j = 0; j < c; j++)
                           hasMineRs[i][j] = tempHasMine[i][j];
           rsX = tX;
                   rsY = tY;
                   impossible = false;

                   break;
        }
                for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
            {
                isOpen[i][j] = tempIsOpen[i][j];
                hasMine[i][j] = tempHasMine[i][j];
            }
        }

}

void recursive_procedure (int nbBombPlaced, int x, int y)
{
     if (impossible)
     {
        for (int i = 1; i >= 0; i--)
        {
            if (i == 0)
            {
               if (nbBombPlaced == 0)
                     solve ();
               else
               {            
                      if (x == r-1 && y == c-1)
                      {
                      
                      }
                      else
                      {
                          if (y == c-1)
                             recursive_procedure(nbBombPlaced,x+1,0);        
                          else
                             recursive_procedure(nbBombPlaced,x,y+1);                    
                      }
               }
                  
            }
            else
            if (i == 1 && hasMine[x][y] == false)
            {
                  hasMine[x][y] = true;
                  isOpen[x][y] = true;
                  nbBombPlaced -= 1;
                  if (nbBombPlaced == 0)
                     solve ();
                  else
                  {
                      if (x == r-1 && y == c-1)
                      {
                      
                      }
                      else
                      {
                          if (y == c-1)
                             recursive_procedure(nbBombPlaced,x+1,0);        
                          else
                             recursive_procedure(nbBombPlaced,x,y+1);                    
                      }
                  }
                  hasMine[x][y] = false;
                  isOpen[x][y] = false;
                  nbBombPlaced += 1;
            }
        }
     }     
}


int main () {

    int t; // Number of test cases
    int count;
    int nbOpen;
    cin >> t;
    for (z = 0; z < t; z++)
    {
        impossible = true;
        cout << "Case #" << (z+1) << ":\n";
        cin >> r >> c >> m;
        //
        count = 0;
        for (int i = 0; i < 51; i++)
            for (int j = 0; j < 51; j++)
            {
                isOpen[i][j] = false;
                hasMine[i][j] = false;
            }
        recursive_procedure (m,0,0);
        if (impossible)
           cout << "Impossible\n";
        else
        {
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (hasMineRs[i][j]) 
                       cout << "*";
                    else 
                    {
                         if (i == rsX && j == rsY)
                            cout  << "c";
                         else
                            cout  << ".";
                    }
                }
                cout << "\n";
            }
        }
        //
    }
}
