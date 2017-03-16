//compiled in vc
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <complex>
// C++
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <ctime>
using namespace std;


int cases , Case = 1;

int main()
{	
	scanf("%d" , &cases);

	
	
	int a , b;

	while( cases-- )
	{
		vector<double> aa;
		printf("Case #%d: " , Case++);   

		cin >> a >> b;

		char all1 = 1;
		
		double ok = 1;
		double aaa = 0;
		for(int i = 0 ; i < a; ++i)
		{
			double t;
			cin >> t;
			aa.push_back(t);
			if( t != 1.0)
				all1 = 0;
			
			ok *=t;
		}

		aaa = ok;

		double ans = 0;

		if(all1)
			ans = b-a+1;
		else
		{
			double enter = 1+ b +1;
			ans = enter;

			for(int back = 0;back< a; ++back)
			{
				if(back)
				{
					double t = 1;
					/*for(int i = 0 ; i < a; ++i)
					{
						if( i >= a-back )
							t *= 1.0-aa[i];
						else
							t *=aa[i];
					}*/
					//ok+=t;

					aaa/= aa[ a-back ];
					aaa*= 1.0-aa[ a-back ];
					ok +=aaa;
				}

				double t = ok *(back*2 + (b-a) +1 ) + (1.0-ok)*(back*2+b-a+1 + b+1);



				ans = min(ans,t);
			}

			

		}

		printf("%.8lf\n" , ans);
	}


	return 0;
}
