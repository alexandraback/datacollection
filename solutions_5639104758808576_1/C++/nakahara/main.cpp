#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <fstream>
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
    
    int needed=0;
    int standing=0;
    
    int bound;
    cin >> bound;
    
    char temp;
    int num;
    for (int j =0; j<=bound; j++){
      cin >> temp;
      num = temp - '0';
      if(num > 0){
	int diff = j - standing;
	if(diff > 0){
	  needed += diff;
	  standing += diff;
	}
	standing += num;
      }  
    }
    cout << needed;
  }
  return 0;
}

