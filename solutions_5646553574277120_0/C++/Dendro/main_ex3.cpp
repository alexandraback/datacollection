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
 vector< vector<long long> > _inst;
 vector<int> res;
 vector<int> _C;
 vector<int> _D;
 vector<int> _V;
 vector< vector<int> > _coins;
};


void Instance::read()
{
  cin >> _n;

  for (long long i = 0; i < _n; ++i) {
    int inp;
    cin >> inp;
    _C.push_back(inp);
    cin >> inp;
    _D.push_back(inp);
    cin >> inp;
    _V.push_back(inp);

    vector<int> nc;
    _coins.push_back(nc);
    for (int j = 0; j < _D[i]; ++j){
      cin >> inp;
      _coins[i].push_back(inp);
    }
  }
}


void Instance::write()
{
   for (long long i = 0; i < _n; ++i) {
     cout << "Case #" << i+1 << ": " << res[i] << endl;
   }

}



int find_smallest_false(vector<bool> &values)
{
  int sm = 0;
  for (int i = 1; i < values.size(); ++i) {
    if (!values[i]) {
      return i;
    }
  }
  return 0;
}

int add_all_feasible_values
( vector<bool> &values,
  int coin)
{
  for (int v = values.size()-1; v >= 0; v--) {
    if (values[v] == true) {
      int n = v+coin;
      if (n < values.size()) {
        values[n] = true;
      }
    }

  }

}



int  recusrive_add
(
  vector<bool> &values,
  vector <int> &coins,
  int min_pos,
  int counter,
  int & best)
{
 if (counter > best) {
  return 0;
 }
  int old_pos = find_smallest_false(values);
  if (min_pos > old_pos) {
    return 99;
  }

  for (int i = 0; i < coins.size(); ++i){
    if (min_pos == coins[i]) {
      return 99;
    }
  }
  vector<bool> v2;
  for (int i = 0; i < values.size(); ++i) {
    v2.push_back(values[i]);
  }
  add_all_feasible_values(v2, min_pos);
  counter++;

  if (find_smallest_false(values) == 0) {
    if (counter < best) {
       best = counter;
    }
    return 0;
  }

  for (int j= min_pos+1; j < values.size()-1; ++j) {
    recusrive_add(v2,coins,j,counter,best);
  }
}



void Instance::compute()
{
  for(int i = 0; i < _n; ++i) {
    int V = _V[i];
    int D = _D[i];
    int C = _C[i];
    int add_coins = 0;

    vector<bool> values;
    for (int j = 0; j < V+1; ++j){
      values.push_back(false);
    }
    values[0] = true;

    for (int j = 0; j < _coins[i].size(); ++j) {
      add_all_feasible_values(values, _coins[i][j]);
    }

    int pos = find_smallest_false(values);
    while (pos != 0) {
      add_coins++;
//     cout << "Adding " << pos << endl;
      add_all_feasible_values(values, pos);
      pos = find_smallest_false(values);
    }
//cout << "add_coins " << add_coins << endl;

    int best = add_coins;
    if (best > 0)
    for (int j = 1; j <= V; ++j){
     recusrive_add(values, _coins[i], j, 0, best);
    }


    res.push_back(best);
  }
}


int main(int argc, char** argv){
  Instance I;
  I.read();
  I.compute();
  I.write();
}
