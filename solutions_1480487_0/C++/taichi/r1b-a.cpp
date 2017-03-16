#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
	int T;
	cin>>T;

	for(int i = 1; i <= T; ++i)
	{
		int N;
		cin>>N;
		vector<int> vi;
		int sum = 0;
		int smallest = 200;
		int idx = -1;
		for(int j = 0; j < N; ++j)
		{
			int temp;
			cin>>temp;
			vi.push_back(temp);
			sum += temp;
			if(temp < smallest)
			{
				smallest = temp;
				idx = j;
			}
		}

		double l = 0;
		double h = 1.0;
		while(l <= h)
		{
			double m = (l+h)/2;
			double target = vi[idx]+sum*m;
			vector<double> vd;
			double all = m;			
			for(int j = 0; j < vi.size(); ++j)
			{
				if(j == idx)
				{
					vd.push_back(m);
					continue;
				}

				double v = (target - vi[j])/sum;
				if(v<0) v = 0;				
				vd.push_back(v);
				all += v;
			}

			if(abs(all-1) <= 0.000000001)
			{
				cout<<"Case #"<<i<<":";
				for(int j = 0; j < vd.size(); ++j)					
					cout<<" "<<setprecision(8)<<vd[j]*100;
				cout<<endl;
				break;
			}

			if(all > 1)
				h = m;
			else
				l = m;
		}		
	}
}