#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	int t, n, standing, smax;
	string peeps;
	scanf("%d", &t);

	for(int i = 1; i <= t; i++)
	{
		cin >> smax >> peeps;
		standing = n = 0;

		for(int j = 0; j <= smax; j++)
		{
			int add = 0;

			if(peeps[j] != '0' and standing < j)
			{
				add = (j-standing);
				n += add;
			}
			
			standing += (peeps[j] - '0') + add;
		}

		printf("Case #%d: %d\n", i, n);
	}

	return 0;
}