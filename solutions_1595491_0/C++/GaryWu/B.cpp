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

   ofstream ofile("A.out");
   int T, N, S, p;
   ifile >> T;
   for ( uint32_t i = 0 ; i < T ; ++i ){
      ifile >> N >> S >> p;
      vector<int> ss(p,0);
      for ( uint32_t j = 0 ; j < N ; ++j )
         ifile >> ss[j];

      int sur = 0;
      int best = 0;
      for ( uint32_t j = 0 ; j < N ; ++j ){
         if ( ss[j] == 0 ){
            if ( p == 0 )
               ++best;
            continue;
         }
         if ( ss[j]%3 == 0 ){
            if ( sur<S && ss[j]/3-p==-1 ){
               ++sur;
               ++best;
            }else if (ss[j]/3>=p){
               ++best;
            }
         }else if (ss[j]%3==1){
            if (ss[j]/3+1>=p){
               ++best;
            }
         }else{
            if ( sur<S && ss[j]/3+1-p==-1 ){
               ++sur;
               ++best;
            }else if (ss[j]/3+1>=p){
               ++best;
            }
         }
      }
      ofile << "Case #" << i+1 << ": " << best << endl;
      cout << "Case #" << i+1 << ": " << best << endl;
   }

   ofile.close();
   ifile.close();
   return 0;
}
