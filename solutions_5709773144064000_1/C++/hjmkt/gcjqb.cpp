#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


int main(){

   ifstream fin("B-large.in");
   ofstream fout("B-large.out");
   fout << fixed << setprecision(7);

   string buf;

   getline(fin, buf);
   int T = atoi(buf.c_str());
   double C, F, X;
   double incRate;
   double time1, time2, bestTime;

   for(int i = 0; i < T; i++){
      fout << "Case #" << (i + 1) << ": ";

      getline(fin, buf, ' ');
      C = atof(buf.c_str());
      getline(fin, buf, ' ');
      F = atof(buf.c_str());
      getline(fin, buf, '\n');
      X = atof(buf.c_str());

      incRate = 2;
      bestTime = 0;
      while(true){
         time1 = X / incRate;
	 time2 = (C / incRate) + (X / (incRate + F));
	 if(time1 < time2){
            bestTime += time1;
	    break;
	 }
	 else{
            bestTime += (C / incRate);
	    incRate += F;
	 }
      }
      fout << bestTime << "\n";
   }



   fin.close();
   fout.close();
}
