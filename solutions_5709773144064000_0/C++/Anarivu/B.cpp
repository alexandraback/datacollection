#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;



int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);

	int TT;
	scanf("%d", &TT);
	for(int T = 0; T < TT; T++)
	{
		printf("Case #%d: ", T+1);
		double c, f, x;
		scanf("%lf%lf%lf", &c, &f, &x);
		double t = 0, res = x / 2.0;
		double sp = 2;
		while(1)
		{
			t += (double)c / sp;
			sp += f;
			if(t + (double)x / sp > res)
				break;
			res = t + (double)x / sp ;
		}
		printf("%.8lf\n", res);
	}

	return 0;
}