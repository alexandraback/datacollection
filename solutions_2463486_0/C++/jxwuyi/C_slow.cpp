#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<cassert>
#include<complex>
#include<ctime>
using namespace std;

#define LL long long

vector<LL > A;

int S[100], n;

bool palind(LL k)
{
	n=0;
	for(; k>0; S[n++]=k%10, k/=10);
	for(int i=0;i<=n-1-i; ++ i)
		if(S[i]!=S[n-1-i]) return false;
	return true;
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	
	for(LL i = 1; i <= 10000000; ++ i)
	{
		if(palind(i) && palind(i*i))
			A.push_back(i*i);
	}
	int test;scanf("%d", &test);
	for(int no=1;no<=test;++no)
	{
		LL a,b;
		cin >> a >> b;
		LL sb = upper_bound(A.begin(), A.end(), b) - A.begin();
		LL sa = lower_bound(A.begin(), A.end(), a) - A.begin();
		printf("Case #%d: %d\n", no, sb - sa);
	}
}
