#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
	int t, smax = 0;
	ifstream infile("large.in");
	ofstream outfile("largeout.txt");
	infile >> t;
	
	for (int index = 0; index < t;index++)
	{
		string shy;
		int sum=0;
		int others = 0;
		infile >> smax;
		infile >> shy;
		sum = shy[0]-'0';
		for (int i = 1; i <= smax; i++)
		{
			int num = shy[i] - '0';
			if (sum < i){ others += i - sum; sum = i+num; }
			else{ sum += num; }
		}
		outfile << "Case #" << index+1 << ": " << others << endl;
	}
	infile.close();
	outfile.close();
	return 0;
}