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
		printf("Case #%d: ", t1+1);
		char a[1000];cin>>a;
		int n;S(n);
		int l=strlen(a);
		int count=0;int ans=0;int tp=0;
		REP(i,l)
		{
			if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
				count=0;
			else count++;
			if(count>=n)
			{
				ans+=i+1-n+1;
				tp=i+2-n;
			}
			else if(tp)
				ans+=tp;
		}			
		cout<<ans<<endl;
	}
	return 0;
}

