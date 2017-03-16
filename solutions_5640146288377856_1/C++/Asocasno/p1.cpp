#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	int tests;
	cin >> tests;

	for(int a=0; a<tests; a++)
	{
		int rows, cols, width;
		cin >> rows >> cols >> width;

		int retval = 0;
		int perRow = cols / width;
		retval = rows * perRow;
		cerr << "Case " << (a+1) << ": rowTotal " << retval << endl;

		int left = -1, right = cols;
		int i=0;
		while(i < perRow)
		{
			left += width;
			i++;
			if(i < perRow)
			{
				right -= width;
				i++;
			}
		}

		retval += width - 1;
		cerr << "Left: " << left << " Right: " << right << endl;
		if((right - 1) > left)
		{
			retval++;
		}

//		if(width == cols)
//		{
//			retval--;
//		}

		cout << "Case #" << (a+1) << ": " << retval << endl;
	}

	return 0;
}
