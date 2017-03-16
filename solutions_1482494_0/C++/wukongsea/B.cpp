#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <queue>

using  namespace std;

#define MAX 1010

int N;
int a[MAX];
int b[MAX];
bool r1[MAX];
bool r2[MAX];

struct item
{
	int r;
	int i;
	int v;
};


int solve_single(int case_num);

int main(int argc, char**argv)
{
    if (argc != 2)
	{
             printf("usage:%s input file! \n", argv[0]);
             return 0;
	}
	string line;
	ifstream fin(argv[1]);
	if (fin.fail())
	{
		printf("open file %s error!\n", argv[1]);
	}
	int total_case;
	fin >> total_case;
	for(int i = 0; i < total_case; i++)
	{
		fin >> N;
		for(int j = 0; j < N; j++)
		{
			fin >> a[j] >> b[j];
		}
		solve_single(i+1);
	}

	fin.close();
	return 0;

}

int solve_single(int case_num)
{
	for(int i = 0; i < N; i++)
	{
		r1[i] = false;
		r2[i] = false;
	}
	vector<bool> is;
	is.assign(2*N,true);
	vector<int> star;
	for(int i = 0; i < N; i++)
	{
		star.push_back(a[i]);
		star.push_back(b[i]);
	}
	int cnt = N;
	int sum = 0;
	int t = 0;
	bool flag = false;
	while(true)
	{
		int best = -1;
		int v = -1;
		bool ok = false;
		for(int i = 0; i < star.size(); i++)
		{
			if (is.at(i)  && (i %2) == 1 && star.at(i) <= sum )
			{
				ok = true;
				int gain = 2;
				if (is.at(i-1) == false)
				{
					gain = 1;
				}
				if (gain > v)
				{
					best = i;
					v = gain;
				}
			}
		}
		if (ok)
		{
			is.at(best) = false;
			cnt--;
			if (is.at(best-1))
			{
				sum+=2;
			}
			else
			{
				sum+=1;
			}
			t++;
			if (cnt == 0)
			{
				printf("Case #%d: %d\n",case_num,t);
				return 0;
			}
		}
		else
		{
			best = -1;
			v = -1;
			ok = false;
			for(int i = 0; i < star.size(); i++)
			{
				if (is.at(i)  && (i %2) == 0 && star.at(i) <= sum 
						&& is.at(i+1)==true)
				{
					ok = true;
					best = i;
					break;
				}
			}
			if (ok)
			{
				t++;
				sum+=1;
				is.at(best) = false;
				continue;
			}
			else
			{
				printf("Case #%d: Too bad\n",case_num);
				return 0;
			}

		}
	
	}
	return 0;
}
