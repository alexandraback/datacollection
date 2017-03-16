#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <math.h>
using namespace std;

//trocar para 0 para desabilitar output
#if 1
#define DEBUG(x) cout << x << endl
#define PAUSE() cin.get(); cin.get()
#else
#define DEBUG(x)
#define PAUSE()
#endif

#define TRACE(x) DEBUG(#x << " = " << x)
#define DEBUGS() DEBUG("***************************")
#define MAX 1000

int high[MAX];

typedef struct attack{
  int day, begin, end, strength;
}attack;

bool ord(const attack &a, const attack &b){
  if (a.day == b.day) return a.strength < b.strength;
  return a.day < b.day;
}

int sucess(vector<attack> attacks){
  int desv = MAX/2, total = 0;
  fill(high, high+MAX, 0);
  for (int i = 0; i < attacks.size(); ++i){
    bool ok = false;
    for (int j = attacks[i].begin; j < attacks[i].end; ++j){
      if (high[j+desv] < attacks[i].strength && !ok){
	ok = true;
	++total;
      }
      high[j+desv] = max(high[j+desv], attacks[i].strength);
    }
  }
  return total;
}

int main(){
  int t, cases = 0;
  cin >> t;
  while (t--){
    int N, d, n, w, e, s, deltad, deltap, deltas;
    cin >> N;

    vector<attack> v;
    for (int i = 0; i < N; ++i){
      cin >> d >> n >> w >> e >> s >> deltad >> deltap >> deltas;
      for (int j = 0; j < n; ++j){
	attack aux;
	aux.day = d+(deltad*j);
	aux.begin = w+(deltap*j);
	aux.end = e+(deltap*j);
	aux.strength = s+(deltas*j);
	v.push_back(aux);
      }
    }
    sort(v.begin(), v.end(), ord);
    cout << "Case #" << ++cases << ": " << sucess(v) << endl;
  }
  return 0;
}
