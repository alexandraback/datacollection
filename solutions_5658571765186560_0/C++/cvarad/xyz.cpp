#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	int t, x, r, c;
	scanf("%d", &t);

	for(int i = 1; i <= t; i++)
	{
		scanf("%d%d%d", &x, &r, &c);
		if((r*c)%x)
			cout << "Case #" << i << ": RICHARD\n";
		else if(x > 2 and (r < 2 or c < 2))
			cout << "Case #" << i << ": RICHARD\n";
		else if(x == 4 and (r == 2 or c == 2))
			cout << "Case #" << i << ": RICHARD\n";
		else
			cout << "Case #" << i << ": GABRIEL\n";
	}

	return 0;
}