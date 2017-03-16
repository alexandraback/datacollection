#include <iostream>
#include <vector>
#include <string>

#define FOR(i,C) for(int i=0; i<C; i++)
#define FOR_REV(i,C) for(int i=C-1; i>=0; i--)

typedef long long ll_t;

using namespace std;

ll_t ans(ll_t E, ll_t R, vector<ll_t>& v);

int main(int argc, char* argv[]){
  int T;

  cin >> T;

  // read input
  ll_t c = 0;
  while( cin ){
    if( ++c > T ) return -1;

    ll_t E,R,N;
    vector<ll_t> v;
    cin >> E >> R >> N;

    ll_t tmp;
    for(int i=0; i<N; i++){
      cin >> tmp;
      v.push_back(tmp);
    }

    // output answer
    cout << "Case #" << c << ": " << ans(E,R,v) << endl;
  }
}

ll_t calc_gain(ll_t E, ll_t R, vector<ll_t>& v, int from, int to, ll_t startE, int endE);

ll_t ans(ll_t E, ll_t R, vector<ll_t>& v){
  return calc_gain(E,R,v,0,v.size()-1,E,0);
}

ll_t calc_gain(ll_t E, ll_t R, vector<ll_t>& v, int from, int to, ll_t startE, int endE){

  //cout << from << " -> " << to << endl;

  if( from == to ){
    //cout << "achieved " << from << " " << v[from] << " (remainedE-reservedE)" << (startE-endE) << endl;
    return v[from]*(startE-endE);
  }

  ll_t gain = 0;

  ll_t max   = 0;
  int  i_max = -1;
  for(int i=from; i<=to; i++){
    if( v[i] > max ){
      max = v[i];
      i_max = i;
    }
  }

  ll_t regain_before = (i_max-from)*R;
  ll_t regain_after  = (to-i_max)*R;

  ll_t remainedE = regain_before + startE;
  if( remainedE > E ){
    remainedE = E;
  }

  ll_t reservedE = endE - regain_after;
  if( reservedE < 0 ){
    reservedE = 0;
  }

  if( remainedE < reservedE ){ cout<< "is something wrong?" << endl; }
  gain += max*(remainedE-reservedE);

  //cout << "achieved " << i_max << " " << max << " (remainedE-reservedE)" << (remainedE-reservedE) << endl;;

  // before i_max
  if( i_max > from ){
    gain += calc_gain(E, R, v, from, i_max-1, startE, remainedE-R);
  }
  // after i_max
  if( i_max < to ){
    gain += calc_gain(E, R, v, i_max+1, to, reservedE+R, endE);
  }

  return gain;
}
