#include <iostream>
#include <string>

using namespace std;

int calculate(int h, string in)
{
	int mIn[in.size()];
	for(size_t i = 0; i < in.size(); i++)
	{
		mIn[i] = in[i] - '0';
	}

	int mOut = 0;
	int cur = 0;
	size_t i = 0;
	while(i < in.size())
	{
		//cout << "#" << mIn[i] << endl;
		if(mIn[i] == 0) i++;
		else if(cur >= i)
		{
			cur += mIn[i];
			i++;
		}
		else
		{
			mOut++;
			cur++;
		}
	}
	return mOut;
}

int main()
{
	// get total number of testcases
	int totalcase = 0;
	cin >> totalcase;

	int output[totalcase];
	int highest = 0;
	string input = "";
	for(int i = 0; i < totalcase; i++)
	{
		cin >> highest;
		cin >> input;
		output[i] = calculate(highest, input);
	}

	for(int i = 0; i < totalcase; i++)
	{
		cout << "Case #" << (i + 1) << ": " << output[i] << endl;
	}


	return 0;
}