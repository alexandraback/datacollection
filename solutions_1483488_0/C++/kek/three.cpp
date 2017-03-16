#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;;

int solve(int a, int b);
int recycle(int n, int c, int d);
int main()
{
	std::ifstream f("C-small-attempt0.in");
	std::ofstream o("result3-1.txt");

	int size;
	f >> size;
	for(int i = 0; i < size; i++)
	{
		int a, b;
		f >> a >> b;
		
		int result = solve(a,b);
		std::cout << "Case #" << i+1 << ": " << result << std::endl;
		o << "Case #" << i+1 << ": " << result << std::endl;
	}
	return 0;
}
int solve(int a, int b)
{
	stringstream ss;//create a stringstream
	ss << a;	
	int size = ss.str().size();
	int cnt = 0;
	int p[7] = {10, 100, 1000, 10000, 100000, 1000000, 10000000};
	for(int i = a; i <= b; i++)
	{
		for(int j = 0; j < size - 1; j++)
		{
 			int r = recycle(i, p[j], p[size - 2 - j]);
			if( i < r && r <= b)
				cnt++;
		}
	}
	return cnt;
}

int recycle(int n, int c, int d)
{	
	return (n % c) * d + n / c;
}