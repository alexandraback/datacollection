#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int count;
	cin >> count;

	for(int i = 0; i < count; i++)
	{
		int jackets, pants, shirts, limit;

		cin >> jackets;
		cin >> pants;
		cin >> shirts;
		cin >> limit;

		int days = 0;
		stringstream output;

		int *jp = new int[jackets * pants];
		int *js = new int[jackets * shirts];
		int *ps = new int[pants * shirts];
		for(int j = 0; j < (jackets * pants); j++)
		{
			jp[j] = 0;
		}
		for(int j = 0; j < (jackets * shirts); j++)
		{
			js[j] = 0;
		}
		for(int j = 0; j < (pants * shirts); j++)
		{
			ps[j] = 0;
		}

		for(int j = 0; j < jackets; j++)
		{
			for(int k = 0; k < pants; k++)
			{
				for(int l = 0; l < shirts; l++)
				{
					if((jp[j * pants + k] < limit) && (js[j * shirts + l] < limit) && (ps[k * shirts + l] < limit))
					{
						output << (j + 1) << " " << (k + 1) << " " << (l + 1) << endl; 
						jp[j * pants + k]++;
						js[j * shirts + l]++;
						ps[k * shirts + l]++;
						days++;
					}
				}
			}
		}
		cout << "Case #" << (i + 1) << ": " << days << endl;
		cout << output.str();

		delete[] jp;
		delete[] js;
		delete[] ps;
	}
	return 0;
}
