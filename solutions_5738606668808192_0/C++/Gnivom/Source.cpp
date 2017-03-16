#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ifstream input;
	ofstream output;
	input.open("input.txt");
	output.open("output.txt");
	output << "Case #1:" << endl;
	int n, j;
	input >> n >> n >> j;
	vector<int> half(n / 2,0);
	half[0] = 1;
	for (int i = 0; i < j; i++)
	{
		for (int ii = 0; ii < half.size(); ii++)
		{
			output << half[ii];
		}
		for (int ii = half.size() - 1; ii >= 0; ii--)
		{
			output << half[ii];
		}
		for (int x = 3; x < 12; x++)
		{
			output << " " << x;
		}
		output << endl;

		for (int ii = 1; ii < half.size(); ii++)
		{
			if (half[ii] == 1)
			{
				half[ii] = 0;
				continue;
			}
			half[ii] = 1;
			break;
		}
	}
}