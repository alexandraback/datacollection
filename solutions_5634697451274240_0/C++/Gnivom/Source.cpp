#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream input;
	ofstream output;
	input.open("input.txt");
	output.open("output.txt");
	int t;
	input >> t;
	for (int i = 0; i < t; i++)
	{
		int answer = 0;
		string pancakes;
		input >> pancakes;
		int n = pancakes.size();
		char previous = '+';
		for (int j = n - 1; j >= 0; j--)
		{
			if (pancakes[j] != previous)
			{
				answer++;
				previous = pancakes[j];
			}
		}

		output << "Case #" << i + 1 << ": " << answer << endl;
	}
}