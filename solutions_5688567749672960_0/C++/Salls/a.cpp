#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

long long reverse(long long val) {
  long long result = 0;
  while(val > 0) {
    result *= 10;
    result += val%10;
    val /= 10;
  }
  return result;
}

long long count_digits(long long val) {
  long long result = 0;
  while(val > 0) {
    result += 1;
    val /= 10;
  }
  return result;
}

bool is_pow_10(long long val) {
  while(val > 9) {
    if (val%10 != 0)
      return false;
    val /= 10;
  }
  return val == 1;
}

long long get_all_to_9(long long &val) {
  long long count = 0;
  
  int num_digits = count_digits(val);
  // check
  long long mod = 10;
  for (int i = 0; i < num_digits-1; i++) {
    if ((val % mod) / (mod/10) != 0) {
      cout << "ERROR: " << "mod: " << mod << " res: " << (val % mod) / (mod/10) << endl;
    }
    val += 9*(mod/10);
    mod *= 10;
  }
  if ((val % mod) / (mod/10) != 1) {
    cout << "ERROR2: " << (val % mod) / (mod/10) << " " << mod << " ndigits: " << num_digits << " val: "<< val << endl;
  }
  val += 8*mod/10;

  long long base = 1;
  for (int i = 0; i < num_digits - num_digits/2; i++) {
    count += 9*base;
    base *= 10;
  }

  base = 1;
  for (int i = 0; i < num_digits/2; i++) {
    count += 9*base;
    base *= 10;
  }
  count -= 1;

  if (num_digits > 1) {
    count += 1; // reverse
  }

  return count;
}

long long get_all_to_n(long long &val, long long N) {
  int num_digits = count_digits(val);
  long long reversed_n = reverse(N);
  long long mod = 1;
  long long base = 1;
  long long count = 0;
  
  // corner case checks
  if (num_digits == 1) {
    count += N-val;
    val = N;
    return count;
  }
  
  
  mod = 1;
  for (int i = 0; i < num_digits - num_digits/2; i++) {
    mod *= 10;
  }  
  // corner case 1 no swapping needed
  if (is_pow_10(N / mod)) {
    count += N-val;
    val = N;
    return count;
  }
  
  mod = 1;
  for (int i = 0; i < num_digits/2; i++) {
    mod *= 10;
  }
  // corner case 2 cant swap correctly
  if (N % mod == 0) {
    count += get_all_to_n(val, N-1);
    val += 1;
    count += 1;
    return count;
  }
  
  
  mod = 1;
  for (int i = 0; i < num_digits - num_digits/2; i++) {
    mod *= 10;
  }
  count += reversed_n % mod;
  
  mod = 1;
  for (int i = 0; i < num_digits/2; i++) {
    mod *= 10;
  }
  count += N % mod;

  count -= 1;

  if (num_digits > 1) {
    count += 1; // reverse
  }
  val = N;
  return count;

}


int main() {
  int T;
  cin >> T;

  /*
  while(1) {
    long long X, tempN;
    cin >> X >> tempN;
    cout << "count: " << get_all_to_n(X,tempN) << endl;
    cout << "val: " << X << endl;
  
  }
  */


  for(int tt = 1; tt <= T; tt++) {
    long long N;
    cin >> N;
    
    long long curr = 1;
    long long number_said = 1;
    while(count_digits(N) > count_digits(curr)) {
      number_said += get_all_to_9(curr);
      number_said += 1;
      curr += 1;
    }
    
    // now curr has the same number of digits
    number_said += get_all_to_n(curr,N);
    

    cout << "Case #" << tt << ": " << number_said << endl;

  }

  return 0;
}
















