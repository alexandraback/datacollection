#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;
double chance[1505][1505];

int main()
{
	chance[0][0]=1;
	for (int i=1;i<=1500;++i)
	{
		chance[i][0] = chance[i-1][0]/2;
		for (int j=1;j<=i-1;++j)
		{
			chance[i][j] = (chance[i-1][j-1] + chance[i-1][j])/2;
		}
		chance[i][i] = 1;
	}


	
	int T;
	cin >> T;
	for (int t=1;t<=T;++t)
	{
		int N, X, Y;
		cin >> N >> X >> Y;
		
		int height = (int)floor((-1+sqrt(1+8*(double)N))/2);
		if (height %2 == 0) height--;
		
		int remainder = N - (height)*(height+1)/2;
		cout << "Case #" << t << ": " ;
		if (abs(X) + Y <= height - 1)
		{
				cout << "1.0" << endl;
		}
		else if (abs(X) + Y == height+1)
		{
			if (remainder < (Y+1)) cout << "0.0" << endl;
			else if (remainder > (Y+1) + height) cout << "1.0" << endl;
			else if ( remainder < 2*(height+2)-1 && (Y+1) == height+2) cout << "0.0" << endl;
			else cout << chance[remainder][remainder-(Y+1)] << endl;
			
			//cout << remainder << endl << height << endl <<  Y << endl;
		}
		else
		{
			cout << "0.0" << endl;
		}
		
	}
	return 0;
}