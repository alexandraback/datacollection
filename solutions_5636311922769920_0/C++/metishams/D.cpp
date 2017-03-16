#include <iostream>
using namespace std;

int solve_print(int k, int c)
{	
	for(int i=0;i<k;i++)
	{
		long long num = 0;
		long long pow = 1;
		for(int j=0;j<c;j++)
		{
			num+=i*pow;
			pow*=k;
		}
		cout << num+1;
		if(i<k-1)
			cout << " ";
	}
	cout << endl;
}


int main()
{
	int t;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		int k, c, s;	
		cin >> k >> c >> s;
		cout << "Case #" << i+1 << ": ";
		solve_print(k,c);
	}
	return 0;
}

