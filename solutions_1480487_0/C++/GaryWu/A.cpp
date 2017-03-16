 /* Copyright NTU GIEE 2012. All Rights Reserved. */
 /* =====================================================================================
 *       Filename:  B.cpp
 *    Description:  
 *        Created:  04/14/2012 12:42:55 PM CST
 *         Author:  Bo-Han Gary Wu (NTU GIEE), researchgary@gmail.com
 * ===================================================================================== */

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cassert>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
   ifstream ifile(argv[1]);
   if ( argc != 2 ){
      cout << "Error" << endl;
      return 0;
   }
   int N = 0;
   ifile >> N;
   ofstream ofile("A.out");
   for ( uint32_t i = 0 ; i < N ; ++i ){
      int S = 0;
      ifile >> S;
      vector<int> ss;
      uint32_t sum = 0;
      for ( uint32_t j = 0 ; j < S ; ++j ){
         int tmp;
         ifile >> tmp;
         ss.push_back(tmp);
         sum += tmp;
      }
      double average = (double)sum/ss.size()*2;
      vector<double> diff;
      for ( uint32_t j = 0 ; j < ss.size() ; ++j )
         diff.push_back(average-ss[j]);

      uint32_t nMinor = 0;
      do{
         nMinor = 0;
         double minors = 0.0;
         for ( uint32_t j = 0 ; j < ss.size() ; ++j )
            if ( diff[j] < 0 ){
               minors += diff[j];
               nMinor++;
            }
         for ( uint32_t j = 0 ; j < ss.size() ; ++j )
            if ( diff[j] >= 0 ){
               diff[j] += minors/(ss.size()-nMinor);
            }else{
               diff[j] = 0;
            }
      }while (nMinor>0);

      double s=0.0;
      for( uint32_t j = 0 ; j < ss.size() ; ++j ){
         s+= diff[j]/sum;
      }
      //cout << s << endl;

      ofile << "Case #" << i+1 << ": ";
      cout << "Case #" << i+1 << ": ";
      ofile.precision(8);
      cout.precision(8);
      for ( uint32_t j = 0 ; j < ss.size() ; ++j ){
         ofile << 100*diff[j]/sum << " ";
         cout << 100*diff[j]/sum << " ";
      }
      ofile << endl;
      cout << endl;
   }

   ofile.close();
   ifile.close();
   return 0;
}
