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
#include <stdio.h>
#include <stdlib.h>

using namespace std;

ofstream ofile("C.out");
uint64_t checkPrime(uint64_t n){
   for (uint64_t i=2; i<=uint64_t(pow(n,0.5)); i++){
      if (n%i==0) return i;
   }
   return 0;
}
uint64_t base(string str, uint64_t b){
   uint64_t rst = 0;
   uint64_t f = 1;
   for (int i=str.size()-1; i>=0; i--){
      if (str[i]=='1') rst += f;
      f*=b;
   }
   return rst;
}
uint64_t N, J; 
uint64_t JJ=1;
void run(string str){
   if (JJ>J) return;
   vector<uint64_t> fs;
   for (int i=2; i<=10; i++){
      uint64_t n = base(str,i);
      uint64_t f = checkPrime(n);
      if (f==0) return;
      fs.push_back(f);
   }
   ofile << str+str;
   cout << str+str;
   for (int i=0; i<fs.size(); i++){
      ofile << " " << fs[i];
      cout << " " << fs[i];
   }
   ofile << endl;
   cout << endl;
   JJ++;
}

void nex(string str){
   if (str.size()==14){
      str = "1"+str+"1";
      run(str);
   }else{
      nex(str+"1");
      nex(str+"0");
   }
}

int main(int argc, char* argv[]){
   ifstream ifile(argv[1]);
   if ( argc != 2 ){
      cout << "Error" << endl;
      return 0;
   }

   int T;
   ifile >> T;
   ofile << "Case #" << 1 << ":" << endl;
   cout << "Case #" << 1 << ":" << endl;
   for ( int i = 0 ; i < T ; ++i ){
      ifile >> N >> J;
      nex("0");
      nex("1");
   }
   ofile.close();
   ifile.close();
   return 0;
}
