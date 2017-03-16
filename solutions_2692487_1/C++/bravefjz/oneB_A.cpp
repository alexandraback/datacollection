#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <xfunctional>

using namespace std;

ifstream fin;
ofstream fout;
int T;
int mode = 1;

//data
int N,A;
int sizes[100];

void readdata()
{
	fin >> A >> N;
	int i;
	for (i = 0; i < N; i++)
		fin >> sizes[i];
}

string solve()
{
	stringstream str;
	sort(sizes,sizes+N,less<int>());
	int minimum = N;
	int i;
	int cursize = A;
	int add = 0;
	int sub = N;
	if (cursize > 1)
	{	
		for (i = 0; i < N; i++)
		{
			while(cursize <= sizes[i])
			{
				cursize += cursize-1;
				add++;
			}
			sub--;
			cursize += sizes[i];
			if (add + sub < minimum)
				minimum = add + sub;		
		}
	}
	str << minimum;
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