#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

struct data
{
	double time, position;
};

int main()
{
	int numCase, cases, N, M, i, j;
	double distance, checktime, root1, root2, diskriminan, root, traveled;
	float accel;
	double a, b, c, constant, gap;
	data mydata[2];

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%i\n", &cases);
	for(numCase = 1; numCase <= cases; numCase++)
	{
		scanf("%lf %i %i", &distance, &N, &M);
		for(i = 0; i < N; i++)
			scanf("%lf %lf", &mydata[i].time, &mydata[i].position);

		printf("Case #%i:\n", numCase);
		for(i = 0; i < M; i++)
		{
			scanf("%f", &accel);

			checktime = sqrt( distance * 2 / accel );
			if(N == 1 || mydata[0].position > distance || checktime > mydata[1].time) // no collision
				printf("%.7lf\n", checktime);
			else
			{
				a = 0.5 * accel;
				b = - (mydata[1].position - mydata[0].position) / mydata[1].time;
				c = - mydata[0].position;

				diskriminan = sqrt ( b * b - 4 * a * c );
				root1 = (-b + diskriminan) / (2 * a);
				root2 = (-b - diskriminan) / (2 * a);

				if(root1 < 0) root = root2;
				else root = root1;

				traveled = 0.5 * accel * root * root;
				gap = distance - traveled;
				printf("%.7lf\n", root + gap * mydata[1].time / (mydata[1].position - mydata[0].position));
			}
		}
	}

	return 0;
}