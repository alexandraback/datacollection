#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main()
{
	int numCase, cases, E, energy, R, N, data[10000], i, j, upper, lower;
	long long answer = 0;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%i", &cases);
	for(numCase = 1; numCase <= cases; numCase++)
	{
		answer = 0;
		scanf("%i %i %i", &E, &R, &N);

		for(i = 0; i < N; i++)
			scanf("%i", &data[i]);

		sort(data, data + N);
		lower = 0;
		upper = N - 1;
		energy = E;

		answer += energy * data[upper--];
		energy = R;
		while(lower <= upper)
		{
			if(lower == upper)
			{
				answer += energy * data[lower];
				break;
			}
			else
			{
				if(energy == E)
				{
					answer += energy * data[upper];
					energy = R;
					upper--;
				} else if(energy * data[lower] + R * data[upper] < __min(E, energy + R) * data[upper])
				{
					lower++;
					energy = min(E, energy + R);
				} else if(data[lower] <= data[upper])
				{
					answer += energy * data[upper];
					upper--;
					energy = R;
				}
			}
		}
		
		printf("Case #%i: %lli\n", numCase, answer);
	}

	return 0;
}