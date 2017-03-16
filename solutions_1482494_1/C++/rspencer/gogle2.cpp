#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
	int T;
  cin>>T;
	for (int t = 0;t<T;t++)
	{
		cout<<"Case #"<<t+1<<": ";
		int N;
		cin>>N;
		pair<int,int> levels[N];
		int complete[N];
		for (int i = 0;i<N;i++)
		{
			complete[i] = 0;
			cin>>levels[i].second>>levels[i].first;
			levels[i].second=-levels[i].second;
			levels[i].first=-levels[i].first;
		}
		sort(levels,levels+N);
		for (int i = 0;i<N;i++)
		{
			int t;
			t = levels[i].first;
			levels[i].first = -levels[i].second;
			levels[i].second = -t;
		}
		int score = 0;
		bool doneSomething = true;
		int moves = 0;

		while (doneSomething)
		{
			if (score==2*N)
				break;
			doneSomething = false;
			for (int i = 0;i<N;i++)
			{
				if ((complete[i]<2)and (levels[i].second<=score))
				{
				  //cout<<"**"<<i<<endl;
					doneSomething = true;
					score += 2-complete[i];
					moves++;
					complete[i]=2;
				}
			}
			if ( not doneSomething)
				for (int i = 0;i<N and (not doneSomething);i++)
				{
					if ((complete[i]<1)and (levels[i].first<=score))
					{
						//cout<<"*"<<i<<endl;
						doneSomething = true;
						score++;
						complete[i]=1;
						moves++;
					}
				}				
		}
		
		if (score==2*N) cout<<moves<<endl;
		else cout<<"Too Bad"<<endl;
		
	}
	return 0;
}
