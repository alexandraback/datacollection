#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <fstream>
#include <utility> 
using namespace std;

// Shortcuts for common data type
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef set<int> si;

int main(){
  ifstream in("input");
  cin.rdbuf(in.rdbuf());
  ofstream out("output");
  cout.rdbuf(out.rdbuf());
  
  int cases;
  cin >> cases;
  
  for(int i = 1 ; i<=cases; i++){
    if(i != 1)
      cout << endl;
    cout << "Case #" << i << ": ";

    int size;
    cin >> size;
    int plates[size];
    int temp;
    int max=1;
    for (int j=0; j<size; j++){
      cin >> temp;
      max = (temp> max) ? temp:max;
      plates[j]=temp;
    }

    int mintime = max;
    
    for(int bound = max; bound >0; bound--){
      //      cout << "bound = " << bound << endl;
      int curtime = 0;
      int curmax = 1;
      for(int j = 0; j<size; j++){
	if(plates[j] > bound){
	  //	  cout << "pancakes = " << plates[j]<<endl;
	  temp = plates[j]/bound - (plates[j] % bound == 0);
	  curtime += temp;
	  temp++;
	  //	  cout << j << " big" << "temp = " << temp << endl;
	}else{
	  temp = 1;
	  //  cout << j << " small"<< endl;
	}
	curmax = (curmax < plates[j]/temp + (plates[j]%temp!=0)) ? plates[j]/temp + (plates[j]%temp!=0):curmax;
      }
      //      cout << "time:"<<curtime<< " max:" << curmax<<endl<< endl;
      mintime = (mintime > curtime + curmax)? curtime+curmax: mintime;
    }

    cout << mintime;
  }
  return 0;
}
