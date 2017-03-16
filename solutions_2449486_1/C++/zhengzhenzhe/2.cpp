#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t,n,m;
	cin>>t;
	vector<vector<int> > a;
	int ca=0;
	while(t--)
	{
		ca++;
		a.clear();
		cin>>n>>m;	
		int tmp;
		vector<int> a_c;
		vector<int> array_max_c;
		vector<int> array_max_r;
		for (int i=0;i<n;i++)
		{
			a_c.clear();
			for (int j=0;j<m;j++)
			{
				cin>>tmp;
				a_c.push_back(tmp);
			}
			a.push_back(a_c);
			array_max_r.push_back(*max_element(a_c.begin(),a_c.end()));
		}
		int max_c=0;
		for (int i=0;i<m;i++)
		{
			max_c=0;
			for (int j=0;j<n;j++)
			{
				if (max_c<a[j][i])
					max_c=a[j][i];
			}
			array_max_c.push_back(max_c);
		}
		bool is_yes=true;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				if (a[i][j]<array_max_r[i]&&a[i][j]<array_max_c[j])
				{
					is_yes=false;
					break;
				}
			}
			if (!is_yes)
			{
				break;
			}
		}
		cout<<"Case #"<<ca<<": ";
		if (is_yes)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
	return 0;
}
