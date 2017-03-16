#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long ll;

 int main()
{
	//freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	//freopen("A.in","r",stdin);freopen("A.out","w",stdout);
	int testcase;
	
	int ans=0;
	
	scanf("%d",&testcase);
	for (int case_id=1;case_id<=testcase;case_id++)
	{
		ans=0;
		printf("Case #%d: ",case_id);
		int A,N;
		int m[100];
		int s[101];
		memset(m,0,sizeof(int)*100);
		memset(s,0,sizeof(int)*101);
		cin>>A>>N;
		for(int i=0;i<N;i++)
			cin>>m[i];
		sort(m,m+N);
		s[0]=N;
		if(A==1)
			ans=N;
		else
		{
		for(int i=0;i<N;i++)
		{
			
			int count=0;
			if(m[i]>=A)
			{
				while(1)
				{
					A=2*A-1;
					count++;
					if(A>m[i])
					{
						A=A+m[i];
						s[i+1]=s[i]-1+count;
						break;
					}
				}
			}
			else
			{
				A+=m[i];
				s[i+1]=s[i]-1;
			}
			
		}
		int max=200;
		for(int i=0;i<=N;i++)
		{
			max=max>s[i]?s[i]:max;
		}
		ans=max;
		}


		printf("%d",ans);
		printf("\n");
	}
	return 0;
}

