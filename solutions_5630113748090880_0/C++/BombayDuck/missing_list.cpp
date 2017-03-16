#include <iostream>

using namespace std;

int main()
{
	int cases;
	cin >> cases;

	int *height;
	height = new int[2501];
	for(int i  = 0; i < cases; i++)
	{
		int length;
		cin >> length;

		int person;
		for(int j = 0; j < 2501; j++)
		{
			height[j] = 0;
		}

		for(int j = 0; j < ((length * 2 - 1) * length); j++)
		{
			cin >> person;
			height[person]++;
		}

		int *lost;
		lost = new int[length];

		int index;
		for(int j = 1, index = 0; j <= 2500 && index < length; j++)
		{
			if(height[j] % 2 != 0)
			{
				lost[index] = j;
				index++;
			}
		}

		cout << "Case #" << (i + 1) << ":";
		for(int j = 0; j < length; j++)
		{
			cout << " " << lost[j];
		}
		cout << endl;

		delete[] lost;
	}

	delete[] height; 
	return 0;
}
