#include <stdio.h>

int maxe, regain, numact;

int sim(int* sig, int* vals)
{
	int energy = maxe;
	int ret = 0;
	int i;
	for(i = 0; i < numact; i++)
	{
		energy -= sig[i];
		if(energy < 0) return -1;
		ret += vals[i] * sig[i];
		energy += regain;
		if(energy > maxe) energy = maxe;
	}
	return ret;
}

int main()
{
	int cases;
	scanf("%d", &cases);
	
	int i;
	for(i = 0; i < cases; i++) 
	{
		scanf("%d", &maxe);
		scanf("%d", &regain);
		scanf("%d", &numact);
		
		int vals[numact];
		int sig[numact];
		int j;
		for(j = 0; j < numact; j++) 
		{
			scanf("%d", &vals[j]);
			sig[j] = 0;
		}
		
		int best = -1;
		while(1)
		{
			int res = sim(&sig, &vals);
			if(res > best) best = res;
			int loc = 0;
			while(loc < numact)
			{
				sig[loc]++;
				if(sig[loc] > maxe) 
				{
					sig[loc] = 0;
					loc++;
				}
				else break;
			}
			if(loc >= numact) break;
		}
		
		printf("Case #%d: %d\n", (i+1), best);
	}

}

