#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<complex>
#include<numeric>
using namespace std;

int pw[20];
int arr[100], s;
long long run()
{
	int A, B;
	scanf("%d %d", &A, &B);
	int L = 0, tmp = A, n;
	for(; tmp > 0; tmp /= 10, ++ L);
	long long ret = 0;
	for(int m=A+1;m<=B;++m)
	{
		s=0;
		for(int i=1; i < L; ++ i)
		{
			n = m / pw[i] + (m % pw[i]) * pw[L-i];
			if(n < m && n >= A) arr[s ++] = n;
		}
		sort(arr, arr + s);
		s = unique(arr, arr + s) - arr;
		ret += s;
	}
	return ret;
}

int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	
	pw[0]=1;
	for(int i=1;i<20;++i)pw[i]=pw[i-1]*10;
	
	int test;scanf("%d", &test);
	for(int no=1;no<=test;++no)
		printf("Case #%d: %lld\n", no, run());
}
