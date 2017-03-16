#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>
#include<map>
#include<set>

using namespace std;


int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int t = 1;
	cin >> t;
	for(int tt = 0; tt < t; tt++)
	{
		long double c, f, x = 0;
		cin >> c >> f >> x;
		long double res = 1000000000;
		res*=1000;
		res*=1000;
		long double curProd = 2;
		long double prevTime = 0;
		for(long long int i = 0; i < 10000000000ll; i++)
		{
			if(res < prevTime + x/curProd)
				break;
			res = min(res, prevTime + x/curProd);
			prevTime += c / curProd;
			curProd += f;
		}
		
		printf("Case #%d: %llf\n", tt+1, res);
	
	}
	return 0;
}

