#include <iostream>
#include <string>

using namespace std;

int mult[8][8] = {
	{0,1,2,3,4,5,6,7},
	{1,0,3,2,5,4,7,6},
	{2,3,1,0,6,7,5,4},
	{3,2,0,1,7,6,4,5},
	{4,5,7,6,1,0,2,3},
	{5,4,6,7,0,1,3,2},
	{6,7,4,5,3,2,1,0},
	{7,6,5,4,2,3,0,1},
};

int inv[8] = {
	0,1,3,2,5,4,7,6,
};

string disp[8] = {
	"1",
	"-1",
	"i",
	"-i",
	"j",
	"-j",
	"k",
	"-k",
};

void doCase()
{
	int firstOcc[8];
	int secondOcc[8];
	
	int L, X;
	
	cin >> L >> X;
	
	string input;
	cin >> input;
	
	if (X % 4 == 0)
	{
		cout << "NO" << endl;
		return;
	}
	
	int curValue = 0;
	
	for (int i=0; i<8; i++)
	{
		firstOcc[i] = secondOcc[i] = -1;
	}
	
	bool foundI=false;
	bool foundK=false;
	
	for (int j=0; j<8 && j<X; j++)
	{
		for (int i=0; i<L; i++)
		{
			switch(input[i])
			{
			case 'i':
				curValue = mult[curValue][2];
				break;
			case 'j':
				curValue = mult[curValue][4];
				break;
			case 'k':
				curValue = mult[curValue][6];
				break;
			default:
				cerr << "FAIL" << endl;
			}
			if (!foundI && curValue == 2)
				foundI = true;
			else if (foundI && curValue == 6)
				foundK = true;
		}
		if (X % 2 == 1 && j == 0 && curValue != 1)
		{
			cout << "NO" << endl;
			return;
		}
		if (X % 4 == 2 && j == 1 && curValue != 1)
		{
			cout << "NO" << endl;
			return;
		}
	}
	
	if (foundI && foundK)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main()
{
	int T;
	
	cin >> T;
	
	for (int i=0; i<T; i++)
	{
		cout << "Case #" << i+1 << ": ";
		doCase();
	}
	
	return 0;
}
