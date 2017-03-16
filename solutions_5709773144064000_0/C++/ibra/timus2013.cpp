#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>                                                                                                                                                                                  
#include <map>                                                                                                                                                                                    
#include <iostream>                                                                                                                                                                               
#include <set>                                                                                                                                                                                    
#include <cmath>                                                                                                                                                                                  
#include <cassert>                                                                                                                                                                                
#include <ctime>                                                                                                                                                                                  
#include <string>                                                                                                                                                                                 
using namespace std;    
int nextint(){int _;scanf("%d",&_);return _;}
double nextdouble(){double _;scanf("%lf",&_);return _;}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t = nextint();
	for(int test = 1; test <= t; test++)
	{
		double res = 1e100;

		double c = nextdouble();
		double f = nextdouble();
		double x = nextdouble();
		
		double p = 2;
		double add = 0.0;
		for(int i = 0; i < 2*x; i++)
		{
			res = min(res, add + x/p);
			add += c/p;
			p += f;
		}

		printf("Case #%d: %0.12lf\n", test, res);
	}

	return 0;
}
