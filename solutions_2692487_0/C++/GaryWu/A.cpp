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
   uint64_t A, N, S, p;
   ifile >> N;
   for ( uint64_t i = 0 ; i < N ; ++i ){
      ifile >> A;
      uint64_t n = 0;
      ifile >> n;
      vector<uint64_t> others(n,0);
      for ( uint64_t j = 0 ; j < n ; ++j ){
         ifile >> others[j];
      }
      uint64_t op = 0;
      uint64_t cur = A;
      uint64_t hard = 0;
      vector<uint64_t> counting(n,0);
      sort(others.begin(),others.end());
      for ( uint64_t j = 0 ; j < n ; ++j ){
         if ( cur <= others[j] && cur-1 > 0 ){
            hard++;
            uint64_t tmp = cur;
            uint64_t cnt = 0;
            while (tmp<=others[j]){
               tmp += (tmp-1);
               cnt++;
            }
            if ( cnt <= n-j ){
               cur = tmp;
               cur += others[j];
               op += cnt;
               counting[j] = min(op,n);
            }else{
               op += (n-j);
               counting[j] = min(op,n);
            }
         }else if ( cur <= others[j] && cur-1 == 0 ){
            op += others.size();
            counting.clear();
            break;
         }else if ( cur > others[j] ){
            cur += others[j];
            counting[j] = op;
         }
      }
      for ( uint64_t j = 0 ; j < n ; ++j ){
         counting[j] += (n-j-1);
      }
      sort(counting.begin(),counting.end());
      op = min(n,op);
      if ( counting.size()>0)
         op = min(op,counting[0]);
      assert(op<=n);
      ofile << "Case #" << i+1 << ": " << op << endl;
      cout << "Case #" << i+1 << ": " << op << endl;
   }

   ofile.close();
   ifile.close();
   return 0;
}
