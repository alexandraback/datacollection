#include <fstream>
#include <string>
#include <sstream>

using namespace std;

ifstream fin;
ofstream fout;
int T;
int mode = 0;

//data
int X,Y,N;

void readdata()
{
	fin >> N >> X >> Y;
}
double store[2000];

string solve()
{
	stringstream str;
	int layer = (abs(X)+Y)/2;
	int required = layer*(2*layer-1);
	int sufficient = (layer+1)*(2*layer+1);
	if (N >= sufficient)
		str << 1.0;
	else if (N <= required)
		str << 0.0;
	else
	{
		int more = N - required;
		int side = 2*layer;
		Y = Y + 1;
		if (Y > more)
			str << 0.0;
		else if (Y == side+1)
			str << 0.0;
		else if(more >= Y + side)
			str << 1.0;
		else if(more <= side)
		{
			str << store[Y-1]-store[more];
		}
		else
		{
			str << store[2*side-more]-store[side-Y];
		}
	}
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
		fin.open("B-small.in");
		fout.open("B-small.txt");
	}
	else
	{
		fin.open("B-large.in");
		fout.open("B-large.txt");
	}
	store[0] = 1;
	for (int i = 1; i < 2000; i++)
		store[i] = store[i-1]/2;
	fin >> T;
	for (int i = 1; i <= T; i++)
		process(i);
	fin.close();
	fout.close();
}