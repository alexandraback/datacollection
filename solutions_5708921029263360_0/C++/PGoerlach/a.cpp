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
        int J;
        datei >> J;
        int P;
        datei >> P;
        int S;
        datei >> S;
        int K;
        datei >> K;
        
        if(K > S)
        {
        	K = S;
		}
        
        cout << K*J*P << endl;
        
        for(int i = 0; i < J; i++)
        {
        	for(int j = 0; j < P; j++)
        	{
        		for(int l = i+j; l < i+j+K; l++)
        		{
        			cout << i+1 << " " << j+1 << " " << (l % S)+1 << endl;
				}
			}
		}
        
        /*int n;
        int k;
        
        if(k > n)
        {
        	k = n;
        }*/
        //first, construct our 3-dim. matrix for pair k, n with 1 <= k <= n.
        /*bool M[n][n][n];
        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		for(int l = 0; l < n; l++)
        		{
        			M[i][j][l] = false;
				}
			}
		}
		
        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		for(int l = i+j; l < i+j+k; l++)
        		{
        			M[i][j][(l % n)] = true;
				}
			}
		}*/
		
		
        
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
