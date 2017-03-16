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
#include <stdint.h>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]){
   ifstream ifile(argv[1]);
   if ( argc != 2 ){
      cout << "Error" << endl;
      return 0;
   }

   ofstream ofile("D.out");
   int T;
   uint64_t K,C,S;
   ifile >> T;
   for ( int i = 0 ; i < T ; ++i ){
      ifile >> K >> C >> S;
      uint64_t n = (uint64_t)std::ceil(K/(1<<(C-1)));
      if (S<n){
         ofile << "Case #" << i+1 << ": " << "IMPOSSIBLE" << endl;
         cout << "Case #" << i+1 << ": " << "IMPOSSIBLE" << endl;
      }else{
         ofile << "Case #" << i+1 << ": ";
         cout << "Case #" << i+1 << ": ";
         for (uint64_t i = 1; i<=K; i++){
            ofile << i << " ";
            cout  << i << " ";
         }
         ofile << endl;
         cout << endl;
         /*
         uint64_t c = C-1;
         uint64_t g = 1<<c;
         vector<uint64_t> tiles;
         for (uint64_t i=0; i<c; i++){

         }
         */
      }
   }
   ofile.close();
   ifile.close();
   return 0;
}
