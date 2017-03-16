#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int A[36];
int B[36];
int C[36];

void decode(int *where, int p)
{
	int i;
	for(i = 0; i < 30; i ++)
	{
		where[i] = p%2;
		p/=2; 
	}
}
int dp[36][2][2][2];
int rec(int left, bool belowA, bool belowB, bool belowC)
{
	//cout << left << " " << belowA << " " << belowB << " " << belowC << endl;
	//getchar();

	if(left <= 0)
		return 1;

	if(dp[left][belowA][belowB][belowC] != -1)
		return dp[left][belowA][belowB][belowC];

	int i, j, k, ret = 0;
	for(i = 0; i <= (belowC || C[left-1]); i++)
	{
		int newBelowC = belowC || (i < C[left-1]);
		for(j = 0; j <= (belowA || A[left - 1]); j ++)
			for(k = 0; k <= (belowB || B[left - 1]); k ++)
			{
				if((j & k) != i)
					continue;

				int newBelowA = belowA || (j < A[left-1]);	
				int newBelowB = belowB || (k < B[left-1]);
				ret += rec(left - 1, newBelowA, newBelowB, newBelowC);
			}
	}

	return dp[left][belowA][belowB][belowC] = ret;
}
void solve()
{
	int a, b, c;
	cin >> a >> b >> c;
	 a--; b --; c --;
	 memset(A, 0, sizeof(A));
	 memset(B, 0, sizeof(B));
	 memset(C, 0, sizeof(C));
	 
	decode(A, a);
	decode(B, b);
	decode(C, c);
	int i;
	
	memset(dp, -1, sizeof(dp));

	printf ("%d\n", rec(30, 0, 0, 0));

}
int main ()
{

	int tt;
	scanf ("%d", &tt);

	int i;
	for(i = 0; i < tt; i ++)
	{
		printf ("Case #%d: ", i+1);
		solve();
	}

	return 0;
}