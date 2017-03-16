#include <iostream>
#include <fstream>
#include <algorithm>

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
      
      
      for(int k = 0; k < T; k++)
      {
         cout << "Case #" << k+1 << ": ";
                  
         //start:
         //======
         
         int C;
         datei >> C;
         int D;
         datei >> D;
         long long V;
         datei >> V;
         
         long long a[D];         
         for(int i = 0; i < D; i++)
         {
            datei >> a[i];
         }
         sort(a, a+D);
         
         long long currentMax = 0;
         int denominationsAdded = 0;
         ////cout << C << " " << D << " " << V << ".";
         for(int i = 0; i < D; i++)
         {
            ////cout << a[i] << " ";
            while(a[i] > currentMax + 1)
            {
               ////cout << currentMax+1 << "(new) ";
               //add intermediate denomination: add currentMax+1
               denominationsAdded++;
               currentMax += C*(currentMax+1);
            }
            //add a[i] to current:
            currentMax += C*a[i];
         }
         //add denominations at end:
         while(currentMax < V)
         {
            //add currentMax+1:
            denominationsAdded++;
            currentMax += C*(currentMax+1);
         }
         
         cout << denominationsAdded;
         
         //===
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
