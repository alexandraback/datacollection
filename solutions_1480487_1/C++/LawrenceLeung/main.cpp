#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
 	int nCase;
 	scanf("%d", &nCase);
 	for (int cId = 1; cId <= nCase; cId++)
 	{
	 	int v[200];
	 	int N;
	 	scanf("%d", &N);
		for (int i =0 ; i < N; scanf("%d", &v[i++]));
		int sum = 0;
		for (int i = 0; i < N; sum += v[i++]);
		
		printf ("Case #%d:", cId);
		for (int i = 0; i < N; i++)
		{
			double top = 1;
 		   	double btm = 0;
 		   	double mid;
 		   	while(top - btm > 1e-8)
 		   	{
  				 mid = (top + btm) / 2;
				 double thres = v[i] + sum * mid;
				 double rem = 1 - mid;
				 //printf ("%.2f %.2f %.2f\n", top, btm, thres);
				 for (int j = 0; j < N && rem >= 0; j++) 
				 {
					if (j != i)
					{
						double req = (thres - v[j])/sum;
						if (req <= 0)
						{
						}
						else
						{
							rem -= req;
						}
					}
				 }
				 if (rem <= 0)
				 {
					 top = mid;
				 }
				 else
				 {
					 btm = mid;
				 }
			}
			printf (" %.5f", top*100);
		}
		printf ("\n");
	}
	
    return EXIT_SUCCESS;
}
