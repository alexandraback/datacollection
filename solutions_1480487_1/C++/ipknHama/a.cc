#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int tn;
	cin >> tn;
	for(int loop = 0; loop < tn; loop++)
	{
		cout << "Case #" << loop+1 << ":";
		int N;
		cin >> N;
		vector<int> v;
		v.reserve(N);
		int s = 0;
		for(int i = 0 ; i< N; i ++)
		{
			int t;
			cin >> t;
			v.push_back(t);
			s+=t;
		}
		for(int i = 0; i < N; i ++)
		{
			double l = 0;
			double r = 1;
			//while(r-l > 1e-7)
			for(int k = 0; k < 100;k++)
			{
				double m = (l+r)/2;
				double f = m;
				double remain = 1-m;
				double myscore = v[i] + s*f;

				bool valid = false;

				for(int j = 0; j < N; j ++)
				if (j == i) continue;
				else {
					if (myscore > v[j])
					{
						remain -= (myscore-v[j])/s;
					}
					if (remain < 0)
					{
						valid = true;
						break;
					}
				}

				if (valid)
					r = m;
				else
					l = m;

			}
			printf(" %.10lf", (double)(100*(l+r)/2));

		}
		cout << endl;
	}
	return 0;
}
