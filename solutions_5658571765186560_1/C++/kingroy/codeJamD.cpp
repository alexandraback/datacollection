#include <iostream>
#include <cstdio>

using namespace std;

bool ans(int size, int r, int c)
{
	if ((r * c) % size != 0)
		return true;
	if (size <= 2)
		return false;
	//size >= 3
	int m = r;
	if (c < m)
		m = c;
	if (r * c == size)
		return true;
	if (m == 1) //Single line, choose 2d one
		return true;
	//m >= 2
	if (size == 3)
		return false;
	//size >= 4
	if (m == 2)
		return true;
	if (size >= 7) //Hole
		return true;

	//m >= 3, 6 >= size >= 4
	if (size == 4) //Must be at least 3x4
		return false;
	//m >= 3, 6 >= size >= 5
	if (m == 3)
	{
		if (size == 6)//Plus plus a square
			return true;
		if (r >= 10 || c >= 10)//At least 3x10
			return false;
		return true; //3 x 5
	}
	//size == 6, m >= 4
	return false;
}

int main()
{
	int cases, size, r, c;
	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		cin >> size >> r >> c;
		if (!ans(size, r, c))
			printf("Case #%d: GABRIEL\n", i + 1);
		else
			printf("Case #%d: RICHARD\n", i + 1);
	}
}