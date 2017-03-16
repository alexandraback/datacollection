#include <iostream>
#include <cmath>
#include <set>
#include <utility>
using namespace std;

int main(void){
 int T,A,B;
 cin >> T;
 for(int t = 1; t <= T; ++t){
  cout << "Case #" << t << ": ";
  cin >> A >> B;
  int length = (int)(log(A)/log(10)) + 1;
  if(A == 10 or A == 100 or A == 1000 or A == 10000 or A == 100000 or A == 1000000){
   length = (int)(log(A+1)/log(10)) + 1;
  }
  int number = 0;
  set<pair<int,int> > pairSet;
  for(int i = A; i < B; ++i){
   pairSet.clear();
   for(int j = 1; j < length; ++j){
    int a, b;
    a = pow(10,j);
    b = pow(10,length-j);
    int x = i / a;
    int z = b*(i%a);
    int pair = x+z;
    if(pair > i and pair <= B){
     unsigned int size = pairSet.size();
     pairSet.insert(make_pair<int, int>(i,pair));
     if(pairSet.size() != size){
      number++;
     }
    }
    
   }
  }
  cout << number << endl;
 }

}
