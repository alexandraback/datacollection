#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	cin>>n;	
	for (int step=0; step<n; ++step)
	{
		printf("Case #%d: ", step+1);

		int a, b;
		scanf("%d%d", &a, &b);
		double prob=1, bst=999999999999999999;
		double k, tmp;
		for (int i=0; i<a; ++i)
		{
			double x, y;
			scanf("%lf", &k);
			prob*=k;
			//tmp=a+2*b-2*(i+1)+2-prob*(b+1);
			//tmp=prob*(a-i-1+b-i-1+1)+(1-prob)*(a+b-2*i+b);
			x=a-i-1+b-i-1+1;
			y=a+b-2*i+b;
			tmp=prob*x+(1-prob)*y;
			if (tmp<bst)
				bst=tmp;
		}
		if (bst>b+2) bst=b+2;
		printf("%.9lf\n", bst);





	}

}
