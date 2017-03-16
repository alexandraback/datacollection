#include <iostream>
#include <vector>
#include <cassert>
#define X 4

using namespace std;

int solve();

bool isVowel(char a)
{
  if(a == 'a'||a == 'e'||a == 'i'||a == 'o' ||a == 'u')
    return true;
  return false;
}

int main()
{
	int T;
	cin >> T;
  for(int i=1; i<=T; i++)
    cout << "Case #" << i << ": " << solve() << endl;
}	

int solve()
{
  string A;
  int N, M;
  cin >> A >> N;
  M = A.size();
  long ans = 0;
  int last = -1;
  for(int i=0; i<N; i++)
    if(isVowel(A[i]))
      last = i;
  vector <int> B;
  for(int i=N-1; i<M; i++)
  {
    if(isVowel(A[i]))
      last = i;
    else if(i >= N + last)
      B.push_back(i);
  }
  B.push_back(10000);
//  for(int i=0; i<B.size(); i++)
//    cout << B[i] << endl;
  int bIndex = -1;
  for(int i=N-1; i<M; i++)
  {
//    cout << i << " " << bIndex << " " << B[bIndex] << endl;
//    cout << "B[bIndex+1] : i\t\t" << B[bIndex+1] << " : " << i << endl;
//    cout << "bIndex : B.size()\t" << bIndex << " : " << B.size() << endl;
    while(B.size() - bIndex > 0 && B[bIndex+1] <= i) bIndex++;
    if(bIndex >= 0 && B[bIndex] <= i)
    {
//      cout << "added : " << B[bIndex] - N + 2 << endl;
      ans += B[bIndex] - N + 2;
    }
  }
  return ans;
}
