#include <iostream>
#include <random>
#include <time.h>
#include <limits>
#include <vector>
#include <sstream>
#include <algorithm>
#include <functional>
#include <array>

using namespace std;


class Instance{
public:
  void read();
  void write();

  void compute();
private:
  int _n;
  vector<int> _result;
  vector<vector<int> > _arrays;
};


void Instance::read()
{
  cin >> _n;
  /*cout << "Found " << _n << endl;*/
  for (int i = 0; i < _n; ++i) {
    _result.push_back(0);
    vector<int> v;
    _arrays.push_back(v);
    int d;
    cin >> d;
    for (int j = 0; j < d; ++j) {
      int n;
      cin >> n;
      _arrays[i].push_back(n);
    }
    //std::sort(_arrays[i].begin(), _arrays[i].end(), std::greater<int>());
  }
}


void Instance::write()
{
  for (int i = 0; i < _n; ++i) {
    cout << "Case #"<< i+1 << ": " << _result[i] << endl;

/*    for (int j = 0; j < _arrays[i].size(); ++j) {
      cout << _arrays[i][j] << " ";
    }
    cout << endl;*/
  }

}


void Instance::compute()
{
  for (int i = 0; i < _n; ++i){
    vector<int> array = _arrays[i];

//cout << endl <<  "case" << i+1 << endl;

    std::sort(array.begin(), array.end(), std::greater<int>());

    int min_num = array[0];

    //cout << array[0] << endl;

    for (int unspecial = 1; unspecial < min_num; unspecial++){
      int special = 0;
      for (int c = 0; c < array.size(); ++c){
         int d = array[c];
         if (d <= unspecial) {
          break; // Remaining need not to be split
         }
         int r = d/unspecial;
         if (d % unspecial == 0){
           r--;
         }
         special += r;
         if (special + unspecial >= min_num) {
           break;
         }
      }
      if (special + unspecial < min_num) {
        min_num = special + unspecial;
   //     cout << " " << special << " + " << unspecial << endl;
      }
    }
    _result[i] = min_num;


#if 0
    // First upper bound:
    int min_num = array[0];

    int iter = 0;
    while ((min_num > iter) && (array[0] > 0)) {
      // Add special round where the highest puile is split into two nearly equal sized parts
      iter++;
      int split = array[0] / 2;
      array[0] -= split;
      array.push_back(split);
      std::sort(array.begin(), array.end(), std::greater<int>());
      if (iter + array[0] < min_num) {
        min_num = iter + array[0];
      }
    }
    _result[i] = min_num;
#endif
  }
}

int main(int argc, char** argv){
  Instance I;
  I.read();
  I.compute();
  I.write();
}
