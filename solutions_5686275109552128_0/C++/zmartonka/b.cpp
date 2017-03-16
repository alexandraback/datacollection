#include <stdio.h>
#include <vector>

using std::vector;

int main()
{
	int T;
	scanf("%d",&T);
	vector<int> values(1000,0);
	for(int tn = 0; tn<T; ++tn)
	{
		int num;
		scanf("%d",&num);
		for(int i = 0; i<num;++i)
		{
			scanf("%d",&values[i]);
		}
		int max = 1 << 30;
		for(int normalC = 1; normalC <=1000; ++normalC)
		{
			int round = normalC;
			for(int j = 0; j< num;++j)
			{
				round += (values[j]+(normalC-1)) / normalC - 1; 
			}
			if (round < max) max = round;
		}
		printf("Case #%d: %d\n",tn+1,max);
	}
	return 0;
}