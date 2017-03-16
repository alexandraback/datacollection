#include <iostream>
#include <fstream>

using namespace std;
int R, C, W;

int emptyLine()
{
	return C / W;
}

int notEmptyLine()
{
	int part1 = C / W - 1 + W;
	if(C % W == 0)
		return part1;
	else
		return (part1 + 1);
}

int main()
{
	int T;
	ifstream istr("in");
	ofstream ostr("out");

	istr >> T;
	for(int times=1;times<=T;times++)
	{
		ostr << "Case #" << times << ": ";
		istr >> R >> C >> W;
		int result = 0;
		result += (emptyLine() * (R - 1));
		result += notEmptyLine();
		ostr << result << endl;
	}
	return 0;
}