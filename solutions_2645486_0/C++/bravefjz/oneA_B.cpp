#include <fstream>
#include <string>
#include <sstream>

using namespace std;

ifstream fin;
ofstream fout;
int T;
int mode = 0;

//data
long long int E,R,N,v[10000],totalgain;

void readdata()
{
	fin >> E >> R >> N;
	for (int i = 0; i < N; i++)
		fin >> v[i];
}

long long int cal_maxgain(long long int x, int num)
{
	long long int maxgain = 0;
	if (num == N)
		return 0;
	for (long long int e = max(x+R-E,(long long int)0); e <= x; e++)
	{
		long long int tmpgain = v[num]*e + cal_maxgain(min(E,x-e+R),num+1);
		if (tmpgain > maxgain)
			maxgain = tmpgain;
	}
	return maxgain;
}

string solve()
{
	stringstream str;
	totalgain = 0;
	if(R >= E)
	{
		for (int i = 0; i < N; i++)
			totalgain += v[i];
		totalgain *= E;
	}
	else
	{
		totalgain = cal_maxgain(E,0);
	}
	str << totalgain;
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
	fin >> T;
	for (int i = 1; i <= T; i++)
		process(i);
	fin.close();
	fout.close();
}