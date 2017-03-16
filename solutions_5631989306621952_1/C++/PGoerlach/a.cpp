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
         string S;
         datei >> S;
         
         string Snew = "";
         Snew += S[0];
         
         for(int i = 1; i < S.length(); i++)
         {
            for(int j = 0; j < i; j++)
            {
               if(S[i] > Snew[j])
               {
                  Snew.insert(0, S.substr(i,1));
                  break;
               }
               else if(S[i] < Snew[j] || j == i-1)
               {
                  Snew += S[i];
                  break;
               }
            }
         }
         
         cout << Snew;
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
