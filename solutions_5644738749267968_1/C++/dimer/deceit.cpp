#include <iostream>
#include <fstream>
#include <cstdlib>

#include <list>

using namespace std;

bool ken_strategy(double naomi, list<double> &ws) {
  if (naomi > ws.back()) {
    ws.pop_front();
    return false;
  } else {
    list<double>::iterator it;
    for (it=ws.begin();it!=ws.end();it++)
      if (*it > naomi) break;
    ws.erase(it);
    return true;
  }
}

bool pointwise_lt(list<double> &la, list<double> &lb) {
  list<double>::iterator ita, itb;
  for (ita = la.begin(), itb = lb.begin(); ita != la.end() && itb != lb.end(); ita++, itb++)
    if (*ita >= *itb) return false;
  return true;
}

int main () {
  ifstream input;
  input.open("input");

  int ntest;
  input >> ntest;

  for (int k=0;k<ntest;k++) {
    int N;
    double tmp;
    list<double> naomi,ken;
    input >> N;

    for (int i=0;i<N;i++) {
      input >> tmp; naomi.push_front(tmp);
    }
    for (int i=0;i<N;i++) {
      input >> tmp; ken.push_front(tmp);
    }

    naomi.sort();
    ken.sort();

    list<double> cnaomi(naomi), cken(ken);

    // War
    int warscore = 0;
    list<double>::iterator it;
    for (it=naomi.begin(); it!=naomi.end();it++)
      if (!ken_strategy(*it,ken)) warscore++;

    // Deceitful war
    int deceitscore = 0;
    while (!pointwise_lt(cken, cnaomi)) {
      cnaomi.pop_front();
      cken.pop_back();
    }
    deceitscore = cnaomi.size();

    cout << "case #" << k+1 << ": " << deceitscore << " " << warscore << endl;
  }

  input.close();
  return 0;
}
