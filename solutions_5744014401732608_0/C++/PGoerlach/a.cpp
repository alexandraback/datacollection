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
         int B;
         datei >> B;
         long long M;
         datei >> M;
         
         int A[B][B];
         for(int i = 0; i < B-1; i++)
         {
         	for(int j = 0; j < B-1; j++)
         	{
         		if(i < j)
         			A[i][j] = 1;
         		else
         			A[i][j] = 0;
			}
		 }
		 for(int i = 0; i < B; i++)
		 {
		 	A[B-1][i] = 0;
		 }
		 
		 for(int i = 0; i < B-1; i++)
		 {
		 	int temp = M % 2;
		 	M /= 2;
		 	if(temp != 0)
		 	{
		 		A[i][B-1] = 1;
			}
			else
			{
				A[i][B-1] = 0;
			}
		 }
		 if(M != 0)
		 	cout << "IMPOSSIBLE";
		else
		{
			cout << "POSSIBLE" << endl;
			for(int i = 0; i < B; i++)
			{
				for(int j = 0; j < B; j++)
				{
					cout << A[i][j];
				}
				if(i != B-1)
					cout << endl;
			}
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
