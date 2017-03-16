#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin;
ofstream fout;

int T;
int N;
double weight1[1000];
double weight2[1000];

int y,z;

void solve()
{
	y = 0;
	int minidx,maxidx;
	minidx = 0;
	for(int i = 0; i < N; i++)
	{
		if(weight1[i] > weight2[minidx])
		{
			y++;
			minidx++;
		}
	}
	z = 0;
	maxidx = N-1;
	for (int i = N-1; i >= 0; i--)
	{
		if(weight1[i] > weight2[maxidx])
			z++;
		else
			maxidx--;
	}
}

void main()
{
	fin.open("in.txt");
	fout.open("out.txt");
	fin >> T;
	int i,j;
	for (i = 0; i < T; i++)
	{
		fin >> N;
		for(j = 0; j < N; j++)
			fin >> weight1[j];
		for(j = 0; j < N; j++)
			fin >> weight2[j];
		sort(weight1,weight1+N);
		sort(weight2,weight2+N);
		solve();
		fout << "Case #" << i+1 << ": " << y << " " << z << endl;
	}
	fin.close();
	fout.close();
}