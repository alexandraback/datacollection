#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(long long n)
{
  vector<int> v;
  while(n >= 10)
  {
    v.push_back(n % 10);
    n = n / 10;
  }
  v.push_back(n % 10);
  
  int i=0, j= v.size()-1;
  while(i < j)
  {
    if(v[i] != v[j]) return false;
    i++;
    j--;
  }
  return true;
}

int main()
{
  long long fairNSquare [40] = {0,1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004,};
  
  int T;
  cin >> T;
  int caseNum = 1;
  
  while(caseNum <= T)
  {
    long long A,B;
    cin >> A >> B;
    
    int sum = 0;
    for(int i=0;i< 40;i++) 
    {
      if(fairNSquare[i] >= A && fairNSquare[i] <= B) sum++;
    }
    cout << "Case #" << caseNum << ": " << sum << endl;
  
    caseNum++;
  }
  
  /*
  int M = 10000000;
  
  //int M = 1000;
  for(int i=0;i<M+1;i++)
  {
    if(isPalindrome(i)) cout << i << " ";
  }
  cout << endl;
  */
  
  /*
  long long n;
  cout << "{";
  while(cin >> n)
  {
    if(isPalindrome(n*n)) cout << n*n << ","; 
  }
  cout << "}";
  */

  return 0;
}
