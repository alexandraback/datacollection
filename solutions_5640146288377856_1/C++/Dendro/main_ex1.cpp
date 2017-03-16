#include <iostream>
#include <random>
#include <time.h>
#include <limits>
#include <vector>
#include <sstream>
using namespace std;


class Instance{
public:
  void read();
  void write();

  void compute();
private:
 long long _n;
 vector<long long> _R;
 vector<long long> _C;
 vector<long long> _W;
 vector<long long> out;
};


void Instance::read()
{
  cin >> _n;

  for (long long i = 0; i < _n; ++i) {
    long long in;
    cin >> in;
    _R.push_back(in);
    cin >> in;
    _C.push_back(in);
    cin >> in;
    _W.push_back(in);
  }
}


void Instance::write()
{
   for (long long i = 0; i < _n; ++i) {
     cout << "Case #" << i+1 << ": " << out[i]  << endl;
   }

}




void Instance::compute()
{
  for (int i = 0; i < _n; ++i){
     long long R = _R[i];
     long long C = _C[i];
     long long W = _W[i];

     if (R==1) {
       long long res = ((C-1)/W)+W;

       if (W==1){
         res = C;
       } else if (W==C) {
         res = C;
       } else if (C%W == 0){
         //res -=1;
       }

       out.push_back(res);
     } else{
       long long res = (C/W);
       res *= R;
       res += W;
       if (W==1){
         res = C*R;
       } else
       if (W==C){
         res = W+R-1;
       } else if (C%W == 0){
         res -=1;
       }

       out.push_back(res);
      // cout << "Not implemented yet!";
     }
  }
}


int main(int argc, char** argv){
  Instance I;
  I.read();
  I.compute();
  I.write();
}
