#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream fi("input.txt");
	ofstream fo("output.txt");
	
	int t;
	fi>>t;
	for (int i=0; i<t; i++)
	{
		int n;
		fi>>n;
		int *m = new int[n];
		vector<int> *p = new vector<int>[n];
		bool single = true;
		for (int j=0; j<n; j++)
		{
			fi>>m[j];
			if (m[j] > 1)
			{
				single = false;
			}
			for (int k=0; k<m[j]; k++)
			{
				int t;
				fi>>t;
				p[j].push_back(t-1);
			}
		}
		
		if (single)
		{
			fo<<"Case #"<<i+1<<": "<<"No"<<endl;
		}
		else
		{
			bool diamond = false;
			for (int j=0; j<n; j++)
			{
				if (m[j] > 1)
				{
					vector<int> c(p[j]);
					diamond = false;
					
					for (int k=0; k<c.size(); k++)
					{
						for (int r=0; r<p[c[k]].size(); r++)
						{
							int t = p[c[k]][r];
							for (int l=0; l<c.size(); l++)
							{
								if (t == c[l])
								{
									diamond = true;
									break;
								}
							}
							if (diamond)
							{
								fo<<"Case #"<<i+1<<": "<<"Yes"<<endl;
								break;
							}
							c.push_back(t);
							cout<<"pushed "<<t<<endl;
						}
						if (diamond)
							break;
					}
					if (diamond)
						break;
				}
			}
			if (!diamond)
				fo<<"Case #"<<i+1<<": "<<"No"<<endl;
		}
		// for (int j=0; j<n; j++)
		// {
			// cout<<p[j].size()<<endl;
		// }
		// cout<<endl;
	}
	
	return 0;
}