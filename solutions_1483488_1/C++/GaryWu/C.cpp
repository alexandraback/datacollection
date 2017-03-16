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
#include <math.h>
#include <set>

using namespace std;

uint64_t order[] = { 10, 100, 1000, 10000, 100000, 1000000, 10000000 };

uint32_t nDigit(uint64_t a){
   uint32_t n=0;
   while ( a>=10 ){
      a /= 10;
      ++n;
   }
   return n+1;
}

uint64_t shift_1(uint64_t a, int nD){
   if ( nD == 1 )
      return a;
   uint64_t r = a%10;
   uint64_t q = a/10;
   assert(nD-2>=0);
   return r*order[nD-2]+q;
}

int main(int argc, char* argv[]){
   ifstream ifile(argv[1]);
   if ( argc != 2 ){
      cout << "Error" << endl;
      return 0;
   }

   ofstream ofile("C.out");
   uint64_t T, A, B;
   ifile >> T;
   for ( uint32_t i = 0 ; i < T ; ++i ){
      ifile >> A >> B;
      int nD = nDigit(A);
      uint64_t n = 0;
      for ( uint64_t a = A ; a <= B ; ++a ){
         uint64_t tmpa = a;
         set<uint32_t> traversed;
         for ( int x = 1 ; x < nD ; ++x ){
            tmpa = shift_1(tmpa,nD);
            if ( (tmpa > a) && (tmpa <= B) ){
               if( traversed.find(tmpa) != traversed.end())
                  continue;
               traversed.insert(tmpa);
               ++n;
            }
         }
      }
      ofile << "Case #" << i+1 << ": " << n << endl;
      cout << "Case #" << i+1 << ": " << n << endl;
   }

   ofile.close();
   ifile.close();
   return 0;
}
