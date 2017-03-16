#include<iostream>
#include<string>
#include<fstream>
#include <queue> 
using namespace std;
int main()
{
	int t, smax = 0;
	ifstream infile("small.in");
	ofstream outfile("small.out1");

	infile >> t;
	for (int index = 0; index < t; index++)
	{
		
		int d;
		infile >> d;
		vector<int> pancakes(d,0);
		int ans = 0;
		for (int i = 0; i < d; i++)
		{
			infile >> pancakes[i];
			if (pancakes[i]>ans)ans = pancakes[i];
		}
		int mini = ans;
		for (int z = 2; z < ans; z++)
		{
			int count = 0;
			for (int j = 0; j < d; j++)
			{
				count += (pancakes[j]-1) / z;
			}
			if (count + z < mini)mini = count + z;
		}
		outfile << "Case #" << index + 1 << ": " << mini << endl;
	}
	infile.close();
	outfile.close();
	return 0;
}