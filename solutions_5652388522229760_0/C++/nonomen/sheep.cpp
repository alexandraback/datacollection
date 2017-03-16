#include <iostream>
#include <bitset>

using namespace std;

int main(){
  int n;
  cin >> n;
  for(int i = 0;i<n;i++){
    long long v;
    int t = 0;
    cin >> v;
    cout << "Case #" << i+1 << ": ";
    if(v == 0){
      cout << "INSOMNIA" << endl;
      continue;
    }
    bitset<10> seen;
    while(!seen.all()){
      t++;
      long long i = v*t;
      while(i>0){
        seen[i%10] = true;
        i/=10;
      }
    }
    cout << v*t << endl;

  }
  return 0;
}
