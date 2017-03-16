#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <iomanip>

using namespace std;

double solve();

unsigned long long comb(int N, int R)
{
  unsigned long long ans = 1;
  R = max(R, N-R);
  for(int i=R+1; i<=N; i++)
    ans *= i;
  for(int i=1; i<=N-R; i++)
    ans /= i;
  return ans;
}

int main()
{
	int T;
	cin >> T;
  cout << fixed;
	for(int i=1; i<=T; i++)
		cout << "Case #" << i << ": " << setprecision(7) << solve() << endl;
}

double solve()
{
  int N,X,Y;
  cin >> N >> X >> Y;
  int M=1;
  while(M*(M+1)/2 < N) M+=2;
  if(X < 0)
    X *= -1;

  if(X+Y == 0)
    return 1.0;
  if(X+Y > M)
    return 0.0;
  if(X+Y <= M-2)
    return 1.0;
  
  int A = N-(M-2)*(M-1)/2;
  int Z = Y + 1;
  double ans = 0;
  if(Z == M)
  {
    assert(X == 0);
    return 0.0;
  }
  for(int i=0; i<=A; i++)
  {
    if(i >= Z)
      ans += comb(A,i);
    else if(A-i > M-1 && A-M+1 >= Z)
      ans += comb(A,i);
  }
  for(int i=0; i<A; i++)
    ans/=2;
  return ans;
}

