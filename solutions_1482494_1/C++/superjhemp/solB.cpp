#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, T, nGames, nStars, left;
	
	cin>>T;
	for (int t=1; t<=T; t++)
	{
		cin>>N;
		vector<int> a(N), b(N), s(N,0);
		for (int i=0; i<N; i++)
			cin>>a[i]>>b[i];
			
		left = N;
		nGames = 0;
		nStars = 0;
		
		while(true)
		{
			start:
			for (int i=0; i<N; i++)
				if (s[i]!=2 && nStars>=b[i])
				{
					nGames++;
					nStars += 2-s[i];
					s[i] = 2;
					left--;
					goto start;
				}
			
			int maxB(0), bestI(-1);
			for (int i=0; i<N; i++)
				if (s[i]==0 && nStars>=a[i] && b[i]>=maxB)
				{
					bestI = i;
					maxB = b[i];
				}
				
			if (bestI < 0)
				break;
				
			nGames++;
			nStars += 1;
			s[bestI] = 1;
		}
		
		if (left>0)
			cout<<"Case #"<<t<<": "<<"Too Bad"<<endl;
		else
			cout<<"Case #"<<t<<": "<<nGames<<endl;
	}
	return 0;
}
