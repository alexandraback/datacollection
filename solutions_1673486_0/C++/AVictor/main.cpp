#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<iomanip>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<memory.h>
#include<iomanip>
using namespace std;

typedef double ld;

ld p[100005];
ld M[100005];

int main()
{
	int T;
	cin>>T;
	for(int test=1;test<=T;test++)
	{
		int A, B;
		scanf("%d%d",&A,&B);
		for(int i=0;i<A;i++)
			scanf("%lf",&p[i]);

		for(int j=0;j<=A+1;j++)
			M[j]=0;
		ld mn = 1;
		for(int i=0;i<A;i++)
		{
			ld mn2 = mn*(1-p[i]); 
			for(int j=0;j<A-i;j++)
				M[j]+=mn2*(2*(j+B)-A+2);
			for(int j=A-i;j<=A;j++)
				M[j]+=mn2*(B-A+2*j+1);
			M[A+1]+=mn2*(B+2);
			mn*=p[i];
		}
		for(int j=0;j<=A;j++)
			M[j]+=mn*(B-A+2*j+1);
		M[A+1]+=mn*(B+2);
		ld ans = 1e9;
		for(int j=0;j<=A+1;j++)
			ans=min(ans, M[j]);
		printf("Case #%d: %.7lf\n", test, ans);

	}
	
	return 0;
}