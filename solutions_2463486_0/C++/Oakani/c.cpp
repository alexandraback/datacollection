#include <iostream>
using namespace std;

int main()
{
  int fairNSquare[1001];
  for(int i=0;i<1001;i++) fairNSquare[i] = 0;
  /*
  for(int i=0;i<32;i++) 
  {
    cout << i*i << " "; 
    // 0 1 4 9 16 25 36 49 64 81 100 121 144 169 196 225 256 289 324 361 400 441 484 529 576 625 676 729 784 841 900 961
  }
  // palindromes are 0 1=1*1 4=2*2 9=3*3 121=11*11 484=22*22 676 = 26*26
  // Fair and Square numbers are 0 1 4 9 121 484
  */
  fairNSquare[0] = 1; fairNSquare[1] = 1; fairNSquare[4] = 1; fairNSquare[9] = 1; fairNSquare[121] = 1; fairNSquare[484] = 1;
  
  int T;
  cin >> T;
  int caseNum = 1;
  
  while(caseNum <= T)
  {
    int A,B;
    cin >> A >> B;
    
    int sum = 0;
    for(int i=A;i<=B;i++) sum += fairNSquare[i];
    cout << "Case #" << caseNum << ": " << sum << endl;
  
    caseNum++;
  }

  return 0;
}
