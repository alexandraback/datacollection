#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int ta=1;ta<=t;++ta)
	{
		cout << "Case #" << ta << ": ";
		int d;
		cin >> d;
		vector<int> p(d);
		for(int i=0;i<d;++i)
			cin >> p[i];
		int r=1000;
		for(int i=1;i<=1000;++i)
		{
			int t=i;
			for(int j=0;j<d;++j)
				t+=(p[j]-1)/i;
			if(r>t)r=t;
		}
		cout << r << endl;
	}
}
