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
 vector<int> _max_s;
 vector<string> _arrays;
 vector<int> _results;
};


void Instance::read()
{
  cin >> _n;

  for (int i = 0; i < _n; ++i) {
    int s_max;
    string s;
    cin >> s_max;
    cin >> s;
    _max_s.push_back(s_max);
    _arrays.push_back(s);
    _results.push_back(0);

    if (s.length() != s_max+1) {
      cerr << "length does not fit!" << endl;
    }
  }
}


void Instance::write()
{
   for (int i = 0; i < _max_s.size(); ++i) {
     cout << "Case #" << i+1 << ": " << _results[i] << endl;
   }

}




void Instance::compute()
{
  for (int i = 0; i < _n; ++i) {
    string array = _arrays[i];
    int sum = 0;
    int additional = 0;
    for (int c = 0; c < array.length(); ++ c) {
      while (sum+additional < c) {
        additional++;
      }
      int a = array[c] - '0';
      sum += a;
    }
//    cout << "--- required " << additional << endl;
    _results[i]=additional;
  }

}


int main(int argc, char** argv){
  Instance I;
  I.read();
  I.compute();
  I.write();
}
