#include <iostream>
#include <fstream>
using namespace std;
ofstream fout("output.out");
char s[101][101];
int check(int i)
{
	int status=0;
	if (s[i][0] == '+') status = 1;
	for (int j = 0;j < strlen(s[i]);j++)
	{
		if (s[i][j] == '-' && status == 1)
		{
			for (int k = 0;k < j;k++)
			{
				s[i][k] = '-';
			}
			return 1;
		}
		if (s[i][j] == '+' && status == 0)
		{
			for (int k = 0;k < j;k++)
			{
				s[i][k] = '+';
			}
			return 1;
		}
	}
	if (status == 0)
	{
		for (int k = 0;k < strlen(s[i]);k++)
		{
			s[i][k] = '+';
		}
		return 1;
	}
	return 0;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> s[i];
		int x = 0;
		do
		{
			if (check(i) == 1)
			{
				x++;
			}
			else
			{
				fout <<"Case #"<<i+1<<": "<<x<<endl;
				break;
			}
		} while (1);
	}
}