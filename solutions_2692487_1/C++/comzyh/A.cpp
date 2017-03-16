#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int T,N,A,ANS;
int mote[1000009];
inline void minset(int &a,int b)
{
	if (b<a)
		a=b;
}
inline int getstep(int &a,int b)
{
	int ans=0;
	while (a<=b)
	{
		a<<=1;
		a--;
		ans++;
	}
	return ans;
}
int main()
{
	scanf("%d",&T);
	for (int TT=1;TT<=T;TT++)
	{
		scanf("%d%d",&A,&N);
		int i;
		for (i=1;i<=N;i++)
			scanf("%d",&mote[i]);
		sort(mote+1,mote+N+1);
		ANS=N;
		int step=0;
		if(A>1)
		{
			for (i=1;i<=N;i++)
			{
				if (step>ANS)
					break;
				minset(ANS,step+(N-i+1));
				step+=getstep(A,mote[i]);
				//printf("step=%d\n",step);
				A+=mote[i];
			}
			minset(ANS,step);
		}
		printf("Case #%d: %d\n",TT,ANS);
	}
	return 0;
}