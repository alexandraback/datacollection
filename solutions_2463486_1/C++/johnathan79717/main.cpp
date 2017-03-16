#include <iostream>

using namespace std;

/*
I found the fair array by Haskell

palindrome :: Show a => a -> Bool
palindrome x = s == reverse s where s = show x

[x | x <- [1..10000000], palindrome x]

[x * x | x <- p, palindrome $ x * x]
*/

long long fair[39] = {1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004};

int main() {
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    long long A, B;
    int i, j;
    cin >> A >> B;
    for(i = 0; i < 39; i++)
      if(fair[i] >= A)
        break;

    for(j = 38; j >= 0; j--)
      if(fair[j] <= B)
        break;


    cout << j - i + 1 << endl;
  }
}