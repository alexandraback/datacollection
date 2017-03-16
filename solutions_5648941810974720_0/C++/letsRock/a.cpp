#include <iostream>
#include <algorithm>
#include <vector>

typedef unsigned long long ull;
typedef long long ll;
using namespace std;

string n[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int hist[26];
string uni[] = {"Z","","W","","U","F","X","","G",""};
string uni2[] = {"","O","","R","","","","V","","I"};
int a[] = {4,3,3,5,4,4,3,5,5,4};
string s;

int check(int num, string * x){
  if(x[num].size() > 0){
    if(hist[x[num][0] - 'A'] > 0){
      int ret = hist[x[num][0] - 'A'];
      for(int i=0; i<a[num]; i++){
	hist[n[num][i] - 'A'] -= ret;;
      }
      return ret;
    }
  }
  return 0;
} 


int main(){

  int T;
  cin >> T;
  for(int i=0; i< T; i++){
    cin >> s;
    int co[10];
    for(int j=0; j<10; j++) co[j] = 0;
    for(int j=0; j<26; j++) hist[j] = 0;
    for(int j=0; j<s.size(); j++){
      hist[s[j] - 'A']++;
    }

    for(int j=0; j<10; j++){
      co[j] += check(j,uni);
    }
    for(int j=0; j<10; j++){
      co[j] += check(j,uni2);
    }
    cout << "Case #" << i+1 << ": ";
    for(int j=0; j<10; j++){
      for(int k=0; k<co[j]; k++){
	cout << j;
      }
    }
    cout << endl;
  }

}
