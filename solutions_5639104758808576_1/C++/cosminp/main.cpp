#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream	f("in.txt");
	ofstream	g("out.txt");
	int			testCount;
	int			N, sum, friends;
	string		s;

	f >> testCount;
	for (int test = 1; test <= testCount; test++)
	{
		f >> N >> s;
		sum = friends = 0;
		for (int i = 0; i <= N; i++)
		{
			if ((s[i] != '0') && (sum < i))
			{
				friends += i - sum;
				sum		+= i - sum;
			}
			sum += s[i] - '0';
		}
		g << "Case #" << test << ": " << friends << endl;
	}

	return 0;
}