#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool gr(int a, int b)
{
	return a>b;
}

int main()
{
	int T;

	cin>>T;

	for(int t = 1; t<=T; ++t)
	{
		int N;

		cin>>N;

		priority_queue<int, vector<int>, std::greater<int> > v1;
		priority_queue<int, vector<int>, std::greater<int> > v2;

		for(int i=0; i<N; ++i)
		{
			int a,b;

			cin>>a>>b;
		
			v1.push(a);
			v2.push(b);
		}

		int stars = 0;
		int time = 0;

		bool fail = false;

		while(!v2.empty())
		{
			if(v2.top()<=stars)
			{
				v2.pop();
				stars+=2;
				++time;
			}
			else if(!v1.empty() && v1.top()<=stars)
			{
				v1.pop();
				++stars;
				++time;
			}
			else
			{
				fail = true;
				break;
			}
		}

		if(!fail)
			cout<<"Case #"<<t<<": "<<time<<endl;
	}


	return 0;
}