#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int T,A,B;
	double best,pcorrect,pwrong,check,P;
	cin >> T;
	for(int z = 1; z <= T; z++)
	{
		best = 200000;
		pcorrect = 1.0;
		cin >> A >> B;
		B++;
		best = 1+B;
		for(int i = 1; i <= A; i++)
		{
			cin >> P;
			pcorrect *= P;
			//cout << pcorrect << " " << B-i << " " << (1.0-pcorrect ) << " " << B-i+B << endl;
			check = pcorrect*(B-i)+(1.0-pcorrect)*(B-i+B)+A-i;
			//cout << check << endl;
			if(check < best)
				best = check;
		}
		printf("Case #%d: %.6lf\n", z, best);
		//cout << endl;
	}
}
