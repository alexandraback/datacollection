#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int n, ndiner, ans;
	int pdiner[1000];

	scanf("%d", &n);

	for(int j=0; j<n; j++)
	{
		scanf("%d", &ndiner);

		int max = 0;
		for(int i=0; i<ndiner; i++) {
			scanf("%d", &pdiner[i]);
			if(max < pdiner[i])
				max = pdiner[i];
		}

		int temp = 2;
		while(temp < max) {
			int a = 0;
			for(int k=0; k<ndiner; k++)
				a += ((pdiner[k] - 1)/temp);
			a += temp;

			max = min(max, a);
			temp++;
		}

	
		printf("Case #%d: %d\n", j+1, max);
	}

	return 0;
}