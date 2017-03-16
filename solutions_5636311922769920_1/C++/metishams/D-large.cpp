#include <iostream>
using namespace std;

int solve_print(int k, int c)
{	
	for(int i=0;i<k;i+=c)
	{
		long long num = 0;
		for(int j=0;j<c;j++)
		{
			if(i+j>=k)
				break;
			num = num * k + (i+j);
		}
		cout << num+1;
		if(i+c<k)
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
		if(k>s*c)
			cout << "IMPOSSIBLE" << endl;
		else
			solve_print(k,c);
	}
	return 0;
}

