#include <fstream>
#include <string.h>

#define SIZE 3000

using namespace std;
int main()
{
	ifstream infile("B-large.in");
	ofstream outfile("B-output");

	int t;
	infile >> t;
	for (int ca = 1; ca <= t; ++ca)
	{
		int n;
		infile >> n;
		int f[SIZE];
		memset(f, '\0', sizeof(f));
		for (int i = 1; i <= 2*n-1; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				int x;
				infile >> x;
				f[x] += 1;
			}
		}
		outfile << "Case #" << ca << ":";
		for (int i = 1; i <= SIZE; ++i)
			if (f[i] % 2 == 1)
				outfile << " " << i;
		outfile << endl; 
	}

	return 0;
}