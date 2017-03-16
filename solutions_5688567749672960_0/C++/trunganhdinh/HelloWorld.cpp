#include<bits/stdc++.h>

#define MIN(a, b) (((a) < (b))?(a):(b))
#define MAX(a, b) (((a) > (b))?(a):(b))

using namespace std;

const char INPUT[] = "HelloWorld.inp";
const char OUTPUT[] = "HelloWorld.out";

long long int calc(long long int number){
  //cerr << number << " ";
  if (number < 10){
    return number;
  }
  int numDigit = 0;
  int arr[20];
  long long int temp = number;
  while (temp > 0){
    arr[numDigit] = temp % 10;
    temp /= 10;
    ++ numDigit;
  }
  long long int result = 0;
  bool superSpecial = false;
  if (arr[0] > 0){
    for (int idDigit = 0; idDigit <= (numDigit - 1)/ 2; ++ idDigit){
      if (idDigit == 0){
        arr[0] = 1;
      } else {
        arr[idDigit] = 0;
      }
    }
  } else {
    for (int idDigit = 0; idDigit < numDigit; ++ idDigit){
      if (idDigit == 0){
        arr[idDigit] = 1;
      } else if (arr[idDigit] == 0 && idDigit <= (numDigit - 1)/2){
        arr[idDigit] = 0;
      } else if (arr[idDigit] == 0 && idDigit > (numDigit - 1)/2){
        arr[idDigit] = 9;
      } else {
        if (idDigit == numDigit - 1 && arr[idDigit] == 1){
          superSpecial = true;
          break;
        } else {
          if (idDigit > (numDigit - 1)/2){
            -- arr[idDigit];
            break;
          }
          while (idDigit <= (numDigit - 1)/2){
            arr[idDigit] = 0;
            ++ idDigit;
          }
          break;
        }
      }
    }
  }
  long long int decade = 1;
  long long int temp2 = 0;
  long long int temp3 = 0;
  for (int idDigit = 0; idDigit < numDigit; ++ idDigit){
    temp3 += arr[idDigit] * decade;
    decade *= 10;
  }
  decade = 1;
  for (int idDigit = numDigit - 1; idDigit > 0; -- idDigit){
    temp2 += arr[idDigit] * decade;
    decade *= 10;
  }
  result += number - temp3 + temp2 + 1;
  if (temp3 == decade * arr[0] + temp2){
    result -= 1;
  }
  if (superSpecial){
    result = 0;
  }

  //cerr << result << " " << decade << " " << temp3 << " " << temp2 << endl;

  if (decade == 1){
    return result;
  } else {
    return result + 1 + calc(decade - 1);
  }
}

int main(void){
  freopen(INPUT, "r", stdin);
  freopen(OUTPUT, "w", stdout);

  int numTest;
  cin >> numTest;

  for (int idTest = 0; idTest < numTest; ++ idTest){
    long long int result = 0;
    long long int number;
    cin >> number;

    result = calc(number);

    /*int * f = new int[number + 10];

    for (int id = 1; id <= number; ++ id){
      f[id] = id;
    }

    int arr[20];

    for (int id = 2; id < number; ++ id){
      f[id] = MIN(f[id], f[id - 1] + 1);
      int numDigit = 0;
      long long int temp = id;
      while (temp > 0){
        arr[numDigit] = temp % 10;
        temp /= 10;
        ++ numDigit;
      }
      int decade = 1;
      int temp2 = 0;

      for (int idDigit = numDigit - 1; idDigit >= 0; -- idDigit){
        temp2 += arr[idDigit] * decade;
        decade *= 10;
      }
      //cerr << id << " " << temp2 << endl;
      if (temp2 > id && temp2 <= number){
        f[temp2] = MIN(f[temp2], f[id] + 1);
      }
      //cerr << "ba" << endl;
    }
*/
    cout << "Case #" << idTest + 1 << ": " << result << endl; //" " << MIN(f[number],f[number - 1] + 1) << endl;

  //  delete[] f;

  }

  return 0;
}
