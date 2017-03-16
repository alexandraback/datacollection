#include<stdio.h>
#include<string.h>
#include<math.h>
#include<list>
#include<map>
#include<stack>
#include<queue>

using namespace std;

int main()
{
	int T,N;
	int F[10000];
	freopen("C-small-attempt1.in","r",stdin);
	freopen("C-small-attempt1.out","w",stdout);
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%d",&N);
		for(int j=0;j<N;j++)
		{
			scanf("%d", &F[j+1]);
		}
		list<int> X;
		int kid=0;
		bool G[10000]={false};
		X.push_back(1);
		kid++;
		G[1]=true;
		while(true)
		{
			if(!G[F[X.back()]])
			{
				G[F[X.back()]]=true;
				kid++;
				X.push_back(F[X.back()]);
			}
			else if(F[F[X.back()]]==X.back())
			{
				for(int k=0;k<N;k++)
					if(F[k+1]==X.back() && !G[k+1])
					{
						kid++;
						break;
					}
				break;
			}
			else
			{
				for(int k=0;k<N;k++)
					if(F[k+1]==X.back())
					{
						kid++;
						break;
					}
				kid--;
				break;
			}
		}
		printf("Case #%d: %d\n",i+1,kid);
	}
	return 0;
}