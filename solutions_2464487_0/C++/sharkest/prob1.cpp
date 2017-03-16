#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int count = 0;
	while(count < n)
	{
		count++;
		long long int r, t;
		cin >> r >> t;
		long long int i = 0;
		long long int resp = 0;
		for(i = 1; resp < t; i++)
		{
			resp = 	i*(2*r+2*i-1);
		}
		if(resp != t)
			i -= 2;
		else
			i -= 1;
		cout << "Case #" << count << ": "<<i<< endl;
	}
	return 0;
}
