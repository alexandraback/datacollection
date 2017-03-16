#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <cstdio>
#include <set>
#include <unordered_map>
#include <iomanip>
using namespace std;
#define db(a) (cout << (#a) << " = " << (a) << endl)
typedef long long ll;

ll B,M;

ll A[64];
int G[64][64];

int main()
{
  ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int tt=0;tt<T;tt++)
	{
		cin>>B>>M;
		A[0] = 1;
		A[1] = 1;
		ll sum = 2;
		for(int i=0;i<64;i++) for(int j=0;j<64;j++) G[i][j] = 0;
		for(int i=2;i<=B;i++)
		{
			A[i] = sum;
			sum += A[i];
		}
//for(int i=2;i<=B;i++) db(A[i]);
			
		cout << "Case #" << tt+1 << ": ";
		if(A[B-1] < M) cout << "IMPOSSIBLE\n";
		else
		{
			cout << "POSSIBLE\n";
			for(int i=1;i<64;i++) for(int j=i+1;j<64;j++) G[i][j] = 1;
			int b=B-1;
			while(M > 0)
			{
				while(A[b-1] > M) b--;		
				G[0][B-b] = 1;
				M -= A[b-1];
				b--;
			}
			for(int i=0;i<B;i++) {for(int j=0;j<B;j++) cout << G[i][j]; cout << "\n";}
		}
	}
  return 0;
}
