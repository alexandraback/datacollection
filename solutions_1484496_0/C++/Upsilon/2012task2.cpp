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
		int a[1000];
		for(int i = 0; i<n; i++) cin>>a[i];
		map<int, int> m;
		cout<<"Case #"<<tt+1<<": "<<endl;
		bool b = true;
		for(int i = 1; i<1048576; i++)
		{
			int k = i;
			int s = 0;
			for(int j = 0; j<20; j++)
			{
				if(k%2==1) s+=a[j];
				k>>=1;
			}
			if(m.find(s)!=m.end())
			{
				int r = m[s];
				for(int j = 0; j<20; j++)
				{
					if(r%2==1) cout<<a[j]<<' ';
					r>>=1;
				}
				cout<<endl;
				for(int j = 0; j<20; j++)
				{
					if(i%2==1) cout<<a[j]<<' ';
					i>>=1;
				}
				cout<<endl;
				b = false;
				break;
			}
			else m[s] = i;
		}
		if(b)
		cout<<"Impossible"<<endl;
	}
	return 0;
}