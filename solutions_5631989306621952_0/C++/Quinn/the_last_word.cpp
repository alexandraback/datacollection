#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int t;
	
	ifstream inF;
	ofstream outF;

	inF.open("small.in");
	outF.open("small.out");

	inF >> t;

	string input;
	vector<char> back;
	vector<char> front;
	for (int test_case = 1; test_case < t + 1; ++test_case)
	{
		inF >> input;

		front.push_back(input[0]);
		for (string::iterator it = input.begin() + 1; it != input.end(); ++it)
		{
			if (*it < front.back())
			{
				back.push_back(*it);
			}
			else
			{
				front.push_back(*it);
			}
		}

		outF << "Case #" << test_case << ": ";
		for (vector<char>::reverse_iterator it = front.rbegin(); it != front.rend(); ++it)
		{
			outF << *it;
		}

		for (vector<char>::iterator it = back.begin(); it != back.end(); ++it)
		{
			outF << *it;
		}


		outF << endl;
		back.clear();
		front.clear();
	}

	inF.close();
	outF.close();

	return 0;
}