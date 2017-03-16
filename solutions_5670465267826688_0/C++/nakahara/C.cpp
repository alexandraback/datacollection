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

//Define multiplication of the quaternions
// [0 1 2 3 4 5 6 7] = [1 -1 i -i j -j k -k]
const int op[8][8]=
  {
    {0,1,2,3,4,5,6,7},
    {1,0,3,2,5,4,7,6},
    {2,3,1,0,6,7,5,4},
    {3,2,0,1,7,6,4,5},
    {4,5,7,6,1,0,2,3},
    {5,4,6,7,0,1,3,2},
    {6,7,4,5,3,2,1,0},
    {7,6,5,4,2,3,0,1}
  };

// a^b in quaternion
int pow(int a, int b){
  int prod=0;
  for(int i =0;i<b;i++){
    prod = op[prod][a];
  }
  return prod;
}

int main(){
  ifstream in("inputC");
  cin.rdbuf(in.rdbuf());
  ofstream out("outputC");
  cout.rdbuf(out.rdbuf());
  
  int cases;
  cin >> cases;
  
  for(int i = 1 ; i<=cases; i++){
    if(i != 1)
      cout << endl;
    cout << "Case #" << i << ": ";

    int length, mult;
    cin >> length >> mult;

    int total=0;
    int word[length];
    for(int j = 0; j<length; j++){
      char temp;
      cin >> temp;
      switch(temp){
      case 'i':
	word[j]=2;
	break;
      case 'j':
	word[j]=4;
	break;
      case 'k':
	word[j]=6;
	break;
      }
      total = op[total][word[j]];
    }
    
    if(pow(total,mult)!= 1){
      cout << "NO";
      continue;
    }

    int cur=0;
    int firsti;
    bool fail = true;
    for(firsti=0; firsti<length*mult; firsti++){
      int temp = firsti % length;
      cur = op[cur][word[temp]];
      if(cur == 2){
	break;
      }
    }
    cur=0;
    for(int j = firsti+1; j<length*mult; j++){
      int temp = j%length;
      cur = op[cur][word[temp]];
      if(cur == 4){
	cout << "YES";
	fail = false;
	break;
      }
    }
    if (fail)
      cout << "NO";
  }
  return 0;
}


