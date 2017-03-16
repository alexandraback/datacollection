
#include <iostream>

using namespace std;
  
int solve(){
  char in;
  char prev;
  int flips = 0;
  cin.get(in);
  prev = in;
  do{
    if(in != prev) ++flips;
    prev = in;
    cin.get(in);
  }while(in != '\n');
  if (prev == '-') ++flips;
  return flips;
}

int main(){
  int n;
  cin >> n;
 // char c
  cin.get();

  for(int i = 0; i < n; ++i){
    cout << "Case #" << i+1 << ": ";
    cout << solve() << '\n';
  }
  return 0;
}
