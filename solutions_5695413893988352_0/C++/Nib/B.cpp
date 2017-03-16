#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int tc = 1;tc <= t;tc++) {
	string C, J, resx, resy;
	cin >> C >> J;
	int res = 1707050900, sz = int(C.size());
	while(int(C.size()) < 3) C = "0"+C;
	while(int(J.size()) < 3) J = "0"+J;
	for(int i = 0;i < 1000;i++)
	{
		for(int j = 0;j < 1000;j++)
		{
			bool done = true;
			string x = to_string(i), y = to_string(j);

			while(int(x.size()) < 3) x = "0"+x;
			while(int(y.size()) < 3) y = "0"+y;
			//cout << x << " " << y << "\n";
			for(int k = 0;k < 3;k++)
			{
				if(C[k] != x[k] && C[k] != '?')
				{
					done = false;
				}
				if(J[k] != y[k] && J[k] != '?')
				{
					done = false;
				}
			}
			if(done)
			{
				if(res > abs(i-j))
				{
					res = min(res, abs(i-j));
					resx = x;
					resy = y;
				}
			}
		}
	}

	while(sz < int(resx.size())) resx = resx.substr(1);
	while(sz < int(resy.size())) resy = resy.substr(1);
	printf("Case #%d: ", tc);
	cout << resx << " " << resy << "\n"; }
}