#include <stdio.h>

int main()
{
	// normal:
	// (x,x,x)		= 3x
	// (x,x,x+1)	= 3x+1
	// (x,x+1,x+1)	= 3x+2
	//
	// so if normal,it best must be (t+2)/3,(t >= 0)
	//
	// surprising:
	// (x,x,x+2)	= 3x+2
	// (x,x+1,x+2)	= 3x+3 = 3(x+1)
	// (x,x+2,x+2)	= 3x+4 = 3(x+1)+1
	// 
	// so if surprising,it best must be (t+4)/3, (t >= 2)
	// for t = 0,1,it couldn't be surprising
	// 
	// surprising_best >= normal_best
	// 
	// for surprising_best < p,nomatter surprising,it not be in answer
	// for normal_best >= p,nomatter surprising,it must be in answer
	//
	static const size_t max_number = 100;

	int nCases = 0;scanf("%d",&nCases);
	for(int iCases = 1;iCases <= nCases;++iCases)
	{
		int n = 0,s = 0,p = 0,t = 0;scanf("%d%d%d",&n,&s,&p);
		int normal_g_p = 0,surprising_l_p = 0,middle = 0;			// normal best greater than or equal to p,surprising best less than p,others
		for(int i = 0;i < n;++i)
		{
			scanf("%d",&t);
			int normal_best = (t+2)/3,surprsing_best = (t+4)/3;
			if(0 == t || 1 == t) surprsing_best = normal_best;
			if(normal_best >= p) ++ normal_g_p;
			else if(surprsing_best < p) ++ surprising_l_p;
			else ++ middle;
		}
		int ans = normal_g_p;
		if(middle <= s) ans += middle;
		else ans += s;
		printf("Case #%u: %u\n",iCases,ans);
	}

	return 0;
}