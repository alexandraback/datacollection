#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

main()
{
	int i, j, T, d, l; 
	double p[100001];
	double prob[100001], prob1;
	cin >> T;
	for (i = 1; i <= T; ++i)
	{
		prob1 = 1;
		cin >> d >> l;
		memset(prob, 1, sizeof(double)*d);
		for (j = 0; j < d; ++j)
		{
			cin >> p[j];
			prob1*=p[j];
		}
		prob[0] = p[0];
		for (j = 1; j < d; ++j)
			prob[j] = prob[j-1]*p[j];
		prob1 = 1 - prob1;
		double keykeep = l - d + 1 + prob1*(l+1);
		int apag;
		for (j = d - 2; j >= 0; --j)
		{
			apag = d - j - 1;
			if           (2*apag + l - d + 1 + (1 - prob[j])*(l + 1) < keykeep)
				keykeep = 2*apag + l - d + 1 + (1 - prob[j])*(l + 1);
		}
		cout << "Case #" << i << ": ";
		if (keykeep > 2 + l )
			printf("%d.000000\n", 2 + l);
		else
			printf("%.6lf\n", keykeep);
	}
}




