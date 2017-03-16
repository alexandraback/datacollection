#include <iostream>
#include <string>
#include <vector>

char mymin(char a, char b){
  return std::min(a,b);
}
void solve(std::string a, std::string b){
  int i = 0;

  while(i < a.size() && (a[i] == '?' || b[i] == '?' || a[i] == b[i])) {
    if(a[i] == '?' && '?' == b[i]) {
      a[i] = '0';
      b[i] = '0';
    } else if (a[i] == '?') {
      a[i] = b[i];
    } else {
      b[i] = a[i];
    }
    ++i;
  }

  if(i < a.size()) {
    const char cmp = b[i] > a[i] ? 1 : -1;

    for(; i < a.size(); ++i){
      if(a[i] == '?' && b[i] != '?')
        a[i] = std::max(mymin('9',b[i] + cmp), '0');
      else if(a[i] != '?' && b[i] == '?')
        b[i] = std::max(mymin('9',a[i] - cmp), '0');
      else if(a[i] == '?' && b[i] == '?'){
        a[i] = cmp > 0 ? '9' : '0';
        b[i] = cmp < 0 ? '9' : '0';
      }
    }
  }
  std::cout << a << " " << b;
}

int main(){
  int t;
  std::cin >> t;
  for(int i = 1; i <= t; ++i){
    std::string a, b;
    std::cin >> a >> b;
    std::cout << "Case #" << i << ": ";
    solve(a,b);
    std::cout << "\n";
  }
}