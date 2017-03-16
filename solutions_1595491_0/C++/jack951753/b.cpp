#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int add[3]={3,2,4};
int main()
{
	int T;
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&T);
	for(int k=1;k<=T;k++)
	{
		int n,s,p,t,ans=0;
		scanf("%d%d%d",&n,&s,&p);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&t);
			int t1=t/3+int(t%3>0),t2=0;
			if(t>=2)
				t2=(t+add[t%3])/3;
			if(t1>=p)
				ans++;
			else
				if(t2>=p&&s>0)
					s--,ans++;	
			//printf("%d %d %d %d %d|",t1,t2,t1>=p,t2>=p,s);
		}
		printf("Case #%d: %d\n",k,ans);
	}
}