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
  int _n;
  vector<bool> _result;
  vector<int> _x;
  vector<int> _r;
  vector<int> _c;
  vector<long> _rep;
};



void Instance::read()
{
 cin >> _n;
  /*cout << "Found " << _n << endl;*/
  for (int i = 0; i < _n; ++i) {
    _result.push_back(false);
    int x,r,c;
    cin >> x;
    cin >> r;
    cin >> c;

    _x.push_back(x);
    if (r > c) {
      _r.push_back(r);
      _c.push_back(c);
    } else {
      _r.push_back(c);
      _c.push_back(r);
    }
  }
}


void Instance::write()
{
   for (long i = 0; i < _n; ++i) {
    cout << "Case #"<< i+1 << ": " << (_result[i]? "GABRIEL":"RICHARD") << endl;
  }
}


void Instance::compute()
{
  for (long i = 0; i < _n; ++i){
    _result[i] = false;

// As there are only 64 possible cases for small instnaces, we can enumerate all cases ...
    int x = _x[i];
    int r = _r[i];
    int c = _c[i];
    // r >= c;

    if ((r*c)%x != 0) {
      _result[i] = false;
      continue;
    }
    if ((r < x) && (c < x)) {
      _result[i] = false;
      continue;
    }
    if (x==1) {
      _result[i] = true;
      continue;
    }
    if (x==2) {
      _result[i] = true;
      continue;
    }
    if (x==3) {
      // r >= 3;
      if (c == 1) {
       // XX
       // X
        _result[i] = false;
        continue;
      }
      _result[i] = true;
      continue;
    }


    if (x>=7) {
      _result[i] = false;
      continue;
    }

    // 4<=x<=6
    if ((c==1) || (c==2)) {
      _result[i] = false;
      continue;
    }

    if (x==4) {
     // => r = 4, c> 2
     _result[i] = true;
     continue;
    }

    if (c>=4) {
      // This works always for 5 and 6 dominoes with the given preliminaries
      _result[i] = true;
      continue;
    }

    // c==3
    if (x==5) {
      _result[i] = true;
      continue;

    }
    if (x==6) {
      _result[i] = false;
      continue;
    }
  }

}


int main(int argc, char** argv){
  Instance I;
  I.read();

  I.compute();

  I.write();
}
