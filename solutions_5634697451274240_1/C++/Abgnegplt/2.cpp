#include <iostream>
#include <cstring>
using namespace std;

int t;
int s;
int ans;
char pancakes[102];
char rep[102];
int length;
int p;

int f(int n, char x)
{
	while(n > 0 && pancakes[n-1] == x)
			n --;
	if (n <= 0)
	{
		return 0;
	} 
	else
	{
		return f(n-1, (x == '+') ? '-' : '+') + 1;
	}
}

int main(int argc, char const *argv[])
{
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> pancakes;
		length = strlen(pancakes);
		cout << "Case #" << i+1 << ": ";

		cout << f(length, '+') << endl;

	}

	return 0;
}