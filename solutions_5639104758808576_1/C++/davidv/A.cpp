#include <cstdio>
#include <vector>

using namespace std;

void doCase()
{
	int smax;
	
	scanf("%d", &smax);
	
	vector<int> people(smax+1);
	
	for (int i=0; i<smax+1; i++)
	{
		char in;
		scanf(" %c", &in);
		
		people[i] = in-'0';
	}
	
	int added = 0;
	int total = 0;
	
	for (int i=0; i<smax+1; i++)
	{
		if (i > total)
		{
			added++;
			total++;
		}
		
		total += people[i];
	}
	
	printf("%d\n", added);
}

int main()
{
	int T;
	
	scanf("%d", &T);
	
	for (int i=0; i<T; i++)
	{
		printf("Case #%d: ", i+1);
		doCase();
	}
	
	return 0;
}
