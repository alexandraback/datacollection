#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cstring>
#include <limits>

using namespace std;

#define FOR(I,A,B) for(int I= (A); I<(B); ++I)
#define REP(I,N) FOR(I,0,N)
#define S(N) scanf("%d", &N)
#define SL(N) scanf("%lld", &N)
#define PB push_back
#define MP make_pair
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define cell pair<int,int>
#define edge pair<int, cell>
typedef vector<char *> vs;
typedef long long int LL;
typedef vector<int> vi;
typedef vector<LL> vii;
int main()
{
	int t;S(t);
	REP(t1,t)
	{
		int a,n,ans;S(a);S(n);
		vi v;int k[100];
		printf("Case #%d: ", t1+1);
		REP(i,n)
		{
			int x;S(x);
			v.PB(x);
		}
		sort(v.begin(),v.end());
		if(a==1){printf("%d\n",n);continue;}
		int count=0;ans=n;
		REP(i,n)
		{
			while(v[i]>=a)
			{
				count++;
				a=2*a-1;
			}
			k[i]=count+n-i-1;
			if(k[i]<ans)
               ans=k[i];
           	a=a+v[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}

