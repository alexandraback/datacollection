#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<string.h>
#include<memory.h>
#include<iomanip>
#include<cmath>
using namespace std;

double C, F, X;


int main()
{
	int test_cnt;
	cin>>test_cnt;
	for(int test_num=1;test_num<=test_cnt;test_num++)
	{
		cin>>C>>F>>X;
		double best = X/2;
		if (C<X-1e-7)
		{
			double t = 0;
			for(int i=1;i<5000;i++)
			{
				t += C/(2+(i-1)*F);
				double t2 = t + X/(2+i*F);
				if (t2<best) best = t2;	
			}
		}
		printf("Case #%d: %.9lf\n", test_num, best);
	}
	
	return 0;
}
