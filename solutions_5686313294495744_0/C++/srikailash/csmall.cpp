#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807LL
#define INF 2000000000
#define PI acos(-1.0)
#define inf INT_MAX
using namespace std;
typedef long long int LL;
multiset<string > FF , BF , FS , BS;

int test , N;
string A[1010] , B[1010];

int main()
{
int ANS , ans[1010] , ans2[1010];
scanf("%d",&test);
for(int o=1;o<=test;o++)
{
	FF.clear();
	FS.clear();
	printf("Case #%d: ", o);
	memset(ans, 0 , sizeof(ans));
	memset(ans2 , 0 , sizeof(ans2));

	ANS = 0;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		cin >> A[i] >> B[i];
	}
	for(int i=1;i<=N;i++)
	{
		if(FF.find(A[i])!=FF.end())
			ans[i] = 1;
		FF.insert(A[i]);
	}
	FF.clear();
	FS.clear();
	for(int i=N;i>=1;i--)
	{
		if(FF.find(A[i])!=FF.end())
			ans[i] = 1;
		FF.insert(A[i]);
	}
	FF.clear();
	FS.clear();
	for(int i=1;i<=N;i++)
	{
		if(FF.find(B[i])!=FF.end())
			ans2[i] = 1;
		FF.insert(B[i]);
	}
	FF.clear();
	FS.clear();
	for(int i=N;i>=1;i--)
	{
		if(FF.find(B[i])!=FF.end())
			ans2[i] = 1;
		FF.insert(B[i]);
	}


	for(int i=1;i<=N;i++)
		ANS = ANS + ans[i]*ans2[i];
	cout << ANS << endl;
}
return 0;
}










