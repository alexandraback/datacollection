#!/usr/bin/python3
"""
uint64_t calculate(uint64_t n, uint64_t i, uint64_t base){
  uint64_t result = 1;
  uint64_t tmp = base;
  while(i != 0){
    if(i%2) result += tmp;
    i = i/2;
    tmp = tmp * base;
  }
  tmp = 1;
  for(int j = 0; j < n-1; ++j){
    tmp *= base;
  }
  return result+tmp;
}

void solve(){
  int n, j, jamcoinsFound = 0;
  cin >> n >> j;
  cout << '\n';
  vector<int> divisors;
  for(int i = 0; i < 1000; ++i){
    divisors.clear();
    for(int base = 2; base <= 10; ++base){
      bool divisorFound = false;
      uint64_t num = calculate(n, i, base);
      for(int divisor = 2; divisor < 100000; ++divisor){
        if(num % divisor == 0){
          divisorFound = true;
          divisors.push_back(divisor);
          break;
        }
      }
      if(!divisorFound) break;
    }
    if(divisors.size() == 9){
      cout << calculate(n, i, 10);
      for(auto d : divisors){
        cout << " " << d;
      }
      cout << '\n';
      ++jamcoinsFound;
      if(jamcoinsFound == j) return;
    }
  }
}
"""


def calculate(n, i, base):
    result = 1
    tmp = base
    while i != 0:
        if i % 2 != 0:
            result = result + tmp
        i = i//2
        tmp = tmp*base
    tmp = 1
    for j in range(0, n-1):
        tmp = tmp * base
    return result+tmp


def solve():
    jamcoinsFound = 0
    inputList = list(map(int, input().split()))
    n = inputList[0]
    j = inputList[1]

    for i in range(0, 1000):
        divisors = []
        for base in range(2, 11):
            divisorFound = False;
            num = calculate(n, i, base)
            for divisor in range(2, 100000):
                if divisor >= num:
                    break
                if num % divisor == 0:
                    divisorFound = True
                    divisors.append(divisor)
                    break
            if not divisorFound: break
        if len(divisors) == 9:
            outLine = ""
            outLine += str(calculate(n, i, 10))
            for d in divisors:
                outLine += " " + str(d)
            print(outLine)
            jamcoinsFound += 1
            if(jamcoinsFound == j): return


def main():
    cases = int(input())
    for i in range(0, cases):
        print("Case #%d:" % (i+1,))
        solve()

main()