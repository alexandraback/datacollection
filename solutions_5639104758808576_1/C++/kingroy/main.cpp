#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int cases, shyn;
	cin >> cases;
	for(int i = 0; i < cases; i++)
	{
		int friends = 0, cursum = 0;
		cin >> shyn;
		char c = ' ';
		for (int j = 0; j <= shyn; j++)
		{
			cin >> c;
			while (c == ' ')
				cin >> c;
			if (cursum < j)
			{
				friends += j - cursum;
				cursum = j;
			}
			cursum += c - '0';
		}
		cout << "Case #" << i + 1 << ": " << friends << endl;
	}
}