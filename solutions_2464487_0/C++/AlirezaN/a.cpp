//In the Name of God
#include <iostream>

using namespace std;
typedef long long LL;

LL T , t , r , st , en;

inline bool f(LL mid){
  if(mid > (2 * 1000000000000000000LL) / mid || mid > (2 * 1000000000000000000LL) / (2 * r - 1))
    return false;
  return (mid * mid * 2 + (2 * r - 1) * mid <= t);
}

int main(){
  cin >> T;
  for(LL i = 0 ; i < T ; i++){
    cin >> r >> t;
    st = 1LL , en = 1000000000LL;
    while(st < en){
      LL mid = (st + en) / 2;
      //      if(i == 0)cout << st <<' ' << en << '\t';
      if(f(mid)){
	if(st == mid){
	  if(f(en))
	    st = en;
	  else
	    break;
	}
	else
	  st = mid;
      }
      else
	en = mid - 1;
    }
    cout << "Case #" << i + 1 << ": " << st << endl;
  }
  return 0;
}
