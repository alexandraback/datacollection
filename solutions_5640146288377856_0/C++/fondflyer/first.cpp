#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream out; ifstream in;
	out.open("output.txt");
	in.open("input.txt");
	int t;
	in >> t;
	for (int i = 0; i < t; ++i)
	{
		int R, C, W, x;
		in >> R >> C >> W;

		x = C/W;
		x *= R;
		if(C%W == 0)
		x += (W-1);
		else
		x += (W);

		out << "Case #" << i+1 << ": " <<  x << endl;
	}
	
}