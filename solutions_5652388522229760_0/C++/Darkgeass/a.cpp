#include <iostream>
#include <cstring>

using namespace std;

int n,count,x;
bool vist[10];

int main(){
  int t; cin >> t;
  for(int cass = 1; cass <= t; ++cass){
    cin >> n;
    if(n == 0){
      cout << "Case #" << cass << ": INSOMNIA\n";
      continue;
    }
    count = 0,x = 0;
    memset(vist,0,sizeof(vist));
    while(count < 10){
      x += n;
      int y = x;
      while(y){
	if(!vist[y%10]) ++count;
	vist[y%10] = 1;
	y /= 10;
      }
    }
    cout << "Case #" << cass << ": " << x << '\n';
  }
}