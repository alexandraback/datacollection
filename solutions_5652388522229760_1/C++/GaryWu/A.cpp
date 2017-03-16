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

void checkDigit(vector<bool>& c,int64_t n){
   while (n>0){
      int d = n%10;
      c[d] = true;
      n = int64_t(n/10);
   }
}

bool all(const vector<bool>& c){
   for (int i=0; i<c.size(); i++){
      if (!c[i]) return false;
   }
   return true;
}

int main(int argc, char* argv[]){
   ifstream ifile(argv[1]);
   if ( argc != 2 ){
      cout << "Error" << endl;
      return 0;
   }

   ofstream ofile("A.out");
   int T, N;
   ifile >> T;
   for ( int i = 0 ; i < T ; ++i ){
      ifile >> N;
      if (N==0){
         ofile << "Case #" << i+1 << ": " << "INSOMNIA" << endl;
         cout << "Case #" << i+1 << ": " << "INSOMNIA" << endl;
      }else{
         vector<bool> c(10,false);
         int n = N;
         for ( int i = 1 ; ; i++){
            checkDigit(c,n);
            if (all(c))
               break;
            n += N;
         }
         ofile << "Case #" << i+1 << ": " << n << endl;
         cout << "Case #" << i+1 << ": " << n << endl;
      }
   }
   ofile.close();
   ifile.close();
   return 0;
}
