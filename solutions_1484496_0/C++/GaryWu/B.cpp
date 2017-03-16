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
   uint32_t N = 0;
   ifile >> N;

   ofstream ofile("A.out");
   for ( uint32_t i = 0 ; i < N ; ++i ){
      uint32_t n = 0;
      ifile >> n;
      vector<uint32_t> num;
      for ( uint32_t j = 0 ; j < n ; ++j ){
         uint32_t x;
         ifile >> x;
         num.push_back(x);
      }
      uint32_t nC =0;
      ofstream of2("a.lp");
      of2 << "min: 1;" << endl;
      of2 << "c" << nC++ << ": ";
      of2 << num[0] << " x0 - " << num[0] << " y0 ";
      for( uint32_t j = 1 ; j < n ; ++j ){
          of2 << " + " << num[j] << " x" << j << " - " << num[j] << " y" << j << " ";
      }
      of2 << " = 0;" << endl;
      for( uint32_t j = 0 ; j < n ; ++j ){
         of2 << "c" << nC++ << ": x" << j << "- y" << j << " - 4 z" << j << " <= 0;" << endl;
         of2 << "c" << nC++ << ": y" << j << "- x" << j << " - 4 z" << j << " <= 0;" << endl;
         //of2 << "c" << nC++ << ": y" << j << "- x" << j << " + 4 z" << j << " - 4 <= 0;" << endl;
      }

      for( uint32_t j = 0 ; j < n ; ++j ){
         of2 << "c" << nC++ << ": x" << j << "+ y" << j << " + z" << j << " -2 a" << j << " = 0;" << endl;
      }

      for( uint32_t j = 0 ; j < n ; ++j ){
         of2 << "c" << nC++ << ": x" << j << "+ y" << j << " <= 1;" << endl;
      }

      of2 << "c" << nC++ << ": ";
      of2 << "sum - z0 ";
      for( uint32_t j = 1 ; j < n ; ++j ){
          of2 << " - z" << j;
      }
      of2 << " = 0;" << endl;

      of2 << "c" << nC++ << ": ";
      of2 << "sum >= 1;" << endl;

      of2 << "c" << nC++ << ": ";
      of2 << "x0 ";
      for( uint32_t j = 1 ; j < n ; ++j ){
          of2 << " + x" << j;
      }
      of2 << "- 1 >= 0; " << endl;

      for( uint32_t j = 0 ; j < n ; ++j ){
         of2 << "bin a" << j << ";" << endl;
         of2 << "bin x" << j << ";" << endl;
         of2 << "bin y" << j << ";" << endl;
         of2 << "bin z" << j << ";" << endl;
      }
      of2.close();

      system("./lp_solve a.lp > result");

      ifstream r("result");
      bool unsat = false;
      string name;
      uint32_t v;
      r >> name;
      if ( name == "This" ) unsat = true;
      else{
         while (r>>name){
            if ( name=="x0")
               break;
         }
      }
      r >> v;
      vector<bool> selX, selY;
      selX.push_back(v);
      r >> name >> v;
      selY.push_back(v);
      for( uint32_t j = 1 ; j < n ; ++j ){
         r >> name >> v;
         selX.push_back(v);
         r >> name >> v;
         selY.push_back(v);
      }
      r.close();

      ofile << "Case #" << i+1 << ":" << endl;
      cout << "Case #" << i+1 << ":" << endl;
      if ( unsat){ 
         ofile << "Impossible" << endl;
         cout << "Impossible" << endl;
      }else{
         for( uint32_t j = 0 ; j < n ; ++j ){
            if ( selX[j] == true ){
               ofile << num[j] << " ";
               cout << num[j] << " ";
            }
         }
         ofile << endl;
         cout << endl;
         for( uint32_t j = 0 ; j < n ; ++j ){
            if ( selY[j] == true ){
               ofile << num[j] << " ";
               cout << num[j] << " ";
            }
         }
         ofile << endl;
         cout << endl;
      }
   }

   ofile.close();
   ifile.close();
   return 0;
}
