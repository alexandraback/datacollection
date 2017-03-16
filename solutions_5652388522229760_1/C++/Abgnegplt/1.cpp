#include <iostream>
using namespace std;

int t, n;
int tmp;
bool digit[10];
void clear() 
{
	for (int i = 0; i < 10; ++i)
	{
		digit[i] = 0;
	}
}
bool check(int x)
{
	bool res = 1;

	while(x > 0) {
		digit[x % 10] = 1;
		x /= 10;
	}

	for (int i = 0; i < 10; ++i)
	{
		res &= digit[i];
	}

	return res;
}

int main(int argc, char const *argv[])
{
	
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> n;
		cout << "Case #" << i+1 << ": ";
		if (n == 0)
		{
			cout << "INSOMNIA";
		} else 
		{
			clear();
			tmp = n;
			while(!check(tmp))
			{
				tmp += n;
			}
			cout << tmp;
		}
		cout << endl;
	}

	return 0;
}
