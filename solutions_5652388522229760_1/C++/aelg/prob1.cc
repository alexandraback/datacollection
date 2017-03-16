
#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;

  for(int i = 0; i < n; ++i){
    cout << "Case #" << i+1 << ": ";
    int current, starting, seen = 0;
    cin >> starting;
    if(starting == 0) {
      cout << "INSOMNIA\n";
      continue;
    }

    current = 0;
    do{
      current += starting;
      int tmp = current;
      while (tmp != 0){
        seen = seen | (1 << (tmp % 10));
        tmp = tmp / 10;
      }
    }while(seen != 0b1111111111);
    
    cout << current << '\n';
  }
  return 0;
}
