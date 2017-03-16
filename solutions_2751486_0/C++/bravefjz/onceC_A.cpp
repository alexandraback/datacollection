#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <xfunctional>

using namespace std;

ifstream fin;
ofstream fout;
int T;
int mode = 0;

//data
string name;
int n;
int continone;
int endnum;
int nnum;
void readdata()
{
	fin >> name >> n;
}

string solve()
{
	stringstream str;
	int i;
	continone = 0;
	endnum = 0;
	nnum = 0;
	for(i = 0; i < name.length(); i++)
	{
		if (name.at(i) == 'a' || name.at(i) == 'e' || name.at(i) == 'i' || name.at(i) == 'o' || name.at(i) == 'u')
		{
			continone = 0;
			nnum += endnum;
		}
		else
		{
			continone++;
			if (continone >= n)
			{
				endnum = i+2-n; 
				nnum += i+2-n;				
			}
			else
			{
				nnum += endnum;
			}
		}
	}
	str << nnum;
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