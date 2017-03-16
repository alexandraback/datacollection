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

using namespace std;

int main(int argc, char* argv[]){
   ifstream ifile(argv[1]);
   if ( argc != 2 ){
      cout << "Error" << endl;
      return 0;
   }

   ofstream ofile("B.out");
   int T;
   string P;
   ifile >> T;
   for ( int i = 0 ; i < T ; ++i ){
      ifile >> P;
      char c = '0';
      int64_t cnt = 0;
      for (int i=0; i<P.size(); i++){
         if (P[i]=='-' && c=='0') cnt++;
         else if (P[i]=='-' && c=='+') cnt+=2;
         c = P[i];
      }
      ofile << "Case #" << i+1 << ": " << cnt << endl;
      cout << "Case #" << i+1 << ": " << cnt << endl;
   }
   ofile.close();
   ifile.close();
   return 0;
}
