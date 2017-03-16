#include <map>
#include <iostream>

using namespace std;

// struct Triplet {
//   int a;
//   int b; 
//   int k;
//   const bool operator< (const Triplet& compared) {
//     if(a == compared.a) {
//       if(b == compared.b) {
// 	return c < compared.c;
//       }
//       return b < compared.b;
//     }
//     return a < compard.a;
//   };
// };

bool checkLastBitOne(int number) {
  int shifted = (number >> 1) << 1;
  return shifted ^ number;
}


// this function does not accept zero
int setLastBitOne(int number) {
  if (checkLastBitOne(number))
    return number;
  else {
    int result = number;
    int bitshifted = 0;
    while (checkLastBitOne(result)) {
      result = result >> 1;
      bitshifted++;
    }
    result = (result >> 1) << 1;
    for(int i = 0; i < bitshifted; i++)
      result = (result << 1) | 1;
    return result;
  }
}

long calculate(int a, int b, int x) {
  if (a == 0 && b == 0) {
    if (x == 0)
      return 1;
    else
      return 0;
  }
  if (checkLastBitOne(x)) {
    int newa = 0;
    if (a != 0)
      newa = setLastBitOne(a) >> 1;
    int newb = 0;
    if (b != 0)
      newb = setLastBitOne(b) >> 1;
    
    
    long result = calculate(newa, newb, x >> 1);
    return result;
  }
  else {
    int twozero = calculate(a >> 1, b >> 1, x >> 1);
    int onezero = 0;
    if (b != 0) {
      printf("calling onezerob with %d %d %d\n" , a>>1, setLastBitOne(b) >> 1, x>>1);
      onezero = calculate(a >> 1, setLastBitOne(b) >> 1, x >> 1);
    }
    int onezero2 = 0;
    if (a != 0) {
      printf("calling onezeroa with %d %d %d\n", setLastBitOne(a) >> 1, b>> 1, x >> 1);
      onezero2 = calculate(setLastBitOne(a) >> 1, b >> 1, x >> 1);
    }
    cout << "a b x is " << a << b << x << endl;

    cout << "twozero " << twozero << " onezerob " << onezero << " onezeroa " << onezero2 << endl;
    long result = twozero + onezero + onezero2;
    return result;
  }
}


long solve(int a, int b, int k) {
  long result = 0;
  for(int i = 0; i < a; i++) {
    for(int j = 0; j < b; j++) {
      if ((i & j) < k)
	result++;
    }
  }
  return result;
}

int main() {
  int cases;			
  cin >> cases;
  for(int i = 0; i < cases; i++) {
    int a, b, k;
    cin >> a >> b >> k;
    cout << "Case #" << i+1 << ": " << solve(a, b, k) << endl;
  }
  return 0;
}
