#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct info
{
	char c;
	int n;
};

struct my_string
{
	string s;
	vector<info> inf;
};

unsigned long long exchange(int x, vector<int> &v)
{
	unsigned long long result = 0;
	for (int i = 0; i < v.size(); i++)
	{
		result += abs(v[i] - x);
	}
	return result;
}

void main()
{
	ifstream input;
	ofstream output;
	input.open("input.in");
	output.open("output.out");

	if (!input)
	{
		cout<<"No input file"<<endl;
	}
	if (!output)
	{
		cout<<"No output file"<<endl;
	}
	int cases = 0;
	input>>cases;

	for (int nn = 1; nn <= cases; nn++)
	{
		unsigned long long a, b, k;
		unsigned long long result = 0;
		input>>a>>b>>k;

		for (unsigned long long i = 0; i < a; i++)
		{
			for (unsigned long long j = 0; j < b; j++)
			{
				if ((i & j) < k)
				{
					result++;
				}
			}
		}

		output<<"Case #"<<nn<<": "<<result<<endl;


	}



	input.close();
	output.close();
	system("pause");
}