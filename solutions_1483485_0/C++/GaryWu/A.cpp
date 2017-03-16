 /* Copyright NTU GIEE 2012. All Rights Reserved. */
 /* =====================================================================================
 *       Filename:  A.cpp
 *    Description:  
 *        Created:  04/14/2012 12:42:55 PM CST
 *         Author:  Bo-Han Gary Wu (NTU GIEE), researchgary@gmail.com
 * ===================================================================================== */

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cassert>

using namespace std;

map<char,char> trans;

int main(int argc, char* argv[]){
   ifstream ifile(argv[1]);
   if ( argc != 2 ){
      cout << "Error" << endl;
      return 0;
   }

   string googlerese = "ejp mysljylc kd kxveddknmc re jsicpdrysi\
   rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd\
   de kr kd eoya kw aej tysr re ujdr lkgc jv";

   string normal = "our language is impossible to understand\
   there are twenty six factorial possibilities\
   so it is okay if you want to just give up";

   assert(googlerese.size()==normal.size());

   for ( uint32_t i = 0 ; i < googlerese.size() ; ++i ){
      trans[googlerese[i]] = (char)normal[i];
   }


   ofstream ofile("A.out");
   int n = 0;
   string line;
   getline(ifile,line); 
   n = atoi(line.c_str());
   for ( uint32_t j = 0 ; j < n ; ++j ){
      string newNormal;
      getline(ifile,newNormal); 
      for ( uint32_t i = 0 ; i < newNormal.size() ; ++i )
         newNormal[i] = trans[newNormal[i]];
      ofile << "Case #" << j+1 << ": " << newNormal << endl;
      cout << "Case #" << j+1 << ": " << newNormal << endl;
   }
   ofile.close();

   ifile.close();
   return 0;
}
