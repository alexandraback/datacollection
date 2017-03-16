#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
   //Eingabe des Dateinamens über Konsole oder Übergabe als Eingabeparameter
   char* filename;
   if(argc > 1)
   {
      filename = argv[1];
   }
   else
   {
      char buffer[256];
      cout << "Input file name (up to 255 Characters): " << endl;
      cin >> buffer;
      filename = buffer;
   }
   
   int T = 0;
   
   try
   {    
      ifstream datei(filename);
      if(!datei.is_open())
         throw 1;
      
      if(!datei.good())
         throw 2;
      datei >> T;
      if(T <= 0)
         throw 3;
      
      
      for(int k0 = 0; k0 < T; k0++)
      {
         cout << "Case #" << k0+1 << ": ";
         
         
         //start
         int N;
         datei >> N;
         
         int a[2*N-1][N];
         int result[N];
         for(int i = 0; i < 2*N-1; i++)
         {
            for(int j = 0; j < N; j++)
            {
               datei >> a[i][j];
            }
         }
         for(int i = 0; i < N; i++)
         {
            result[i] = 0;
         }
         
         int index = -1;
         int hash[N][2];
         bool flagged[2*N-1];
         
         for(int i = 0; i < 2*N-1; i++)
         {
            flagged[i] = false;
         }
         
         for(int k = 0; k < N; k++)
         {
            int min = 2501;
            int numMin = 0;
            for(int i = 0; i < 2*N-1; i++)
            {
               if(flagged[i])
                  continue;
               
               if(a[i][k] < min)
               {
                  min = a[i][k];
                  numMin = 1;
                  hash[k][0] = i;
               }
               else if(a[i][k] == min)
               {
                  numMin++;
                  hash[k][1] = i;
               }
            }
            if(numMin < 2)
            {
               if(numMin != 1 || index != -1)
                  cout << "UPS!";
                  
               index = k;
               flagged[hash[k][0]] = true;
            }
            else
            {
               flagged[hash[k][0]] = true;
               flagged[hash[k][1]] = true;
            }
         }
         
         int iRef = hash[index][0];
         for(int j = 0; j < N; j++)
         {
            if(j == index)
            {
               cout << a[iRef][index];
               if(j < N-1)
                  cout << " ";
                  
               continue;
            }
            
            int A = a[hash[j][0]][index];
            int B = a[hash[j][1]][index];
            int X = a[iRef][j];
            
            if(A == X)
               cout << B;
            else
            {
               if(B != X)
                  cout << "UPS!?!";
                  
               cout << A;
            }
            
            if(j < N-1)
               cout << " ";
         }
         
         //end
         cout << endl;
      }
   }
   catch(int e)
   {
      cout << "Fehler (Nr. " << e << ") beim Einlesen der Datei.";
      int a;
      cin >> a;
      return 1;
   }
    
    //int a;
    //cin >> a;
    return 0;    
}
