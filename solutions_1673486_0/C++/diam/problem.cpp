
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
double enter[100000+100];
using namespace std;
    int main()
        {
			freopen("input.txt","rt", stdin);
			freopen("output.txt","wt", stdout);
			int tests;
			scanf("%d",&tests);
			for (int test = 1; test <= tests; test++)
			{
				//scanf("")
				int a,b;
				scanf("%d%d", &a, &b);
				for (int i = 1; i <= a; i++)
					scanf("%lf", &enter[i]);
				long double best = 2.0 + b;
				long double p = 1.0;
				long double cb = 1;
				for (int i = 1; i <= a; i++)
				{
					p = p*enter[i];
					cb =  ((a-i)+(b-i) + 1.0) + (1-p)*(b+(1.0));
					if ( cb < best)
						best = cb;
				}
				
				string s = "";
				printf("Case #%d: ",test);
				double prt = double(best);
				printf("%lf\n",prt);

			}



			
        } 
    // END CUT HERE 
