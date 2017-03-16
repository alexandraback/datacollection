#include <fstream>
#include <string>
#include <sstream>

using namespace std;

ifstream fin;
ofstream fout;
int T;
int mode = 0;

//data
long long int r,t;
long long int y;

void readdata()
{
	fin >> r >> t;
}

string solve()
{
	stringstream str;
	double dr = double(r);
	double dt = double(t);
	y = 2*t/(sqrt((2*dr-1)*(2*dr-1)+8*dt)+2*dr-1);
	str << y;
	return str.str();
}
//fixed
void process(int id)
{
	readdata();
	string result = solve();
	fout << "Case #" << id << ": " << result << endl;
}

void main()
{
	if(mode == 0)
	{
		fin.open("A-small.in");
		fout.open("A-small.txt");
	}
	else
	{
		fin.open("A-large.in");
		fout.open("A-large.txt");
	}
	fin >> T;
	for (int i = 1; i <= T; i++)
		process(i);
	fin.close();
	fout.close();
}