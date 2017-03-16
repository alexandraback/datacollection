#include <iostream>
#include <fstream>

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
         
         int N;
         datei >> N;
         
         int D[N];
         int H[N];
         long long M[N];
         int numberOfHikers = 0;
         for(int i = 0; i < N; i++)
         {
            datei >> D[i];
            datei >> H[i];
            datei >> M[i];
            numberOfHikers += H[i];
         }
         
         //Algorithm begin
         long long min = numberOfHikers;
         for(int i = 0; i < N; i++)
         {
            for(int j = 0; j < H[i]; j++)
            {
               //finish just after hiker j in group i:
               long long Z = (360-D[i])*(M[i]+j);  //endtime*360
               long long encounters = 0;
               for(int l = 0; l < N; l++)
               {
                  for(int r = 0; r < H[l]; r++)
                  {
                     long long Y = (360-D[l])*(M[l]+r);
                     if(Y > Z)
                        encounters++;
                     else
                        encounters += (Z-Y)/(360*(M[l]+r));
                     
                     if(encounters > min)
                        break;
                  }
                  if(encounters > min)
                     break;
               }
               if(encounters < min)
               {
                  min = encounters;
               }
            }
         }
         cout << min;
         
         //Algorithm end
         
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
