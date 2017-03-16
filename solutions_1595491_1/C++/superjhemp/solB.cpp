#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int T, N, S, P, pi;
	int mLim, yLim, m, y;
	
	cin>>T;
	for (int t=1; t<=T; t++)
	{
		cin>>N>>S>>P;
		mLim = max(3*P-4,1);
		yLim = 3*P-2;
		m = 0;
		y = 0;
		for (int j=0; j<N; j++)
		{
			cin>>pi;
			if (pi>=yLim) y++;
			else if (pi>=mLim) m++;
		}
		cout<<"Case #"<<t<<": "<<y+min(S,m)<<endl;
	}
	return 0;
}
