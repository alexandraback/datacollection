#include <fstream>
#include <string>
#include <sstream>

using namespace std;

ifstream fin;
ofstream fout;
int T;
int mode = 0;

//data
int R,N,M,K;
int p[7];
int decres[7][3];
int maxorder[4];
int count2[7];

void readdata()
{
	fin >> R >> N >> M >> K;
}

void decompose(int id)
{
	int product = p[id];
	decres[id][0] = 0;
	decres[id][1] = 0;
	decres[id][2] = 0;
	while (product % 2 == 0)
	{
		product /=2;
		decres[id][0]++;
	}
	if (maxorder[0] < decres[id][0])
		maxorder[0] = decres[id][0];
	while (product % 3 == 0)
	{
		product /=3;
		decres[id][1]++;
	}
	if (maxorder[1] < decres[id][1])
		maxorder[1] = decres[id][1];
	while (product % 5 == 0)
	{
		product /=5;
		decres[id][2]++;
	}
	if (maxorder[2] < decres[id][2])
		maxorder[2] = decres[id][2];
	count2[id] = 3 - decres[id][1] - decres[id][2];
	if(maxorder[3] < decres[id][0]-count2[id])
		maxorder[3] = decres[id][0]-count2[id];
}

string solve()
{
	stringstream str;
	str << endl;
	for(int i = 0; i < R; i++)
	{
		maxorder[0] = 0;
		maxorder[1] = 0;
		maxorder[2] = 0;
		maxorder[3] = 0;
		for(int j = 0; j < K ; j++)
		{
			fin >> p[j];
			decompose(j);
		}
		for (int j = 0; j < maxorder[1];j++)
			str << 3;
		for (int j = 0; j < maxorder[2];j++)
			str << 5;
		for (int j = 0; j < maxorder[3];j++)
			str << 4;
		for (int j = 0; j < 3 - maxorder[3]-maxorder[2]-maxorder[1];j++)
			str << 2;
		str << endl;
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
		fin.open("C-small.in");
		fout.open("C-small.txt");
	}
	else
	{
		fin.open("C-large.in");
		fout.open("C-large.txt");
	}
	fin >> T;
	for (int i = 1; i <= T; i++)
		process(i);
	fin.close();
	fout.close();
}