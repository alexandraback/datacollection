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

char arr[1000005];
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("outputt.txt","w",stdout);
	int t; S(t);
	REP(t1,t)
	{
		scanf("%s", &arr);;
		int n, l, ans = 0, sup = 0, cnt = 0;
        S(n);
		l = strlen(arr );
		REP(i, l)
		{
			if(arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u')
			cnt=0;
			else cnt++;
			if(cnt>=n)
			{
				ans+=i+1-n+1;
				sup=i+2-n;
			}
			else if(sup)
			ans += sup;
		}			
		printf("Case #%d: %d\n", t1+1, ans);
	}
	return 0;
}
