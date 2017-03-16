#include<fstream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<iomanip>

using namespace std;


int main()
{
	ifstream cin("in.txt");
	ofstream cout("out.txt");

	cout.flags(std::ios::fixed);
	cout<<setprecision(6);

	int t;
	cin>>t;
	for(int tt=0; tt<t; tt++)
	{
		int n;
		cin>>n;
		vector<int> a;
		int xx = 0;
		for(int i = 0; i<n; i++)
		{
			int r;
			cin>>r;
			a.push_back(r);
			xx+=a[i];
		}
		double x = xx;
		vector<int> b = a;
		sort(a.begin(), a.end());
		double level = a[0];
		for(int i=0; i<n-1; i++)
		{
			double s = a[i+1]-a[i];
			if(x<s*(i+1))
			{
				level += x/double(i+1);
				x = 0;
				break;
			}
			else
			{
				x-=s*(i+1);
				level+=s;
			}

		}
		level += x/double(n);
		a = b;
		cout<<"Case #"<<tt+1<<":";
		for(int i=0; i<n; i++)
		{
			if(level-a[i]<=0) cout<<' '<<double(0);
			else 
			cout<<' '<<(level-a[i])*100./double(xx);
		}
		cout<<endl;
	}
	return 0;
}