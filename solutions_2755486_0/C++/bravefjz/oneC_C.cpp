#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <xfunctional>
#include <list>
#include <iterator>

using namespace std;

ifstream fin;
ofstream fout;
int T;
int mode = 0;
int height[600] = {0};
//data
int N,n[10],d[10],w[10],e[10],s[10],dd[10],dp[10],ds[10];

void readdata()
{
	fin >> N;
	for (int i = 0; i < N; i++)
		fin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> dd[i] >> dp[i] >> ds[i];
}

bool compare(int *a,int *b)
{
	return a[0] < b[0];
}

string solve()
{
	stringstream str;
	memset(height,0,sizeof(height));
	int num = 0;
	list <int*> stats;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < n[i]; j++)
		{
			int *tmp = new int[4];
			tmp[0] = d[i] + j * dd[i];
			tmp[1] = w[i] + j * dp[i];
			tmp[2] = e[i] + j * dp[i];
			tmp[3] = s[i] + j * ds[i];
			stats.push_back(tmp);
		}
	}
	stats.sort(compare);
	list<int*>::iterator itor;
	int lastday = 0;
	list <int*> tmpstats;
	for(itor = stats.begin(); itor != stats.end(); itor++) 
	{
		int *tmp = *itor;
		if (itor == stats.begin() || tmp[0] != lastday)
		{
			lastday = tmp[0];
			if (tmpstats.size() > 0)
			{
				list<int*>::iterator itor1;
				for(itor1 = tmpstats.begin(); itor1 != tmpstats.end(); itor1++)
				{
					int flag = 1;
					int *tmp1 = *itor1;
					for (int k = tmp1[1]; k < tmp1[2] && flag == 1; k++)
					{
						if (height[k+300] < tmp1[3])
							flag = 0;
					}
					if (flag == 0)
						num++;
				}
				for(itor1 = tmpstats.begin(); itor1 != tmpstats.end(); itor1++)
				{
					int *tmp1 = *itor1;
					for (int k = tmp1[1]; k < tmp1[2]; k++)
					{
						if (height[k+300] < tmp1[3])
							height[k+300] = tmp1[3];
					}
				}
			}
			tmpstats.empty();
		}
		tmpstats.push_back(tmp);
	}
	if (tmpstats.size() > 0)
	{
		list<int*>::iterator itor1;
		for(itor1 = tmpstats.begin(); itor1 != tmpstats.end(); itor1++)
		{
			int flag = 1;
			int *tmp1 = *itor1;
			for (int k = tmp1[1]; k < tmp1[2] && flag == 1; k++)
			{
				if (height[k+300] < tmp1[3])
					flag = 0;
			}
			if (flag == 0)
				num++;
		}
	}
	str << num;
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