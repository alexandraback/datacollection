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
#define LL long long
#define S(N) scanf("%d", &N)
#define SL(N) scanf("%lld", &N)
#define PB push_back
#define MP make_pair
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define cell pair<int,int>
#define edge pair<int, cell>
#define clear(x) memset(x,0,sizeof(x))
#define CHECK_BIT(var,pos) ((var) & (1<<(pos))
#define sp system("pause")
typedef vector<int> vi;
typedef vector<LL> vii;
cell dir[4]={cell(0,1), cell(1,0), cell(0,-1), cell(-1,0) };


int main()
{
	int t; S(t);
	REP(t1,t)
	{
		char a[1000009];cin>>a;
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
		printf("Case #%d: ", t1+1);
        cout<<ans<<endl;
	}
	return 0;
}
    
    
    
    
    
