#include <iostream>
#include <string>

using namespace std;

#define MAX(a, b) (a > b ? a : b)

int main()
{
	int T, test, Smax, i, sum, count, add;
	string S;

	cin>>T;

	for (test = 1; test <= T; test++)
	{
		cin>>Smax>>S;

		sum = count = 0;
		for (i = 0; i <= Smax; i++)
		{
			add = MAX(0, i-count);
			sum += add;
			count += (S[i]-'0') + add;
		}

		cout<<"Case #"<<test<<": "<<sum<<endl;
	}

	return 0;
}
