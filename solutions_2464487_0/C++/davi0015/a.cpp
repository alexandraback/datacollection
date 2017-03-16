#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector <long long int> num;

int main()
{
	int T;
	cin >> T;
	
	for (int i=0; i<T; i++)
	{
		int r, t;
		cin >> r >> t;
		
		int b = 0;
		while (t>=0)
		{
			t -= 2*(r+2*b) + 1;
			b++;
		}
		
		cout << "Case #" << i+1 << ": " << b-1 << endl;
	}
}