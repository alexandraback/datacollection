#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cstdlib>
using namespace std;

void solve()
{
	double A[1005];
	map<double,int> B;
	double B2[1005];
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i ++)
		scanf("%lf", A + i);
	for(int i = 0; i < N; i ++)
	{
		double tmp;
		scanf("%lf", &tmp);
		if(B.find(tmp) != B.end()) 
			B[tmp] ++;
		else
			B[tmp] = 1;
		B2[i] = tmp;
	}
	/* compute the war score */
	int ws = 0;
	for(int i = 0; i < N; i ++)
	{
		map<double,int>::iterator it = B.upper_bound(A[i]);
		if(it == B.end())
			it = B.begin();
		double key = it->first;
		if(it->second == 1)
			B.erase(key);
		else
			B[key] --;
		if(key < A[i]) ws ++;
	}
	/* compute the cheated version */
	int ds = 0;
	sort(A, A + N);
	sort(B2, B2 + N);
	int al = 0, ar = N;
	int bl = 0, br = N;
	for(int i = 0, j = N - 1; i < N; i ++, j --)
	{
		if(A[ar-1] > B2[br-1]) 
		{
			ar --;
			br --;
			ds ++;
		}
		else
		{
			al ++;
			br --;
		}
	}
	printf("%d %d\n",ds,ws);
	return ;
}
int main()
{
	int T;
	scanf("%d", &T);
	for(int i = 0 ; i < T; i  ++)
	{
		printf("Case #%d: ", i + 1);
		solve();
	}
}
