#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int solve();

int main()
{
	int T;
	cin >> T;
	for(int i=1; i<=T; i++)
		cout << "Case #" << i << ": " << solve() << endl;
}

int solve()
{
  int A, N;
  vector <int> B;
  cin >> A >> N;
  for(int i=0; i<N; i++)
  {
    int temp;
    cin >> temp;
    B.push_back(temp);
  }

  sort(B.begin(), B.end());
  if(A == 1)
    return N;

  int ans = 100;
  for(int i=0; i<22; i++)
  {
    int index = 0;
    int count = i;
    unsigned long long C = A;
    while(index < N-i)
    {
      if(C > B[index])
      {
        C += B[index];
        index++;
      }
      else
      {
        C = C*2 - 1;
        count++;
      }
    }
    if(count < ans)
      ans = count;
  }
  return ans;
}

