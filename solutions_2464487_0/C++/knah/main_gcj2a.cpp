//compiler: MSVC 2010 (C++ obviously)

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

typedef unsigned long long ull;
typedef long long ll;

#define FN "gcj2a"

using namespace std;

int main()
{
	ifstream in(FN ".in");
	ofstream out(FN ".out");

	int tn;
	in >> tn;

	for(int i = 1; i <= tn; i++)
	{
		ll r,t;
		in >> r >> t;

		ll ans = 0;


		if(r > 5000000000ll) //overflow maybe
		{
			ll required = 2*r+1;
			while(required <= t)
			{
				ans++;
				t -= required;
				r += 2;
				required = 2*r+1;
			}
		}
		else
		{

			//S = t
			//S = 2r+1 .+. 2(r+x)+1
			//S = (2r+1+2r+1+2x)/2*x
			//S = (2r+1+x)*x
			//S = (2*(2r+1)+(x-1)4)/2*x
			//S = (2r+1)*x+2x(x-1)
			//S = x(2r+1)+2xx-2x
			//0 = xx+x(2r+1-2)/2-s
			//0 = xx + (2r+1)x - S
			//x = (-2r-1+sqrt((2r+1)^2+4S))/2

			
			ll lb = 1;
			ll ub = 800000000;

			do {
				ll mid = (lb+ub)/2;
				//double val = mid-t/(double)mid+(2.0*r-1.0)/2.0;
				ll val = ((4*r+2+4*(mid-1))*mid)/2;
				if(val == t || ub-lb <= 1)
				{
					if(ub - lb <= 1)
						mid = max(ub,lb);
					val = ((4*r+2+4*(mid-1))*mid)/2;
					while(val > t)
					{
						mid--;
						val = ((4*r+2+4*(mid-1))*mid)/2; //mid-t/(double)mid+(2*r+1);
					}
					ans = mid;
					break;
				}
				if(val > t)
					ub = mid - 1;
				else
					lb = mid + 1;
			} while(true);
		}

		

		//if(ans != ans_c)
		//	cout << "ans mismatch " << ans << " " << ans_c << " " << i << "\n";

		out << "Case #" << i << ": " << ans << "\n";
	}

	//system("pause");

	out.close();
	return 0;
}