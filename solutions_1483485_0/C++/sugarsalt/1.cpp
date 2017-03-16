#include <iostream>
//#include <fstream>
using namespace std;

char encode[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l',
	'b','k','r','z','t','n','w','j','p','f','m','a','q'};
char in[200];

int run(int casen)
{
	cout << "Case #" << casen << ": ";
	cin.getline(in,200);
	int i= -1;
	while (in[++i] != 0)
	{
		if (in[i] == ' ')
			continue;
		in[i] = encode[in[i] - 'a'];
	}

	cout << in << endl;
}

int main()
{
	int test_n;
	cin >> test_n;
	cin.getline(in,200);
	for (int i=1;i<=test_n;i++)
		run(i);
}
