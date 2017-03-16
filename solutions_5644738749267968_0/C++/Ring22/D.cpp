#include <vector>
#include <iostream>
#include <set>
#include <limits>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef long double DD;

int N = 0;
vector<DD> read()
{
  vector<DD> r(N);
  for(int i=0;i<N;i++)
    cin >> r[i];
  return r;
}

int main(int argc, char *argv[])
{
  int K = 0;
  cin >> K;
  for(int k=1;k<=K;k++) {
    cin >> N;
    vector<DD> A = read(), B = read();
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    int ans1=0, ans2=0;
    int j=0,i=0;
    for(;i<N;i++) {
      while(j<N && B[j] < A[i]) j++;
      if( j == N )
	break;
      j++;
    }
    ans2 = N-i;

    for(j=0,i=0;i<N;i++) {
      if( A[i] > B[j] )
	j++;
    }
    ans1 = j;

    printf("Case #%d: %d %d\n",k,ans1,ans2);
  }
  return 0;
}
