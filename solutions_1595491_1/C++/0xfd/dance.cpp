#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fi("input.txt");
	ofstream fo("output.txt");
	
	int t;
	fi>>t;
	for (int i=0; i<t; i++)
	{
		int n, s, p;
		fi>>n>>s>>p;
		int lb = max(p - 1, 0);
		int llb = max(p - 2, 0);
	
		int m = 0;
		int g;
		for (int j=0; j<n; j++)
		{
			fi>>g;
			if (g >= p + 2 * lb)
			{
				cout<<g<<endl;
				m++;
			}
			else if ((s > 0) && (g >= p + 2 * llb))
			{
				cout<<"* "<<g<<endl;
				m++;
				s--;
			}
		}
		
		fo<<"Case #"<<i+1<<": "<<m<<endl;
		cout<<"Case #"<<i+1<<": "<<m<<endl;
	}
	
	return 0;
}