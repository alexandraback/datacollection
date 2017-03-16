#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef vector<double> vd;
typedef vector<bool> vb;

int war(vd naomi, vd ken){
  int ret = 0;
  int n = (int) naomi.size();
  vb used(n, false);
  for(int i = 0; i < n; ++i){
    double current = naomi[i];
    bool played = false;
    for(int j = n - 1; j >= 0 and not played; --j){
      if(not used[j]){
        if(ken[j] > current){
          used[j] = true;
          played = true;
        }
      }
    }
    if(not played){
      for(int j = n - 1; j >= 0 and not played; --j){
        if(not used[j]){
          used[j] = true;
          played = true;
        }
      }
      ++ret;
    }
  }
  return ret;
}

int deceitful(vd naomi, vd ken){
  int ret = 0;
  int n = (int) naomi.size();
  double maxnaomi = naomi[n - 1];
  int imink = n - 1, imaxk = 0;

  for(int i = 0; i < n; ++i){
    double minnaomi = naomi[i];
    double minken = ken[imink];
    double maxken = ken[imaxk];
    if(maxken > maxnaomi){
      imaxk++;
    } else if(minnaomi > minken){
      imink--;
      ++ret;
    } else {
      imaxk++;
    }
  }
  return ret;
}

int main(){
  int T;
  cin >> T;
  for(int c=1; c<=T; ++c){
    int N;
    cin >> N;
    vd naomi(N), ken(N);
    for(int i = 0; i < N; ++i)
      cin >> naomi[i];
    for(int i = 0; i < N; ++i)
      cin >> ken[i];
    sort(naomi.begin(), naomi.end());
    sort(ken.rbegin(), ken.rend());
    cout << "Case #" << c << ": " << deceitful(naomi, ken) << ' ' << war(naomi, ken) << endl;
  }
}
