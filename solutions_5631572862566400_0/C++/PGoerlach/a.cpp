#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int N;
int a[1000];
bool flagged[1000];
int red[1000][2];
int score[1000];
int redCount;
int currCircle;
int largestCircle;
int currRepeat;
int pathLength;

int treat(int i)
{
   if(a[a[i]] == i)
   {
      if(pathLength > score[i])
         score[i] = pathLength;
         
      if(score[i] < 0)
         score[i] = 0;
      
      if(score[a[i]] < 0)
         score[a[i]] = 0;
      
      if(!flagged[i])   
      {     
         red[redCount][0] = i;
         red[redCount][1] = a[i];
         redCount++;
         flagged[i] = true;
         flagged[a[i]] = true;
      }
      return 0;
   }
   
   if(flagged[i])
      return score[i];
      
   flagged[i] = true;
   pathLength++;
   int temp = treat(a[i]);
   if(temp == -1)
   {
      if(currRepeat == -1)
      {
         currRepeat = a[i];
         currCircle = 1;
      }
      else if(currCircle > 0)
      {
         currCircle++;
         if(currRepeat == i)
         {
            if(currCircle > largestCircle)
               largestCircle = currCircle;
            currCircle = -1;
         }
      }
   }
   else
      score[i] = temp + 1;
   return score[i];
}

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
         datei >> N;
         
         for(int i = 0; i < N; i++)
         {
            datei >> a[i];
            a[i]--;
         }
         
         
         for(int i = 0; i < N; i++)
         {
            flagged[i] = false;
            score[i] = -1;
         }
         largestCircle = 0;
         redCount = 0;
         
         for(int i = 0; i < N; i++)
         {
            currRepeat = -1;
            currCircle = -1;
            pathLength = 0;
            treat(i);
         }
         
         int sum = 2*redCount;
         for(int i = 0; i < redCount; i++)
         {
            sum += score[red[redCount][0]];
            sum += score[red[redCount][1]];
         }
         
         if(sum > largestCircle)
            cout << sum;
         else
            cout << largestCircle;
         
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
