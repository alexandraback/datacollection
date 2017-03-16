#include<cstdio>
using namespace std;
int main()
{
	int ntc; scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		printf("Case #%d: ",tc);
		int K,C,S;
		scanf("%d %d %d",&K,&C,&S);
		
		long long ans = K /C;
		if(ans * C  != K) ans ++;
	
		if(ans>S) 
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
	 int pos=1;
	long long tmp;
		while(pos<=K && pos!=0)
		{ tmp =pos;
		int ct= 2;
		///printf("entering  pos is %d\n",pos);
		while(ct<=C)
		{
			if(pos!= K)
			pos++;
			
			tmp = K * (tmp-1);  tmp+=pos;
		//	printf("tmp is %lld and ct is %lld\n",tmp,ct);
		//	if(pos==K) pos = 0;
			//else pos++;
			ct++;
		}
		printf("%lld ",tmp); 
		if(K==pos) break;
		else pos++;
		}
		printf("\n");
	}
}
