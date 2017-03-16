#include <iostream>
#include <map>
using namespace std;
bool test(int tester,map<int,bool> &coinset,int c) {
  map<int,bool>::reverse_iterator rit;
  for (rit = coinset.rbegin(); rit!=coinset.rend(); ++rit) {
    if (tester >= rit->first) {
      //      cout << tester <<" " << rit->first <<endl;
      int k = 0; 
      while (tester >=rit->first && k<c) {
	tester-=rit->first;
	k++;
      }
    }
  }
  return (tester != 0);
}
int updatefloatingceiling(int flor,map<int,bool> &coinset, int c) {
  int cei = 1000000001;
  int count = 0;
  map<int,bool>::reverse_iterator rit;
  for (rit = coinset.rbegin(); rit!=coinset.rend(); ++rit) {
    if (flor >= rit->first) {
      count += (rit->first*c);
    }
  }
  return count;
}
int main(){
  int t;
  cin >> t;
  for (int casecnt = 1; casecnt <=t;++casecnt) {
    int c,d,v;
    int coins[100];
    map<int,bool> coinset;
    coinset.clear();
    cin >> c >> d >> v;
    for (int i = 0; i < d; ++i) {
      cin >> coins[i];
      coinset[coins[i]] = true;
    }
    int ans = 0;
    int floatingceiling = 0;
    while (floatingceiling < v) {
      //      cout <<"floating ceiling:" << floatingceiling << endl;
      bool adding = test(floatingceiling+1,coinset,c);
      if (adding) {
	coinset[floatingceiling+1] = true;
	ans++;
	//	cout << "added\n";
      }
      floatingceiling = updatefloatingceiling(floatingceiling+1,coinset,c);
    }
    cout << "Case #" << casecnt <<": "<<ans <<endl;
  }
}
