#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;

	cin >> t;

	int temp;
	int n;

	fstream fout;
	fout.open("b_output.out", ios::out);
	bool height[2510];

	for(int i=1; i<=t; i++)
	{
		cin >> n;
	
		for(int k=0; k<2510; k++)
		{
			height[k] = false;
		}	
		
		for(int j=1; j<=(2*n-1); j++)
		{
			for(int l=1; l<=n; l++)
			{
				cin >> temp;
			    height[temp] = !height[temp]; 
			}

		}

		fout << "Case #" << i << ":";
		for(int k=0; k<2510; k++)
		{
			if(height[k])
			{
				fout << " " << k;
			}
		}
		fout << endl;	
	}
	return 0;
}
