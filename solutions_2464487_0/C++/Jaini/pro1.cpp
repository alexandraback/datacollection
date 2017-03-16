#include <iostream>
#include <fstream>

using namespace std;

fstream in, out;
int T; 
long long  r, t, ans;


long long  solve() 
{
	long long psum = 0, sum = 0;
	psum = 1 + (r << 1);
	long long i = 0, j = 0;
	while (t >= sum) 
	{
		sum += (i << 1) + psum; 
		i += 2;
		j++;
	}
	
	return (j-1);
}


int main() 
{
	in.open("in.txt"); out.open("out.txt");
	in >> T;
	for (int i = 1; i <= T ; ++i)
	{
		in >> r >> t;
		out << "Case #" << i << ": " << solve () << endl; 
	}
	

	return 0;
}