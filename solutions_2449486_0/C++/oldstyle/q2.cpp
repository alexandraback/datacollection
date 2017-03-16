//Joe Snider
//4/13
//
//Solution to problem 2 for codejam 2013q

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//T is just a 2d array (vector<vector<int> >)
template <class T>
bool isValid(const T& lawn) {
   int nx = lawn.size();
   int ny = lawn[0].size();
   for(int x = 0; x < nx; ++x) {
      for(int y = 0; y < ny; ++y) {
         int l = lawn[x][y];
         //check rows
         bool br = true;
         for(int i = 0; i < nx; ++i) {
            if(lawn[i][y] > l) {
               br = false;
            }
         }
         //check columns
         bool bc = true;
         for(int i = 0; i < ny; ++i) {
            if(lawn[x][i] > l) {
               bc = false;
            }
         }
         if(!br && !bc) {
            return false;
         }
      }
   }
   return true;
}

int main() {
   int cases, nx, ny, t;
   cin >> cases;
   for(int i = 0; i < cases; ++i) {
      cin >> nx >> ny;
      vector<int> vb(ny);
      vector<vector<int> > lawn(nx, vb);
      for(int x = 0; x < nx; ++x) {
         for(int y = 0; y < ny; ++y) {
            cin >> t;
            lawn[x][y] = t;
         }
      }
      cout << "Case #" << i+1 << ": " << (isValid(lawn)?"YES":"NO") << "\n" << flush;
   }

   return 0;
}

