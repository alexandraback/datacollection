#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream ein;
FILE * aus;
int TestCase;

void start()
{
	printf("%d\n", TestCase);
  int result;
	// read test case
	int N,M,K;
	ein >> N >> M >> K;
	int mi;
	if ((K<=4) || (N<=2) || (M<=2))
		mi = K;
	else
	{
		mi =N*M+1000;
	for (int n=2;n<N;n++)
	{
		for (int m=2;m<M;m++)
		{
			for (int t=0;t<=min(m,n);t++)
			{
				for (int s=t;s<=m;s++)
				{
					for (int v=t;v<=n;v++)
					{
						for (int l=0;l<=min(v,s);l++)
						{
							int pts;
							pts = (n+1)*(m+1) - t*(t+1)/2 - (n-v)*(n-v+1)/2 - (m-s)*(m-s+1)/2 - l*(l+1)/2;
							int bdr;
							bdr = 2*(n+m) - t - (n-v) - l - (m-s);
							if ((pts >= K) && (bdr <= mi))
							{
								mi = bdr;
							}
						}
					}
				}
			}
		}
	}
	}

	// output result
    fprintf(aus, "Case #%d: %d\n", TestCase, mi);     // %llu , %ll
}

void main()
{
	int NumTestCases;	
	ein.open("C-small-attempt0.in");
	aus = fopen("ausgabe.txt","w");
	
	ein >> NumTestCases;
	for (TestCase = 1; TestCase <= NumTestCases; TestCase++)
		start();

	fclose(aus);
	ein.close();
}
